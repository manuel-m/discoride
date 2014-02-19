#include "rstack_proxy.h"

#define R_CPU_OVERHEAD 0.7
#define R_CPU_DELAY 2

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int raudio_decode( rtrack* track, const int channel)
{
  raudio* ad = &(rattr( ad ));
  rchan* chan = &(rattr(chans)[channel]);
  size_t done = 0;
  int channels = 0, encoding = 0;
  int err  = MPG123_OK;
  off_t samples = 0;
  size_t current_buffer_size;
  size_t len_copy;
  size_t i;
  float max_amplitude = 0.0f;
  rcpu cpulimit;
  int count = 0;

  rcpu_init(&cpulimit);

  /* mp3 decode seems to be not thread safe */
  rmutex_stack_lock( mp3_decode_mutex );

  R_ASSERT_ERROR( track  );
  R_ASSERT_ERROR( strlen( track->filename  ) > 0  );
  R_ASSERT_ERROR(  R_AUDIO_CHANNELS > channel  );

  chan->buffer_len = 0;
  chan->sample_rate = 0;
  chan->audio_buffer_offset = 0;
  chan->wavebuffer_offset = 0;

  if (  /* Let mpg123 work with the file, that excludes MPG123_NEED_MORE messages. */
    mpg123_open(ad->mh, track->filename) != MPG123_OK
        /* Peek into track and get first output format. */
    || mpg123_getformat(ad->mh, &(chan->sample_rate), &channels, &encoding) != MPG123_OK ) {
    fprintf( stderr, "Trouble with mpg123: %s\n",
             ad->mh == NULL ? mpg123_plain_strerror(err) : mpg123_strerror(ad->mh) );
    raudio_portaudio_error( );
    return -1;
  }

  if (encoding != MPG123_ENC_SIGNED_16) {       /* Signed 16 is the default output format anyways; it would actually by only different if we forced it.
                                                   So this check is here just for this explanation. */
    raudio_portaudio_error( );
    fprintf(stderr, "Bad encoding: 0x%x!\n", encoding);
    return -2;
  }
  /* Ensure that this output format will not change (it could, when we allow it). */
  mpg123_format_none(ad->mh);

  mpg123_format(ad->mh,
                chan->sample_rate,
                channels,
                encoding);

  /* Buffer could be almost any size here, mpg123_outblock() is just some recommendation.
     Important, especially for sndfile writing, isplay_buffer[play_buffer_len++] = ((short*)buffer)[i]; that the size is a multiple of sample size. */
  current_buffer_size = mpg123_outblock( ad->mh );

  R_ASSERT_ERROR( current_buffer_size <= R_MP3_DECODE_BUFFER);
  memset(ad->mp3decode_buffer, 0, R_MP3_DECODE_BUFFER);
  ad->mp3_decode_buffer_size = current_buffer_size;

  /* [!] needs early to compute progress loading */
  track->sample_rate = chan->sample_rate;


#ifdef DEBUG
  printf("play %g Hz sample %ld Hz buffer_size %d B\n",
         ad->device_rate,
         chan->sample_rate,
         (int)ad->mp3_decode_buffer_size);
#endif

  count = 0;
  do {

    err = mpg123_read( ad->mh,
                       ad->mp3decode_buffer,
                       ad->mp3_decode_buffer_size,
                       &done );
    len_copy = done / sizeof(short);


    /* feed big buffer */
    for ( i = 0; i < len_copy; i++) {
      const S_MIX_HW_SMP_t val = S_MEM_2_SMP((S_MEM_SMP_t)((short*)(ad->mp3decode_buffer))[i]);

      if ( R_ABS(val) > max_amplitude ) {
        max_amplitude = val;
      }

      if ( !(i % 2)  ) {
        chan->left[chan->buffer_len] = val;
      }else {
        chan->right[chan->buffer_len++] = val;
      }
    }

    samples += (off_t)len_copy;

    /* load progress */
    track->samples = samples / channels;
    track->pos = track->samples;

    if ( chan->buffer_len >= ( R_CHAN_BIG_BUFFER / R_AUDIO_CHANNELS ) ) {
      /* quick break => buffer saturation ... at least got the begining */
      err = MPG123_DONE;
    }

    /* We are not in feeder mode, so MPG123_OK, MPG123_ERR and MPG123_NEW_FORMAT are the only possibilities.
       We do not handle a new format, MPG123_DONE is the end... so abort on anything not MPG123_OK. */

    if ( count == 0 ) {
      /* no more R_CPU_OVERHEAD % cpu, if so R_CPU_DELAY ms sleep */
      rcpu_clamp(R_CPU_OVERHEAD, R_CPU_DELAY);
      count = 16384;
    }
    count--;
  } while (err == MPG123_OK);

/* adding one blank frame sample */
  for (i = 0; ( i < R_AUDIO_FRAMES_PER_BUFFER ) && ( chan->buffer_len < ( R_CHAN_BIG_BUFFER / R_AUDIO_CHANNELS ) ); i++  ) {
    if ( !(i % 2)  ) {
      chan->left[chan->buffer_len] = 0;
    }else {
      chan->right[chan->buffer_len++] = 0;
    }
  }

  if (err != MPG123_DONE)
    fprintf( stderr, "Warning: Decoding ended prematurely because: %s\n",
             err == MPG123_ERR ? mpg123_strerror(ad->mh) : mpg123_plain_strerror(err) );

  samples /= channels;


#ifdef DEBUG
  printf("%li samples written.\n", (long)samples);
#endif

  chan->normal_ratio = ((double)(chan->sample_rate)) / ad->device_rate;

/* == [normalise] ============*/
  if ( ( max_amplitude < 0.99f || max_amplitude > 1.0f)  && max_amplitude > 0.0f ) {

    i = 0;
    count = 0;
    do {
      chan->left[i] =  R_CLAMP( (chan->left[i] / max_amplitude), -1.0f, 1.0f );
      chan->right[i] = R_CLAMP( (chan->right[i] / max_amplitude), -1.0f, 1.0f );

      /* no more R_CPU_OVERHEAD % cpu, if so R_CPU_DELAY sleep */
      if ( !count  ) {
        track->pos = i;
        rcpu_clamp(R_CPU_OVERHEAD, R_CPU_DELAY);
        count = 16384;

      }
      count--;
      i++;
    } while (i < chan->buffer_len);
  }

/* == [waveform] ==============*/
  {
    int ii = 0;
    int waveform_offset = 0;
    const int len = chan->buffer_len;
    for (ii = 0; ii < len; ii += R_WAVEFORM_SAMPLING) {
      size_t j;
      S_MIX_HW_SMP_t max = 0.0f;
      S_MIX_HW_SMP_t min = 0.0f;
      for (j = 0; j < R_WAVEFORM_SAMPLING; j++) {
        const S_MIX_HW_SMP_t val_left = chan->left[ii + j];
        const S_MIX_HW_SMP_t val_right = chan->right[ii + j];
        if (val_left > max ) max = val_left;
        if (val_left < min ) min = val_left;
        if (val_right > max ) max = val_right;
        if (val_right < min ) min = val_right;
      }
      chan->waveform_min[waveform_offset] = min;
      chan->waveform_max[waveform_offset] = max;
      track->pos = ii + j;
      waveform_offset++;
    }
  }
  rmutex_stack_unlock( mp3_decode_mutex );

  return 0;
}

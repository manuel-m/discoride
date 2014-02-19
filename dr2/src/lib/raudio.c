#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_display( void )
{
  raudio* ad = &(rattr( ad ));

  PaStreamParameters* opp = &ad->outputParameters;
  const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo( opp->device );

  printf( "[%d][%s][%s] (%gHz %d channels) \n",
          opp->device,
          Pa_GetHostApiInfo( deviceInfo->hostApi )->name,
          deviceInfo->name,
          ad->device_rate,
          opp->channelCount);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_device( const unsigned short wanted_nbChannels,
                    const PaSampleFormat format )
{
  raudio* ad = &(rattr( ad ));
  int i;
  const char* hostApiName;
  int numDevices;
  PaStreamParameters* opp = &ad->outputParameters;
  const PaDeviceInfo *deviceInfo;

  opp->channelCount = wanted_nbChannels;
  opp->sampleFormat = format;
  opp->device = paNoDevice;

  numDevices = Pa_GetDeviceCount();

  /* just info */
  for (i = 0; i < numDevices; i++) {
    deviceInfo = Pa_GetDeviceInfo( i );
    hostApiName = Pa_GetHostApiInfo( deviceInfo->hostApi )->name;
    printf("[%d/%d][%s][%s]\n",
           i, numDevices,
           hostApiName,
           deviceInfo->name);
  }

  /* no device ... */
  if ( numDevices <= 0 ) {
    return;
  }
  /* find Jack ... */
  for (i = 0; (i < numDevices) && ( opp->device == paNoDevice ); i++) {
    deviceInfo = Pa_GetDeviceInfo( i );
    hostApiName = Pa_GetHostApiInfo( deviceInfo->hostApi )->name;

    if ( !strcmp("JACK Audio Connection Kit", hostApiName ) ) {
      opp->device = i;
    }
  }
  /* no jack .. find default */
  if ( opp->device == paNoDevice ) {
    opp->device = Pa_GetDefaultOutputDevice();       /* default output device */
  }
  if ( opp->device == paNoDevice ) {
    opp->device = 0;
  }
  deviceInfo = Pa_GetDeviceInfo( opp->device );
  ad->device_rate = deviceInfo->defaultSampleRate;
  ad->device_ok = 1;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_close( void )
{
  raudio* ad = &(rattr( ad ));

  raudio_stop();

  /* mpg123 */
  {
    /* It's really to late for error checks here;-) */
    mpg123_close(ad->mh);
    mpg123_delete(ad->mh);
    mpg123_exit();
  }
  /* portaudio */
  {
    int i;
    for ( i = 0; i < R_AUDIO_CHANNELS; i++ ) {
      rchan * chan = &(rattr(chans)[i]);
      if (chan->left) {
        free( chan->left );
        chan->left = NULL;
      }

      if (chan->right) {
        free( chan->right );
        chan->right = NULL;
      }
      Pa_Terminate();
    }
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int raudio_portaudio_error( void )
{
  raudio* ad = &(rattr( ad ));

  raudio_close(  );
  if ( ad->paerr ) {
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", ad->paerr );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( ad->paerr ) );
    fprintf( stderr, "Host Error message: %s\n", Pa_GetLastHostErrorInfo()->errorText );
  }
  return ad->paerr;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_init( void )
{
  raudio* ad = &(rattr( ad ));

  R_CLEAR( ad, raudio );

  /* mpg123 */
  {
    int err  = MPG123_OK;
    err = mpg123_init();
    R_ASSERT_ERROR( (err == MPG123_OK) );
    ad->mh = mpg123_new(NULL, &err);
    R_ASSERT_ERROR( (ad->mh) );
    ad->mp3decode_buffer = R_CALLOC( 1, R_MP3_DECODE_BUFFER );
    R_ASSERT_ERROR( (ad->mp3decode_buffer) );

  }
  /* portaudio */
  {
    int i;
    for ( i = 0; i < R_AUDIO_CHANNELS; i++ ) {
      rchan * chan = &(rattr(chans)[i]);
      const size_t bbl = R_CHAN_BIG_BUFFER / R_AUDIO_CHANNELS;
      chan->left = R_CALLOC( bbl, sizeof( S_MIX_HW_SMP_t ) );
      R_ASSERT_ERROR(  chan->left );
      chan->waveform_min = R_CALLOC( bbl /  R_WAVEFORM_SAMPLING, sizeof( float ) );
      R_ASSERT_ERROR(  chan->waveform_min );
      chan->right = R_CALLOC( bbl, sizeof( S_MIX_HW_SMP_t ) );
      R_ASSERT_ERROR( chan->right );
      chan->waveform_max = R_CALLOC( bbl /  R_WAVEFORM_SAMPLING, sizeof( float ) );
      R_ASSERT_ERROR( chan->waveform_max );
    }

    ad->paerr = Pa_Initialize();
    if ( ad->paerr != paNoError ) {
      raudio_portaudio_error( );
    }
    raudio_device( R_AUDIO_CHANNELS, R_AUDIO_MIX_FMT  );
    raudio_display(  );
  }

  if ( !ad->device_ok ) {
    fprintf(stderr, "[ERROR] device ko\n");
    raudio_portaudio_error( );
    exit( 1 );
  }

  /* for taglib to be ok */
  taglib_set_strings_unicode(0);


  raudio_start( );
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_playlist_populate(void)
{
  rlschar255_iterator iter;
  rlschar255* ls = &(rattr( args ));
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  rtrack* track;

  rchar255* filename = rlschar255_first( &iter, ls );

  /* skip args 0 => process name */
  filename = rlschar255_next( &iter );
  while ( filename ) {

    /* filter 1: check filename access */
    track = rtrack_new( filename );

    if ( track ) {
      rlstrack_add( tracks, track );
    }
    filename = rlschar255_next( &iter );
  }

  rplaylist_tag_decode_init();

  R_LOG_INFO("streams decoding finish")
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
/*
 * This routine is called by portaudio when playback is done.
 */
static void StreamFinished( void* userData )
{
  (void)userData;
  printf( "Stream Completed\n");
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_start(void)
{
  raudio* ad = &(rattr( ad ));

  ad->paerr =
    Pa_OpenStream(
      &(ad->stream),
      NULL,         /* no input */
      &(ad->outputParameters),
      ad->device_rate,
      R_AUDIO_FRAMES_PER_BUFFER,
      0,
      raudio_playbuffer_cb,
      ad );

  if ( ad->paerr != paNoError ) raudio_portaudio_error( );

  ad->paerr = Pa_SetStreamFinishedCallback( ad->stream, &StreamFinished );
  if ( ad->paerr != paNoError ) raudio_portaudio_error(  );


  ad->paerr = Pa_StartStream( ad->stream );
  if ( ad->paerr != paNoError ) raudio_portaudio_error( );
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_stop(void)
{
  raudio* ad = &(rattr( ad ));

  ad->paerr = Pa_StopStream( ad->stream );
  if ( ad->paerr != paNoError ) raudio_portaudio_error( );
  ad->paerr = Pa_CloseStream( ad->stream );
  if ( ad->paerr != paNoError ) raudio_portaudio_error( );
}


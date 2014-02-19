#include "rstack_proxy.h"

/*========================================================================
 *
 *========================================================================*/
int raudio_playbuffer_cb( const void *inputBuffer,
                          void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData )
{
  S_MIX_HW_SMP_t *out = (S_MIX_HW_SMP_t*)outputBuffer;
  unsigned long i;
  rchan* chan_0 =  &(rattr(chans)[0]);
  rchan* chan_1 =  &(rattr(chans)[1]);

  /* state */
  const int chan0_play = chan_0->is_playing;
  const int chan1_play = chan_1->is_playing;

  /* volume */
  const double x = rval_get(xfader);

  const double mix0 = 1 - (( x - 1 ) * ( x - 1 ));  /*1-dipped transition*/
  const double mix1 = 1 - (x * x);
  const double g0 = 1 + ((rattr( gain_factor ) - 1) * rval_get(chan0_gain));
  const double g1 = 1 + ((rattr( gain_factor ) - 1) * rval_get(chan1_gain));
  const double volume0 = rval_get(chan0_vol) * g0 * mix0;
  const double volume1 = rval_get(chan1_vol) * g1 * mix1;

  /*printf("xf:%f mx0:%f mx1:%f vol0:%f vol1:%f\n", xfader, mix0, mix1, volume0, volume1);*/

  /* pitch */
  const double pitch0 = (( 2 * rattr( depitch_factor ) * rval_get( chan0_depitch ) ) + 1 - rattr( depitch_factor )) * rval_get( chan0_punch );
  const double pitch1 = (( 2 * rattr( depitch_factor ) * rval_get( chan1_depitch ) ) + 1 - rattr( depitch_factor )) * rval_get( chan1_punch );

  /* offset incr */
  const double offset_incr0 = ( chan_0->normal_ratio * pitch0 );
  const double offset_incr1 = ( chan_1->normal_ratio * pitch1 );

  raudio_meter* peak_meter_main = &rattr( peak_meter_main  );

  (void)timeInfo;    /* Prevent unused variable warnings. */
  (void)statusFlags;
  (void)inputBuffer;
  (void)userData;

  /*raudio_meter_reset_minval( peak_meter_main );*/
  peak_meter_main->peak_left = 0.0;
  peak_meter_main->peak_right = 0.0;

  /******************************************/
  /* chan0, chan1 playing                   */
  /******************************************/
  if ( chan0_play  && chan1_play ) {
    i = framesPerBuffer;
    do {
      /* chan_0 : val = (valmax - valmin) ( x - offset ) + valmin */
      const int offset_0 = (int)( chan_0->audio_buffer_offset );
      const double opt1_0  = chan_0->audio_buffer_offset - (double)(offset_0);

      const double valmax_left_0  = chan_0->left[ offset_0 + 1 ];
      const double valmin_left_0  = chan_0->left[ offset_0 ];
      const double val_left_0
        = ( valmax_left_0 - valmin_left_0 ) * opt1_0 + valmin_left_0;

      const double valmax_right_0  = chan_0->right[ offset_0 + 1 ];
      const double valmin_right_0  = chan_0->right[ offset_0 ];
      const double val_right_0
        = ( valmax_right_0 - valmin_right_0 ) * opt1_0 + valmin_right_0;

      /* chan_1 : val = (valmax - valmin) ( x - offset ) + valmin */
      const int offset_1 = (int)( chan_1->audio_buffer_offset );
      const double opt1_1  = chan_1->audio_buffer_offset - (double)(offset_1);

      const double valmax_left_1  = chan_1->left[ offset_1 + 1 ];
      const double valmin_left_1  = chan_1->left[ offset_1 ];
      const double val_left_1
        = ( valmax_left_1 - valmin_left_1 ) * opt1_1 + valmin_left_1;

      const double valmax_right_1  = chan_1->right[ offset_1 + 1 ];
      const double valmin_right_1  = chan_1->right[ offset_1 ];
      const double val_right_1
        = ( valmax_right_1 - valmin_right_1 ) * opt1_1 + valmin_right_1;

      const S_MIX_HW_SMP_t left_volume_mix = (S_MIX_HW_SMP_t)( (val_left_0 * volume0 ) + (val_left_1 * volume1 ));
      const S_MIX_HW_SMP_t right_volume_mix = (S_MIX_HW_SMP_t)( ( val_right_0 * volume0 )  + (val_right_1 * volume1 ));

      /* mixing */
      *out++ = left_volume_mix;
      *out++ = right_volume_mix;

      /* main vumeter */
      if ( R_ABS( left_volume_mix ) > peak_meter_main->peak_left ) {
        peak_meter_main->peak_left = R_ABS( left_volume_mix );
      }
      if ( R_ABS( right_volume_mix ) > peak_meter_main->peak_right ) {
        peak_meter_main->peak_right = R_ABS( right_volume_mix );
      }

      /* next value */
      chan_0->audio_buffer_offset += offset_incr0;
      chan_1->audio_buffer_offset += offset_incr1;

    } while ( --i );
  }
  /******************************************/
  /* ! chan0, chan1                         */
  /******************************************/
  if ( (!chan0_play ) && chan1_play ) {
    i = framesPerBuffer;
    do {

      /* chan_1 : val = (valmax - valmin) ( x - offset ) + valmin */
      const int offset_1 = (int)( chan_1->audio_buffer_offset );
      const double opt1_1  = chan_1->audio_buffer_offset - (double)(offset_1);

      const double valmax_left_1  = chan_1->left[ offset_1 + 1 ];
      const double valmin_left_1  = chan_1->left[ offset_1 ];
      const double val_left_1
        = ( valmax_left_1 - valmin_left_1 ) * opt1_1 + valmin_left_1;

      const double valmax_right_1  = chan_1->right[ offset_1 + 1 ];
      const double valmin_right_1  = chan_1->right[ offset_1 ];
      const double val_right_1
        = ( valmax_right_1 - valmin_right_1 ) * opt1_1 + valmin_right_1;

      const S_MIX_HW_SMP_t left_volume1 = (S_MIX_HW_SMP_t)(val_left_1 * volume1 );
      const S_MIX_HW_SMP_t right_volume1 = (S_MIX_HW_SMP_t)(val_right_1 * volume1 );

      /* mixing */
      *out++ = left_volume1;
      *out++ = right_volume1;

      /* main vumeter */
      if ( R_ABS( left_volume1 ) > peak_meter_main->peak_left ) {
        peak_meter_main->peak_left = R_ABS( left_volume1 );
      }
      if ( R_ABS( right_volume1 ) > peak_meter_main->peak_right ) {
        peak_meter_main->peak_right = R_ABS( right_volume1 );
      }

      /* next value */
      chan_1->audio_buffer_offset += offset_incr1;

    } while ( --i );

  }

  /******************************************/
  /* chan0, ! chan1                         */
  /******************************************/
  if ( chan0_play  && (!chan1_play) ) {
    i = framesPerBuffer;
    do {

      /* chan_0 : val = (valmax - valmin) ( x - offset ) + valmin */
      const int offset_0 = (int)( chan_0->audio_buffer_offset );
      const double opt1_0  = chan_0->audio_buffer_offset - (double)(offset_0);

      const double valmax_left_0  = chan_0->left[ offset_0 + 1 ];
      const double valmin_left_0  = chan_0->left[ offset_0 ];
      const double val_left_0
        = ( valmax_left_0 - valmin_left_0 ) * opt1_0 + valmin_left_0;

      const double valmax_right_0  = chan_0->right[ offset_0 + 1 ];
      const double valmin_right_0  = chan_0->right[ offset_0 ];
      const double val_right_0
        = ( valmax_right_0 - valmin_right_0 ) * opt1_0 + valmin_right_0;

      const S_MIX_HW_SMP_t left_volume0 = (S_MIX_HW_SMP_t)(val_left_0 * volume0 );
      const S_MIX_HW_SMP_t right_volume0 = (S_MIX_HW_SMP_t)(val_right_0 * volume0 );

      /* mixing */
      *out++ =  left_volume0;
      *out++ = right_volume0;

      /* main vumeter */
      if ( R_ABS( left_volume0 ) > peak_meter_main->peak_left ) {
        peak_meter_main->peak_left = R_ABS( left_volume0 );
      }
      if ( R_ABS( right_volume0 ) > peak_meter_main->peak_right ) {
        peak_meter_main->peak_right = R_ABS( right_volume0 );
      }

      /* next value */
      chan_0->audio_buffer_offset += offset_incr0;

    } while (--i);
  }
/******************************************/
/* ! chan0, ! chan1                       */
/******************************************/
  if ( (!chan0_play)  && (!chan1_play) ) {

    /*
     * may crash in x64
       memset(out, 0, 2 * framesPerBuffer * sizeof(void*) );
     */

    i = framesPerBuffer;
    do {
      *out++ = 0.0;
      *out++ = 0.0;
    } while (--i);


  }
  /* stop when all has been read  */
  {
    if (  chan_0->buffer_len && ( chan_0->audio_buffer_offset >= chan_0->buffer_len ) ) {
      rval_set(rdh_int, chan0_state, R_CHAN_STOP);
      chan_0->is_playing = 0;
    }

    if ( chan_1->buffer_len && ( chan_1->audio_buffer_offset >= chan_1->buffer_len ) ) {
      rval_set(rdh_int, chan1_state, R_CHAN_STOP);
      chan_1->is_playing = 0;
    }
  }

  /* update pos for gui */
  {
    if (chan_0->track) {
      chan_0->track->pos = chan_0->audio_buffer_offset;
    }

    if (chan_1->track) {
      chan_1->track->pos = chan_1->audio_buffer_offset;
    }
  }

  return paContinue;
}

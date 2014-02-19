#include "rstack_proxy.h"

/*========================================================================
 * __f_play_update_gui_state
 *========================================================================*/
static void __f_play_update_gui_state(rdh_int* state, rchan* chan)
{
  if ( chan->is_playing ) {
    if ( chan->is_loading ) {
      rdh_int_set( state, R_CHAN_LOADING_PLAY );
    }else {
      rdh_int_set( state, R_CHAN_PLAY );
    }
  }else {
    if ( chan->is_loading ) {
      rdh_int_set( state, R_CHAN_LOADING_STOP );
    }else {
      rdh_int_set( state, R_CHAN_STOP );
    }
  }
}
/*========================================================================
 * __f_play_fire
 *========================================================================*/
static void __f_play_fire(rdh_int* state, rchan* chan)
{
  chan->is_playing = ( !chan->is_playing ) ? 1 : 0;
  __f_play_update_gui_state( state, chan );
}
/*========================================================================
 * __f_stop_play
 *========================================================================*/
static void __f_stop_play(rdh_int* state, rchan* chan)
{
  chan->is_playing = 0;
  __f_play_update_gui_state( state, chan );
}
/*========================================================================
 * f_play_fire
 *========================================================================*/
void f_play_fire(const int widex)
{
  rdh_int* state = (!widex) ? rdh_addr( chan0_state ) : rdh_addr( chan1_state );

  __f_play_fire( state, &(rattr(chans)[widex]) );
}
/*========================================================================
 * f_play0_fire
 *========================================================================*/
void f_play0_fire(void)
{
  __f_play_fire( rdh_addr( chan0_state ), &(rattr(chans)[0]) );
}
/*========================================================================
 * f_play1_fire
 *========================================================================*/
void f_play1_fire(void)
{
  __f_play_fire( rdh_addr( chan1_state ), &(rattr(chans)[1]) );
}
/*========================================================================
 * raudio_save_depitch_context
 *========================================================================*/
void raudio_save_depitch_context(void)
{
  size_t val;

  for (val = 0; val < 2; val++) {
    rchan * chan = &(rattr(chans)[val]);

    if ( chan->buffer_len && (!chan->is_loading)) {

      const double punch = (val == RDECK_A) ? rval_get( chan0_punch ) : rval_get( chan1_punch );
      const double depitch = (val == RDECK_A) ? rval_get( chan0_depitch ) : rval_get( chan1_depitch );

      const double freq = ( 2 * rattr( depitch_factor )
                            * depitch + 1 - rattr( depitch_factor ))
                          * punch
                          * chan->normal_ratio
                          * S_STREAM_PLAY_RATE;


      const double elapsed = rtimer_delta_sec( &(rtimer_stack_get( current )), &chan->last_action_date);


      /* save last action context */
      rtimer_cpy( &chan->last_action_date, &(rtimer_stack_get( current )));

      if (  chan->is_playing ) {
        chan->wavebuffer_offset += elapsed * freq;
      }
    }
  }
}
/*========================================================================
 * __f_play_label_update(
 *========================================================================*/
static void __f_play_label_update(rchan * chan, rdh_char255 * label)
{
  if ( chan->is_playing ) {
    rdh_char255_strcpy( label, "stop");
  }else {
    rdh_char255_strcpy( label, "play");
  }
}
/*========================================================================
 * f_play0_label_update
 *========================================================================*/
void f_play0_label_update(void* addr)
{
  rchan* chan = &(rattr(chans)[0]);
  rdh_char255 * label = rdh_addr( chan0_play_label );

  (void)addr;

  __f_play_label_update( chan, label );
}
/*========================================================================
 *
 *========================================================================*/
void f_play1_label_update(void* addr)
{
  rchan* chan = &(rattr(chans)[1]);
  rdh_char255 * label = rdh_addr( chan1_play_label );

  (void)addr;

  __f_play_label_update( chan, label );
}
/*========================================================================
 * raudio_chan_load
 *========================================================================*/
void raudio_chan_load( const int widex )
{
  rchan* chan = &(rattr(chans)[widex]);
  rdh_double * pos_norm = (!widex) ? rdh_addr( chan0_pos_norm )  : rdh_addr( chan1_pos_norm );
  rdh_char255* title = (!widex) ? rdh_addr( chan0_track_title )  : rdh_addr( chan1_track_title );
  rtrack* track = rattr( playlist_selected_track );
  rchar255 shorttitle;

  chan->track = track;
  chan->is_loading = 1;
  chan->is_playing = 0;

  /* reset chan gauge */
  rdh_double_set( pos_norm, 0.0 );

  rtrack_short_title( track, &shorttitle);
  rdh_char255_strcpy( title, &shorttitle[0] );

  if ( !widex) {
    rthread_stack_create( raudio_chan0_decode_callback_TS );
  }else {
    rthread_stack_create( raudio_chan1_decode_callback_TS );
  }
}
/*========================================================================
 * f_loading_chan0
 *========================================================================*/
void f_loading_chan0(void)
{
  rtrack* track = rattr(chans)[0].track;
  rchar255 title_time;
  rchar255 shorttitle;
  rchar255 duration;

  if ( !track->sample_rate ) return;

  rtrack_short_title( track, &shorttitle);
  rtrack_pos( track, &duration);

  sprintf(title_time, "%s %s", shorttitle, duration);
  rrstrcpy( rdh_char255, chan0_track_title, &title_time[0] );
}
/*========================================================================
 * f_loading_chan1
 *========================================================================*/
void f_loading_chan1(void)
{
  rtrack* track = rattr(chans)[1].track;
  rchar255 title_time;
  rchar255 shorttitle;
  rchar255 duration;

  if ( !track->sample_rate ) return;

  rtrack_short_title( track, &shorttitle);
  rtrack_pos( track, &duration);

  sprintf(title_time, "%s %s", shorttitle, duration);
  rrstrcpy( rdh_char255, chan1_track_title, &title_time[0] );
}
/*========================================================================
 * f_straffing_chan0
 *========================================================================*/
void f_straffing_chan0(void)
{
  rchan* chan = &(rattr(chans)[0]);

  if ( rattr(chan0_straffway)  ) {

    if (chan->wavebuffer_offset > R_STRAF_SPEED)
      chan->wavebuffer_offset -= R_STRAF_SPEED;
  }else {
    if (chan->wavebuffer_offset < chan->buffer_len)
      chan->wavebuffer_offset += R_STRAF_SPEED;
  }
}
/*========================================================================
 * f_straffing_chan1
 *========================================================================*/
void f_straffing_chan1(void)
{
  rchan* chan = &(rattr(chans)[1]);

  if ( rattr(chan1_straffway)  ) {

    if (chan->wavebuffer_offset > R_STRAF_SPEED)
      chan->wavebuffer_offset -= R_STRAF_SPEED;
  }else {
    if (chan->wavebuffer_offset < chan->buffer_len)
      chan->wavebuffer_offset += R_STRAF_SPEED;
  }
}
/*========================================================================
 * revt_audio_chan0_end_loading
 *========================================================================*/
static void revt_audio_chan0_end_loading(void)
{
  rdh_int* state = rdh_addr( chan0_state );
  rchan* chan = &(rattr(chans)[0]);

  chan->is_loading = 0;
  __f_play_update_gui_state(state, chan);

  rplaylist_tracks_update();
}
/*========================================================================
 * raudio_chan0_decode_callback_TS
 *========================================================================*/
int raudio_chan0_decode_callback_TS(void* param)
{
  rtrack* track = rattr( chans[0].track );

  (void)param;
  raudio_decode( track, 0 );
  rglfw_push_evt( revt_audio_chan0_end_loading );
  return 0;
}
/*========================================================================
 * revt_audio_chan1_end_loading
 *========================================================================*/
static void revt_audio_chan1_end_loading(void)
{
  rdh_int* state = rdh_addr( chan1_state );
  rchan* chan = &(rattr(chans)[1]);

  chan->is_loading = 0;
  __f_play_update_gui_state(state, chan);

  rplaylist_tracks_update();
}
/*========================================================================
 * raudio_chan1_decode_callback_TS
 *========================================================================*/
int raudio_chan1_decode_callback_TS(void* param)
{
  rtrack* track = rattr(chans[1]).track;

  (void)param;
  raudio_decode( track, 1 );
  rglfw_push_evt( revt_audio_chan1_end_loading );
  return 0;
}
/*========================================================================
 * raudio_xfader_right
 *========================================================================*/
void raudio_xfader_right( void )
{
  const double nval = rval_get( xfader ) + rval_get( xfader_step);

  if ( nval >= 1.0   ) {
    rval_set( rdh_double, xfader, 1.0);
  }else {
    rval_set( rdh_double, xfader, nval );
  }
}
/*========================================================================
 * raudio_xfader_left
 *========================================================================*/
void raudio_xfader_left( void )
{
  const double nval = rval_get( xfader ) - rval_get( xfader_step);

  if ( nval <= 0.0   ) {
    rval_set( rdh_double, xfader, 0.0);
  }else {
    rval_set( rdh_double, xfader, nval );
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_xfader_right_auto( const int widex )
{
  (void)widex;
  /*
     if ( rautomation_isactive( rdh_double, xfader ) ) {
     rautomation_stop( rdh_double, xfader );
     }
     rautomation_start( rdh_double, xfader, 1 );
   */
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_xfader_left_auto( const int widex )
{
  (void)widex;
  /*
     if ( rautomation_isactive( rdh_double, xfader ) ) {
     rautomation_stop( rdh_double, xfader );
     }
     rautomation_start( rdh_double, xfader, 0 );
   */
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void raudio_xfader_toggle_auto( const int widex )
{
  (void)widex;
  /*
     if ( rautomation_isactive( rdh_double, xfader ) ) {
     rautomation_stop( rdh_double, xfader );
     }


     if ( rval_get( xfader ) == 0.0) {
     rautomation_start( rdh_double, xfader, 1.0 );
     }else {
     if ( rval_get( xfader ) == 1.0) {
      rautomation_start( rdh_double, xfader, 0.0 );
     }
     }
   */
}
/*========================================================================
 * f_cue_fire_set_on_fly
 *========================================================================*/
static void f_cue_fire_set_on_fly(const int channel)
{
  rwid* wid;
  rchan* chan = &(rattr(chans)[channel]);

  if (channel) {
    wid = rwid_get("dock0_wave");
  }else {
    wid = rwid_get("dock1_wave");
  }

  {
    const double pos =  rchan_pos( chan,
                                   wid->x,
                                   wid->w,
                                   wid->x + ( wid->w * 0.5) );
    chan->track->loop_in = pos;
  }

}
/*========================================================================
 *       f_cue0_fire_set_on_fly
 *========================================================================*/
void f_cue0_fire_set_on_fly_key(void)
{
  f_cue_fire_set_on_fly(0);
}
/*========================================================================
 *       f_cue1_fire_on_fly_key
 *========================================================================*/
void f_cue1_fire_set_on_fly_key(void)
{
  f_cue_fire_set_on_fly(1);
}
/*========================================================================
 * f_cue_fire
 *========================================================================*/
static void f_cue_fire(rchan * chan, rtrack * track)
{
  chan->wavebuffer_offset = track->loop_in;
  chan->audio_buffer_offset = track->loop_in;
}
/*========================================================================
 *       f_cue0_fire_key
 *========================================================================*/
void f_cue0_fire_key(void)
{
  f_cue0_fire(0);
}
void f_cue0_fire(const int val)
{
  (void)val;
  __f_stop_play(rdh_addr( chan0_state ), &(rattr(chans[0])));
  f_cue_fire( &(rattr(chans)[0] ), rattr(chans[0]).track  );
}
/*========================================================================
 *       f_cue1_fire
 *========================================================================*/
void f_cue1_fire_key(void)
{
  f_cue1_fire(1);
}
void f_cue1_fire(const int val)
{
  (void)val;
  __f_stop_play(rdh_addr( chan1_state ), &(rattr(chans[1])));
  f_cue_fire( &(rattr(chans)[1] ), rattr(chans[1]).track );
}



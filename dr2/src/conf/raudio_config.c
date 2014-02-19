#include "rstack_proxy.h"


void raudio_config(void)
{
  rmutex_stack_init( mp3_decode_mutex );

  /*
     rkey_register_down( RKEY_RIGHT, raudio_xfader_left_auto, playlist_state );
     rkey_register_down( RKEY_LEFT, raudio_xfader_right_auto, playlist_state );

     rkey_register_down( RKEY_LEFT, raudio_chan0_load, chan0_can_load );
     rkey_register_down( RKEY_RIGHT, raudio_chan1_load, chan1_can_load );
   */


  rkey_register_down( RKEY_LSHIFT, f_cue0_fire_key, chan0_state );
  rkey_register_down( RKEY_RSHIFT, f_cue1_fire_key, chan1_state );

  rkey_register_down( RKEY_LALT, f_cue0_fire_set_on_fly_key, chan0_state );
  rkey_register_down( RKEY_RALT, f_cue1_fire_set_on_fly_key, chan1_state );




  rkey_register_down( RKEY_LCTRL, f_play0_fire, chan0_state );
  rkey_register_down( RKEY_RCTRL, f_play1_fire, chan1_state );


  /*
     rkey_register_down( RKEY_TAB, raudio_xfader_toggle_auto, chan1_play );
   */


  rdisplay_mainloop_cb_add(&(rattr(chans[0]).is_loading), f_loading_chan0);
  rdisplay_mainloop_cb_add(&(rattr(chans[1]).is_loading), f_loading_chan1);
  rdisplay_mainloop_cb_add(&(rattr(chans[0]).is_playing), f_loading_chan0);
  rdisplay_mainloop_cb_add(&(rattr(chans[1]).is_playing), f_loading_chan1);


  rdisplay_mainloop_cb_add(&rattr(chan0_straffing), f_straffing_chan0);
  rdisplay_mainloop_cb_add(&rattr(chan1_straffing), f_straffing_chan1);


}



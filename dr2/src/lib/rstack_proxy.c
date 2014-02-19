

/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rstack_proxy.h"



void rproxy_init(void)
{

  rattr( mouse_wheel ) = 0;
  rattr( design_height ) = 2000;
  rattr( design_width ) = 2000;
  rattr( video_flags ) = 0;
  rattr( gain_factor ) = 3;
  rattr( depitch_factor ) = 0.15;
  rattr( check_resize ) = 0;
  rattr( resize_flag ) = 0;
  rattr( chan0_straffing ) = 0;
  rattr( chan1_straffing ) = 0;
  rinit( rdh_int, window_mode, RDISPLAY_WINDOW );
  rinit( rdh_char255, window_caption, "discoride - pitch my beach" );
  rinit( rdh_double, global_font_coef, 1.0 );
  rinit( rdh_int, display_state, rnormal );
  rinit( rdh_int, playlist0_state, rdisabled );
  rinit( rdh_int, playlist1_state, rdisabled );
  rinit( rdh_int, playlist2_state, rdisabled );
  rinit( rdh_int, playlist3_state, rdisabled );
  rinit( rdh_int, playlist4_state, rdisabled );
  rinit( rdh_int, playlist5_state, rdisabled );
  rinit( rdh_int, playlist6_state, rdisabled );
  rinit( rdh_int, playlist7_state, rdisabled );
  rinit( rdh_int, playlist_state, 0 );
  rinit( rdh_size, playlist_pos, 0 );
  rinit( rdh_size, playlist_pos_step, 7 );
  rinit( rdh_size, activated_playlist_wid_i, 0 );
  rinit( rdh_int, audio_state, rnormal );
  rinit( rdh_double, xfader, 0.5 );
  rinit( rdh_double, xfader_step, 0.03 );
  rinit( rdh_double, chan0_vol, 1.0 );
  rinit( rdh_double, chan1_vol, 1.0 );
  rinit( rdh_double, chan0_gain, 0.0 );
  rinit( rdh_double, chan1_gain, 0.0 );
  rinit( rdh_double, chan0_depitch, 0.5 );
  rinit( rdh_double, chan1_depitch, 0.5 );
  rinit( rdh_int, chan0_state, rdisabled );
  rinit( rdh_int, chan1_state, rdisabled );
  rinit( rdh_char255, chan0_cue_label, "cue" );
  rinit( rdh_char255, chan1_cue_label, "cue" );
  rinit( rdh_char255, chan0_track_title, " " );
  rinit( rdh_char255, chan1_track_title, " " );
  rinit( rdh_int, chan0_cue_state, 0 );
  rinit( rdh_int, chan1_cue_state, 0 );
  rinit( rdh_double, chan0_pos_norm, 0 );
  rinit( rdh_double, chan1_pos_norm, 0 );
  rinit( rdh_int, chan0_can_load, rdisabled );
  rinit( rdh_int, chan1_can_load, rdisabled );
  rinit( rdh_char255, chan0_play_label, "play" );
  rinit( rdh_char255, chan1_play_label, "play" );
  rinit( rdh_double, main_vumeter_left, 0 );
  rinit( rdh_double, main_vumeter_right, 0 );
  rinit( rdh_double, chan0_vumeter_left, 0 );
  rinit( rdh_double, chan0_vumeter_right, 0 );
  rinit( rdh_double, chan1_vumeter_left, 0 );
  rinit( rdh_double, chan1_vumeter_right, 0 );
  rinit( rdh_char255, deckA_label, "A" );
  rinit( rdh_char255, deckB_label, "B" );
  rinit( rdh_double, chan0_punch, 1.0 );
  rinit( rdh_double, chan1_punch, 1.0 );
  rinit( rdh_double, cpu_user, 0 );
  rmutex_stack_init( mp3_decode_mutex );
  rmutex_stack_init( user_evts_mutex );

}
void rproxy_destroy(void)
{

  rmutex_stack_destroy( mp3_decode_mutex );
  rmutex_stack_destroy( user_evts_mutex );

}


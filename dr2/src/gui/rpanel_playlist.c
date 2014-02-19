#include "rstack_proxy.h"
#include "rpanels.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rpanel_playlist(void)
{

  size_t current_index = 0;

  rframe_new("playlist",
             NULL,
             0.00, 0.60, 0.95, 0.40,
             audio_state,
             NULL,
             0);

  rbutton_label_new("playlist0",
                    "playlist",
                    0.01, 0.88, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist0_state,
                    playlist0_label,
                    "playlist_button_style",
                    NULL_RENDER_SPEC,
                    current_index);


  rbutton_label_new("playlist0_duration",
                    "playlist0",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist0_state,
                    playlist0_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index);

  current_index++;

  rbutton_label_new("playlist1",
                    "playlist",
                    0.01, 0.76, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist1_state,
                    playlist1_label,
                    "playlist_button_style",
                    0,
                    current_index );

  rbutton_label_new("playlist1_duration",
                    "playlist1",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist1_state,
                    playlist1_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index );

  current_index++;

  rbutton_label_new("playlist2",
                    "playlist",
                    0.01, 0.64, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist2_state,
                    playlist2_label,
                    "playlist_button_style",
                    0,
                    current_index );

  rbutton_label_new("playlist2_duration",
                    "playlist2",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist2_state,
                    playlist2_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index  );

  current_index++;

  rbutton_label_new("playlist3",
                    "playlist",
                    0.01, 0.5, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist3_state,
                    playlist3_label,
                    "playlist_button_style",
                    0,
                    current_index );

  rbutton_label_new("playlist3_duration",
                    "playlist3",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist3_state,
                    playlist3_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index );

  current_index++;

  rbutton_label_new("playlist4",
                    "playlist",
                    0.01, 0.38, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist4_state,
                    playlist4_label,
                    "playlist_button_style",
                    0,
                    current_index );

  rbutton_label_new("playlist4_duration",
                    "playlist4",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist4_state,
                    playlist4_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index  );

  current_index++;

  rbutton_label_new("playlist5",
                    "playlist",
                    0.01, 0.26, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist5_state,
                    playlist5_label,
                    "playlist_button_style",
                    0,
                    current_index  );

  rbutton_label_new("playlist5_duration",
                    "playlist5",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist5_state,
                    playlist5_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index  );

  current_index++;

  rbutton_label_new("playlist6",
                    "playlist",
                    0.01, 0.14, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist6_state,
                    playlist6_label,
                    "playlist_button_style",
                    0,
                    current_index );

  rbutton_label_new("playlist6_duration",
                    "playlist6",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist6_state,
                    playlist6_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index );

  current_index++;

  rbutton_label_new("playlist7",
                    "playlist",
                    0.01, 0.02, 0.98, 0.12,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist7_state,
                    playlist7_label,
                    "playlist_button_style",
                    0,
                    current_index  );

  rbutton_label_new("playlist7_duration",
                    "playlist7",
                    0.84, 0.1, 0.15, 0.8,
                    f_playlist_fire_left,
                    f_playlist_fire_right,
                    f_playlist_fire_over_in,
                    f_playlist_fire_over_out,
                    rplaylist_down,
                    rplaylist_up,
                    NULL_FWHEEL_CENTER,
                    playlist7_state,
                    playlist7_duration_label,
                    "playlist_button_duration_style",
                    0,
                    current_index  );

  rplaylist_register_widget( "playlist0", "playlist0_duration");
  rplaylist_register_widget( "playlist1", "playlist1_duration");
  rplaylist_register_widget( "playlist2", "playlist2_duration");
  rplaylist_register_widget( "playlist3", "playlist3_duration");
  rplaylist_register_widget( "playlist4", "playlist4_duration");
  rplaylist_register_widget( "playlist5", "playlist5_duration");
  rplaylist_register_widget( "playlist6", "playlist6_duration");
  rplaylist_register_widget( "playlist7", "playlist7_duration");


}
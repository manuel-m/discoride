#include "rstack_proxy.h"
#include "rpanels.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rpanel_dock1(void)
{
  rframe_new("dock1",
             NULL,
             0.68, 0.0, 0.32, 0.39,
             audio_state,
             NULL,
             0 );

  rjog_new("dock1_jog",
           "dock1",
           0.27, 0.05, 0.5, 0.7,
           f_play_fire,
           f_play_fire,
           NULL, NULL,
           NULL, NULL, NULL,
           chan1_state,
           deckB_label,
           R_DEPITCH,
           "jog_style1",
           R_AUTO_FOCUS,
           RDECK_B);

  rbutton_label_new("dock1_play",
                    "dock1",
                    0.02, 0.05, 0.25, 0.25,
                    f_play_fire,
                    f_play_fire,
                    NULL, NULL,
                    NULL, NULL, NULL,
                    chan1_state,
                    chan1_play_label,
                    "play_button_style1_mini",
                    R_AUTO_FOCUS,
                    RDECK_B );

  rbutton_label_new("dock1_trigger_cue",
                    "dock1",
                    0.02, 0.50, 0.25, 0.25,
                    f_cue1_fire,
                    f_cue1_fire,
                    NULL_FOVER_IN,
                    NULL_FOVER_OUT,
                    NULL_FWHEEL_UP,
                    NULL_FWHEEL_DOWN,
                    NULL_FWHEEL_CENTER,
                    chan1_state,
                    chan1_cue_label,
                    "play_button_style1_mini",
                    R_AUTO_FOCUS,
                    RDECK_B );


  rdeckgauge_new("dock1_track",
                 "dock1",
                 0.05, 0.8, 0.9, 0.15,
                 chan1_state,
                 chan1_pos_norm,
                 R_DENAV,
                 chan1_track_title,
                 "hgauge_style1",
                 NULL_RENDER_SPEC,
                 RDECK_B);



  /*
     rlabel_new("dock0_label",
             "dock0",
             0.014, 0.83, 0.8, 0.17,
             chan0_state,
             chan0_track_title,
             "label_style0",
             0,
             0 );
   */

  rvslider2_new("dock1_depitch",
                "dock1",
                0.83, 0.05, 0.12, 0.7,
                audio_state,
                chan1_depitch,
                NULL, NULL, NULL,
                R_DEPITCH,
                "vslider_style1",
                R_AUTO_FOCUS );


}
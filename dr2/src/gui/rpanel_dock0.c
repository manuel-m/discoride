
#include "rpanels.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rpanel_dock0(void)
{
  rframe_new("dock0",
             NULL,
             0.00, 0.0, 0.33, 0.39,
             audio_state,
             NULL,
             0);

  rjog_new("dock0_jog",
           "dock0",
           0.27, 0.05, 0.5, 0.7,
           f_play_fire,
           f_play_fire,
           NULL_FOVER_IN,
           NULL_FOVER_OUT,
           NULL_FWHEEL_UP,
           NULL_FWHEEL_DOWN,
           NULL_FWHEEL_CENTER,
           chan0_state,
           deckA_label,
           R_DEPITCH,
           "jog_style0",
           R_AUTO_FOCUS,
           RDECK_A);

  rbutton_label_new("dock0_play",
                    "dock0",
                    0.02, 0.05, 0.25, 0.25,
                    f_play_fire,
                    f_play_fire,
                    NULL_FOVER_IN,
                    NULL_FOVER_OUT,
                    NULL_FWHEEL_UP,
                    NULL_FWHEEL_DOWN,
                    NULL_FWHEEL_CENTER,
                    chan0_state,
                    chan0_play_label,
                    "play_button_style0_mini",
                    R_AUTO_FOCUS,
                    RDECK_A  );

  rbutton_label_new("dock0_trigger_cue",
                    "dock0",
                    0.02, 0.50, 0.25, 0.25,
                    f_cue0_fire,
                    f_cue0_fire,
                    NULL_FOVER_IN,
                    NULL_FOVER_OUT,
                    NULL_FWHEEL_UP,
                    NULL_FWHEEL_DOWN,
                    NULL_FWHEEL_CENTER,
                    chan0_state,
                    chan0_cue_label,
                    "play_button_style0_mini",
                    R_AUTO_FOCUS,
                    RDECK_A  );

  rdeckgauge_new("dock0_track",
                 "dock0",
                 0.05, 0.8, 0.9, 0.15,
                 chan0_state,
                 chan0_pos_norm,
                 R_DENAV,
                 chan0_track_title,
                 "hgauge_style0",
                 NULL_RENDER_SPEC,
                 RDECK_A);

  rvslider2_new("dock0_depitch",
                "dock0",
                0.83, 0.05, 0.12, 0.7,
                audio_state,
                chan0_depitch,
                NULL_FWHEEL_UP,
                NULL_FWHEEL_DOWN,
                NULL_FWHEEL_CENTER,
                R_DEPITCH,
                "vslider_style0",
                R_AUTO_FOCUS );


}
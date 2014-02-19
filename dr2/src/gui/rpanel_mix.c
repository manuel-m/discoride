#include "rstack_proxy.h"
#include "rpanels.h"


/* -------------------------------------------------------------------------*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rpanel_mix(void)
{
  rframe_new("dockM",
             NULL,
             0.34, 0.0, 0.32, 0.39,
             audio_state,
             NULL,
             0 );

  rhslider2_new("dockM_xfader",
                "dockM",
                0.20, 0.04,  0.6, 0.18,
                audio_state,
                xfader,
                NULL_FWHEEL_UP,
                NULL_FWHEEL_DOWN,
                NULL_FWHEEL_CENTER,
                R_DEXFADE,
                "hgauge_stylem",
                R_AUTO_FOCUS);


  rvslider2_new("dockM_chan0_gain",
                "dockM",
                0.05, 0.75, 0.12, 0.20,
                audio_state,
                chan0_gain,
                NULL, NULL, NULL,
                R_DEGAIN,
                "vslider_style0",
                R_AUTO_FOCUS  );

  rvslider2_new("dockM_chan0_vol",
                "dockM",
                0.05, 0.04, 0.12, 0.70,
                audio_state,
                chan0_vol,
                NULL, NULL, NULL,
                R_DEVOL,
                "vslider_style0",
                R_AUTO_FOCUS  );

  rvslider2_new("dockM_chan1_gain",
                "dockM",
                0.83, 0.75, 0.12, 0.20,
                audio_state,
                chan1_gain,
                NULL, NULL, NULL,
                R_DEGAIN,
                "vslider_style1",
                R_AUTO_FOCUS  );

  rvslider2_new("dockM_chan1_vol",
                "dockM",
                0.83, 0.04, 0.12, 0.70,
                audio_state,
                chan1_vol,
                NULL, NULL, NULL,
                R_DEVOL,
                "vslider_style1",
                R_AUTO_FOCUS     );


}
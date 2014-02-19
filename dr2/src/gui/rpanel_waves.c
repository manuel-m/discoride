#include "rstack_proxy.h"
#include "rpanels.h"

/*========================================================================
 * include
 *
 *
 *========================================================================*/
void rpanel_waves(void)
{
  rdeckwave4_new("dock0_wave",
                 NULL,
                 0.0, 0.5, 1, 0.1,
                 chan0_state,
                 R_DENAV,
                 "hgauge_style0",
                 NULL_RENDER_SPEC,
                 RDECK_A);

  rdeckwave4_new("dock1_wave",
                 NULL,
                 0.0, 0.4, 1, 0.1,
                 chan1_state,
                 R_DENAV,
                 "hgauge_style1",
                 NULL_RENDER_SPEC,
                 RDECK_B);
}




#include "rstack_proxy.h"
#include "rpanels.h"

/* -------------------------------------------------------------------------*/
/* side nav                                                                 */
/* -------------------------------------------------------------------------*/
void rpanel_sidebar(void)
{
  rframe_new("side_nav",
             NULL,
             0.95, 0.6, 0.05, 0.4,
             audio_state,
             NULL,
             0 );

  rvumeter_new("peak_meter_left",
               "side_nav",
               0.35, 0.1, 0.1, 0.40,
               audio_state,
               main_vumeter_left,
               "vmeter_style",
               NULL_RENDER_SPEC);

  rvumeter_new("peak_meter_right",
               "side_nav",
               0.50, 0.1, 0.1, 0.40,
               audio_state,
               main_vumeter_right,
               "vmeter_style",
               NULL_RENDER_SPEC);


  rcpumeter_new("cpu",
                "side_nav",
                0.3, 0.6, 0.4, 0.30,
                audio_state,
                cpu_user,
                "vmeter_style",
                NULL_RENDER_SPEC);



}

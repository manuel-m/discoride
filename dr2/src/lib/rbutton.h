#ifndef __RBUTTON_H__
#define __RBUTTON_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include "rwid.h"


/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rbutton_label_new( NAME, PARENT_NAME, \
                           X, Y, W, H, \
                           FIRE0, FIRE1, \
                           OVER_IN, OVER_OUT, \
                           WHEEL_UP, WHEEL_DOWN, WHEEL_CENTER, \
                           STATE, \
                           LABEL, \
                           STYLE, \
                           RENDER_SPEC, \
                           WDATA ) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_BUTTON, \
             X, Y, W, H, \
             rbutton_mouse_handler, \
             NULL_FWHEEL_UP_HANDLER, \
             NULL_FWHEEL_DOWN_HANDLER, \
             STYLE, \
             RENDER_SPEC, \
             WDATA, \
             rbutton_label_draw, \
             rbutton_retrigger, \
             FIRE0, \
             FIRE1, \
             OVER_IN, \
             OVER_OUT, \
             WHEEL_UP, \
             WHEEL_DOWN, \
             WHEEL_CENTER, \
             rdh_addr( STATE ), \
             0,  \
             0,  \
             rdh_addr( LABEL ), \
             NULL_STEP, \
             BASIC_TEX )


void rbutton_mouse_handler(rwid* wid, int button_id, int button_state);
void rbutton_label_texrender(rwid* wid);
void rbutton_label_draw(rwid* wid);
void rbutton_retrigger( rwid* wid);
int rbutton_shall_compute_tex( rwid* wid);




#endif /*__RBUTTON_H__*/
#ifndef __RJOG_H__
#define __RJOG_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include "rwid.h"

/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rjog_draw(rwid* wid);
void rjog_mouse_handler(rwid* wid, int button_id, int button_state);
void rjog_texrender(rwid* wid);
void rjog_vertexrender(rwid* wid);
void rjog_bg(rwid* wid);
int rjog_shall_compute_tex(rwid* wid);
int rjog_shall_compute_vertex(rwid* wid);
void rjog_wheel_up(rwid* wid);
void rjog_wheel_down(rwid* wid);
/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rjog_new( NAME, PARENT_NAME, \
                  X, Y, W, H, \
                  FIRE0, FIRE1, \
                  OVER_IN, OVER_OUT, \
                  WHEEL_UP, WHEEL_DOWN, WHEEL_CENTER, \
                  STATE, \
                  LABEL, \
                  STEP, \
                  STYLE, \
                  RENDER_SPEC, \
                  WDATA) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_BUTTON, \
             X, Y, W, H, \
             rjog_mouse_handler, \
             rjog_wheel_up, \
             rjog_wheel_down, \
             STYLE, \
             RENDER_SPEC, \
             WDATA, \
             rjog_draw, \
             rwid_retrigger, \
             FIRE0, \
             FIRE1, \
             OVER_IN, \
             OVER_OUT, \
             WHEEL_UP, \
             WHEEL_DOWN, \
             WHEEL_CENTER, \
             rdh_addr( STATE ), \
             NULL_NORMX,  \
             NULL_NORMY,  \
             rdh_addr( LABEL ), \
             STEP, \
             BASIC_TEX)



#endif /*__RJOG_H__*/
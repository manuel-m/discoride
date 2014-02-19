#ifndef __RDECKWAVE4_H__
#define __RDECKWAVE4_H__

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
#define rdeckwave4_new( NAME, PARENT_NAME, \
                        X, Y, W, H, \
                        STATE, \
                        STEP, \
                        STYLE, \
                        RENDER_SPEC, \
                        WDATA) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_DECKWAVE, \
             X, Y, W, H, \
             rdeckwave4_mouse_handler, \
             rdeckwave4_wheel_up, \
             rdeckwave4_wheel_down, \
             STYLE, \
             RENDER_SPEC, \
             WDATA, \
             rdeckwave4_draw, \
             rwid_retrigger, \
             NULL_FFIRE0, \
             NULL_FFIRE1, \
             NULL_FOVER_IN, \
             NULL_FOVER_OUT, \
             NULL_FWHEEL_UP, \
             NULL_FWHEEL_DOWN, \
             NULL_FWHEEL_CENTER, \
             rdh_addr( STATE ), \
             NULL_NORMX,  \
             NULL_NORMY,  \
             NULL_LABEL, \
             STEP, \
             1, 1, 1); \


/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rdeckwave4_wheel_up(rwid* wid);
void rdeckwave4_wheel_down(rwid* wid);
void rdeckwave4_mouse_handler(rwid* wid, int button_id, int button_state);
void rdeckwave4_vertexrender(rwid * wid);
void rdeckwave4_postfx(rwid * wid);
void rdeckwave4_draw(rwid* wid);


#endif /*__RDECKWAVE4__*/


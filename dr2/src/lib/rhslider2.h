#ifndef __RHSLIDER2_H__
#define __RHSLIDER2_H__

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
void rhslider2_mouse_handler(rwid* wid, int button_id, int button_state);
void rhslider2_texrender(rwid* wid);
void rhslider2_vertexrender(rwid* wid);
void rhslider2_wheel_up(rwid* wid);
void rhslider2_wheel_down(rwid* wid);
int rhslider2_shall_compute_tex( rwid* wid );
int rhslider2_shall_compute_vertex( rwid* wid );
void rhslider2_draw(rwid* wid);

/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rhslider2_new( NAME, PARENT_NAME, \
                       X, Y, W, H, \
                       STATE, \
                       NORMX, \
                       WHEEL_UP, WHEEL_DOWN, WHEEL_CENTER, \
                       STEP, \
                       STYLE, \
                       RENDER_SPEC ) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_VSLIDER, \
             X, Y, W, H, \
             rhslider2_mouse_handler, \
             rhslider2_wheel_up, \
             rhslider2_wheel_down, \
             STYLE, \
             RENDER_SPEC, \
             NULL_WDATA, \
             rhslider2_draw, \
             rwid_retrigger, \
             0, 0, 0, 0, \
             WHEEL_UP, \
             WHEEL_DOWN, \
             WHEEL_CENTER, \
             rdh_addr( STATE ), \
             rdh_addr( NORMX ), \
             NULL_NORMY, \
             0, \
             STEP, \
             BASIC_TEX)


#endif /*__RHSLIDER2_H__*/



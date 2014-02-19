#ifndef __RVSLIDER2_H__
#define __RVSLIDER2_H__

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
void rvslider2_mouse_handler(rwid* wid, int button_id, int button_state);
void rvslider2_texrender(rwid* wid);
void rvslider2_vertexrender(rwid* wid);
void rvslider2_wheel_up(rwid* wid);
void rvslider2_wheel_down(rwid* wid);
int rvslider2_shall_compute_tex( rwid* wid );
int rvslider2_shall_compute_vertex( rwid* wid );
void rvslider2_draw(rwid* wid);

/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rvslider2_new( NAME, PARENT_NAME, \
                       X, Y, W, H, \
                       STATE, \
                       NORMY, \
                       WHEEL_UP, \
                       WHEEL_DOWN, \
                       WHEEL_CENTER, \
                       STEP, \
                       STYLE, \
                       RENDER_SPEC ) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_VSLIDER, \
             X, Y, W, H, \
             rvslider2_mouse_handler, \
             rvslider2_wheel_up, \
             rvslider2_wheel_down, \
             STYLE, \
             RENDER_SPEC, \
             NULL_WDATA, \
             rvslider2_draw, \
             rwid_retrigger, \
             0, 0, 0, 0, \
             WHEEL_UP, \
             WHEEL_DOWN, \
             WHEEL_CENTER, \
             rdh_addr( STATE ), \
             NULL_NORMX,  \
             rdh_addr( NORMY ), \
             0, \
             STEP, \
             BASIC_TEX)


#endif /*__RVSLIDER2_H__*/



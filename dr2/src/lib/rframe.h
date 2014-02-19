#ifndef __RFRAME_H__
#define __RFRAME_H__

/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rwid.h"

/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rframe_new( NAME, PARENT_NAME, \
                    X, Y, W, H, \
                    STATE, STYLE, RENDER_SPEC ) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_FRAME, \
             X, Y, W, H, \
             0, \
             0, 0, \
             STYLE, \
             RENDER_SPEC, \
             NULL_WDATA, \
             rframe_draw, \
             rframe_trigger, \
             0, 0, 0, 0, 0, 0, 0, \
             rdh_addr( STATE ), \
             0,  \
             0,  \
             0,  \
             NULL_STEP, \
             BASIC_TEX)

/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rframe_draw(rwid* wid);
void rframe_trigger( rwid* wid);


#endif /*__RFRAME_H__*/
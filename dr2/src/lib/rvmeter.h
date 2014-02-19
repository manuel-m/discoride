#ifndef __RVMETER_H__
#define __RVMETER_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include "rwid.h"

/*========================================================================
 * rvumeter_new
 *
 *
 *========================================================================*/
#define rvumeter_new( NAME, PARENT_NAME, \
                      X, Y, W, H, \
                      STATE, \
                      NORMY, \
                      STYLE, \
                      RENDER_SPEC) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_VMETER, \
             X, Y, W, H, \
             NULL_FMOUSE_HANDLER, \
             NULL_FWHEEL_UP, \
             NULL_FWHEEL_DOWN, \
             STYLE, \
             RENDER_SPEC, \
             NULL_WDATA, \
             rvmeter_drawvumeter, \
             rwid_retrigger, \
             0, 0, 0, 0, 0, 0, 0, \
             rdh_addr( STATE ), \
             NULL, \
             rdh_addr( NORMY ), \
             0, \
             NULL_STEP, \
             BASIC_TEX)

/*========================================================================
 * rcpumeter_new
 *
 *
 *========================================================================*/
#define rcpumeter_new( NAME, PARENT_NAME, \
                       X, Y, W, H, \
                       STATE, \
                       NORMY, \
                       STYLE, \
                       RENDER_SPEC) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_VMETER, \
             X, Y, W, H, \
             NULL_FMOUSE_HANDLER, \
             NULL_FWHEEL_UP, \
             NULL_FWHEEL_DOWN, \
             STYLE, \
             RENDER_SPEC, \
             NULL_WDATA, \
             rvmeter_drawcpu, \
             rwid_retrigger, \
             0, 0, 0, 0, 0, 0, 0, \
             rdh_addr( STATE ), \
             NULL, \
             rdh_addr( NORMY ), \
             0, \
             NULL_STEP, \
             BASIC_TEX)

/*========================================================================
 * shared functions
 *
 *
 *========================================================================*/
void rvmeter_vertexrender(rwid* wid);

/*========================================================================
 * vumeter
 *
 *
 *========================================================================*/
void rvmeter_drawvumeter(rwid* wid);
int rvmeter_shall_compute_vertex_vumeter(rwid* wid);

/*========================================================================
 * cpu
 *
 *
 *========================================================================*/
void rvmeter_drawcpu(rwid* wid);
int rvmeter_shall_compute_vertex_cpu(rwid* wid);



#endif /*__RVMETER_H__*/


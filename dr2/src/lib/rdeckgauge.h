#ifndef __RDECKGAUGE_H__
#define __RDECKGAUGE_H__

/*========================================================================
 * includes
 *========================================================================*/
#include "rwid.h"

/*========================================================================
 * macros
 *========================================================================*/
#define rdeckgauge_new( NAME, PARENT_NAME, \
                        X, Y, W, H, \
                        STATE, NORMX, STEP, \
                        LABEL, \
                        STYLE, \
                        RENDER_SPEC, \
                        WDATA) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_DECKGAUGE, \
             X, Y, W, H, \
             rdeckgauge_mouse_handler, \
             rdeckgauge_wheel_up, \
             rdeckgauge_wheel_down, \
             STYLE, \
             RENDER_SPEC, \
             WDATA, \
             rdeckgauge_draw, \
             rwid_retrigger, \
             NULL_FFIRE0, \
             NULL_FFIRE1, \
             NULL_FOVER_IN, \
             NULL_FOVER_OUT, \
             NULL_FWHEEL_UP, \
             NULL_FWHEEL_DOWN, \
             NULL_FWHEEL_CENTER, \
             rdh_addr( STATE ), \
             rdh_addr( NORMX ), \
             NULL_NORMY,  \
             rdh_addr( LABEL ), \
             STEP, \
             2, 1, 1)

/*========================================================================
 * functions
 *========================================================================*/
void rdeckgauge_wheel_up(rwid* wid);
void rdeckgauge_wheel_down(rwid* wid);
void rdeckgauge_mouse_handler(rwid* wid, int button_id, int button_state);
int rdeckgauge_shall_compute_vertex(rwid* wid);
int rdeckgauge_shall_compute_tex(rwid* wid);
void rdeckgauge_vertexrender(rwid* wid);
void rdeckgauge_texrender_waveform(rwid* wid);
void rdeckgauge_chan_pos_norm(rwid* wid);
void rdeckgauge_draw(rwid* wid);


#endif /*__RDECKGAUGE_H__*/


#include "rstack_proxy.h"
#include "rvmeter.h"

/*========================================================================
 * rvmeter_drawvumeter
 *
 *
 *========================================================================*/
void rvmeter_drawvumeter(rwid* wid)
{
  /* texture render */
  if ( rattr( resize_flag )  ) {
    rwid_blit_black( wid );
    wid->previousxy_val = 0.0;
  }
  /* vertex render */
  if ( rattr( resize_flag ) || rvmeter_shall_compute_vertex_vumeter(wid) ) {

    rvmeter_vertexrender(wid);

  }
}
/*========================================================================
 * rvmeter_drawcpu
 *
 *
 *========================================================================*/
void rvmeter_drawcpu(rwid* wid)
{
  /* texture render */
  if ( rattr( resize_flag )  ) {
    rwid_blit_black( wid );
    wid->previousxy_val = 0.0;
  }

  /* vertex render */
  if ( rattr( resize_flag ) || rvmeter_shall_compute_vertex_cpu(wid) ) {
    rvmeter_vertexrender(wid);
  }
}
/*========================================================================
 * rvmeter_shall_compute_vertex_vumeter
 *
 *
 *========================================================================*/
int rvmeter_shall_compute_vertex_vumeter(rwid* wid)
{
  (void)wid;
  if ( rval_get(chan0_state) > R_CHAN_STOP || rval_get(chan1_state) > rnormal ) {
    rval_set( rdh_double, main_vumeter_left, rattr(peak_meter_main).peak_left );
    rval_set( rdh_double, main_vumeter_right, rattr(peak_meter_main).peak_right );
    return 1;
  }
  return 0;
}
/*========================================================================
 * rvmeter_shall_compute_vertex_cpu
 *
 *
 *========================================================================*/
int rvmeter_shall_compute_vertex_cpu(rwid* wid)
{
  (void)wid;
  rval_set( rdh_double, cpu_user, rattr(cpu).cpu_user );
  return 1;
}
/*========================================================================
 * rvmeter_vertexrender
 *
 *
 *========================================================================*/
void rvmeter_vertexrender(rwid* wid)
{
  const double Y_VAL = (rwid_normy_get( wid ) < 1 ) ?  rwid_normy_get( wid ) : 1;
  const double x = wid->x;
  const double y = wid->y;
  const double w = wid->w;
  const double h = wid->h;
  const double YG =  h *  Y_VAL;
  const float cred = (float)Y_VAL;
  const float cgreen = 1 - cred;

  glBegin(GL_QUADS);

  if ( Y_VAL < wid->previousxy_val) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x, y + YG);
    glVertex2d(x + w, y + YG);
    glVertex2d(x + w, y + h );
    glVertex2d(x, y + h);
  }else {
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(x, y );
    glVertex2d(x + w, y );
    glColor3f(cred, cgreen, 0.0f);
    glVertex2d(x + w, y + YG );
    glVertex2d(x, y + YG);
  }

  wid->previousxy_val = Y_VAL;
  glEnd();

  glColor3f(1.0f, 1.0f, 1.0f);



}

#include "rstack_proxy.h"
#include "rhslider2.h"
#include "rglfw_cairo.h"

/*========================================================================
 * rhslider2_draw
 *
 *
 *========================================================================*/
void rhslider2_draw(rwid* wid)
{
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );
  const int tex_changed = rhslider2_shall_compute_tex(wid);
  const int vertex_changed = rhslider2_shall_compute_vertex(wid);

  /* texture render */
  if ( rattr( resize_flag ) ||  tex_changed ) {

    rhslider2_texrender( wid );
    rcairogl_texbind( cairogl, wid->w, wid->h );
  }
  /* vertex render */
  if ( rattr( resize_flag ) ||  tex_changed  || vertex_changed ) {

    rcairogl_texblit(cairogl,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h );

    rhslider2_vertexrender(wid);
  }
}
/*========================================================================
 * rhslider2_shall_compute_tex
 *
 *
 *========================================================================*/
int rhslider2_shall_compute_tex( rwid* wid )
{
  R_ASSERT_ERROR( wid )
  if ( rdh_changed( wid->state_dh ) ) return 1;
  return rdh_changed( &wid->focus_dh );
}
/*========================================================================
 * rhslider2_shall_compute_vertex
 *
 *
 *========================================================================*/
int rhslider2_shall_compute_vertex( rwid* wid )
{
  R_ASSERT_ERROR( wid )

  if ( rdh_changed( wid->state_dh )) {
    return 1;
  }
  return rdh_changed( wid->normx_dh );
}
/*========================================================================
 * rhslider2_wheel_up
 *
 *
 *========================================================================*/
void rhslider2_wheel_up(rwid* wid)
{
  const double val = rdh_get(wid->normx_dh);

  if ( val > wid->step ) {
    rdh_double_set( wid->normx_dh, val - wid->step );
  }else {
    rdh_double_set( wid->normx_dh, 0.0 );
  }
}
/*========================================================================
 * rhslider2_wheel_down
 *
 *
 *========================================================================*/
void rhslider2_wheel_down(rwid* wid)
{
  const double val = rdh_get(wid->normx_dh);

  if ( val < (1 - wid->step) ) {
    rdh_double_set( wid->normx_dh, val + wid->step );
  }else {
    rdh_double_set( wid->normx_dh, 1.0 );
  }
}
/*========================================================================
 * rhslider2_texrender
 *
 *
 *========================================================================*/
void rhslider2_texrender(rwid* wid)
{
  rglfw_bg(wid, 0);
}
/*========================================================================
 * rhslider2_vertexrender
 *
 *
 *========================================================================*/
void rhslider2_vertexrender(rwid* wid)
{
  R_ASSERT_ERROR( wid ){

    const double width = wid->w;
    const double height = wid->h;
    const double x = wid->x;
    const double y = wid->y;
    const double slider_h = height * 0.5;

    {
      const rssstyle* sss = rwid_style_get( wid );
      const double radius = sss->active_corner_curvature_radius;
      const double slider_w = sss->active_slider_w_size;
      const double stroke_size_half = ceil( sss->active_stroke_size * 0.5 );

      const double c_x = radius + x + ( ( width - slider_w - 2 * radius)  * ( 1 - rwid_normx_get( wid )) );
      const double c_y = y + (height - slider_h) * 0.5;

      R_ASSERT_ERROR_INFO( sss, wid->name )
      rglColor3( sss->colors[rcolor_fg] );

      /* rule draw */
      {
        const double y_center = y + height * 0.5;
        rglColor3( sss->colors[rcolor_fg] );
        glBegin(GL_QUADS);
        glVertex2d(x + radius, y_center  - stroke_size_half);
        glVertex2d(x + radius,  y_center  + stroke_size_half);
        glVertex2d(x - radius + width,  y_center  + stroke_size_half);
        glVertex2d(x - radius + width,  y_center  - stroke_size_half);
        glEnd();
      }
      /* cursor draw */
      {
        glBegin(GL_QUADS);
        glVertex2d(c_x, c_y);
        glVertex2d(c_x + slider_w, c_y);
        glVertex2d(c_x + slider_w, c_y + slider_h);
        glVertex2d(c_x, c_y + slider_h);
        glEnd();
      }
      /* cursor line */
      {
        const double cl_xx = c_x + ( slider_w * 0.5);
        const double cl_y2 = c_y + slider_h;

        rglColor3( sss->colors[rcolor_in_stroke] );

        glBegin(GL_QUADS);
        glVertex2d(cl_xx - stroke_size_half, c_y );
        glVertex2d(cl_xx + stroke_size_half, c_y );
        glVertex2d(cl_xx + stroke_size_half, cl_y2 );
        glVertex2d(cl_xx - stroke_size_half, cl_y2 );
        glEnd();
      }
    }
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rhslider2_mouse_handler(rwid* wid, int button_id, int button_state)
{
  R_ASSERT_ERROR_INFO( wid->normx_dh, wid->name );

  if ( button_state == GLFW_PRESS ) {

    if ( ( button_id == GLFW_MOUSE_BUTTON_LEFT ) || ( button_id == GLFW_MOUSE_BUTTON_RIGHT )) {
      if ( button_id == GLFW_MOUSE_BUTTON_LEFT ) {
        rdh_double_set( wid->normx_dh, 1.0 );
      } else{
        rdh_double_set( wid->normx_dh, 0.0 );
      }
      R_ASSERT_ERROR_INFO( wid->normx_dh, wid->name );
      return;
    }

    /* wheel center */
    if ( button_id == GLFW_MOUSE_BUTTON_MIDDLE ) {
      if ( wid->f_fire_wheel_center ) {
        wid->f_fire_wheel_center( wid->wdata );
      }else {
        rdh_double_reinit( wid->normx_dh );
      }
    }
  }
}
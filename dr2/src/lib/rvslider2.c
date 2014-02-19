#include "rstack_proxy.h"
#include "rvslider2.h"
#include "rglfw_cairo.h"

/*========================================================================
 * rvslider2_draw
 *
 *
 *========================================================================*/
void rvslider2_draw(rwid* wid)
{
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );
  const int tex_changed = rvslider2_shall_compute_tex(wid);
  const int vertex_changed = rvslider2_shall_compute_vertex(wid);

  /* texture render */
  if ( rattr( resize_flag ) ||  tex_changed ) {
    rvslider2_texrender( wid );
    rcairogl_texbind( cairogl, wid->w, wid->h );
  }
  /* vertex render */
  if ( rattr( resize_flag ) || tex_changed || vertex_changed ) {

    rcairogl_texblit(cairogl,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h );

    rvslider2_vertexrender(wid);
  }
}
/*========================================================================
 * rvslider2_shall_compute_tex
 *
 *
 *========================================================================*/
int rvslider2_shall_compute_tex( rwid* wid )
{
  R_ASSERT_ERROR( wid )
  if ( rdh_changed( wid->state_dh ) ) return 1;
  return rdh_changed( &wid->focus_dh );
}
/*========================================================================
 * rvslider2_shall_compute_vertex
 *
 *
 *========================================================================*/
int rvslider2_shall_compute_vertex( rwid* wid )
{
  R_ASSERT_ERROR( wid )

  if ( rdh_changed( wid->state_dh )) {
    return 1;
  } else
  if ( rdh_changed( wid->normy_dh )) {
    return 1;
  }
  return 0;
}
/*========================================================================
 * rvslider2_wheel_up
 *
 *
 *========================================================================*/
void rvslider2_wheel_up(rwid* wid)
{
  const double val = rdh_get(wid->normy_dh);

  if ( val < (1 - wid->step) ) {
    rdh_double_set( wid->normy_dh, val + wid->step );
  }else {
    rdh_double_set( wid->normy_dh, 1.0 );
  }
}
/*========================================================================
 * rvslider2_wheel_down
 *
 *
 *========================================================================*/
void rvslider2_wheel_down(rwid* wid)
{
  const double val = rdh_get(wid->normy_dh);

  if ( val > wid->step ) {
    rdh_double_set( wid->normy_dh, val - wid->step );
  }else {
    rdh_double_set( wid->normy_dh, 0.0 );
  }
}
/*========================================================================
 * rvslider2_texrender
 *
 *
 *========================================================================*/
void rvslider2_texrender(rwid* wid)
{
  rglfw_bg(wid, 0);
}
/*========================================================================
 * rvslider2_vertexrender
 *
 *
 *========================================================================*/
void rvslider2_vertexrender(rwid* wid)
{
  R_ASSERT_ERROR( wid ){

    const double width = wid->w;
    const double height = wid->h;
    const double x = wid->x;
    const double y = wid->y;
    const double slider_w = width * 0.5;

    {
      const rssstyle* sss = rwid_style_get( wid );
      const double radius = sss->active_corner_curvature_radius;
      const double slider_h = sss->active_slider_h_size;
      const double stroke_size_half = ceil( sss->active_stroke_size * 0.5 );

      const double c_x = wid->x + (width - slider_w) * 0.5;
      const double c_y = radius + wid->y + ( ( height - slider_h - 2 * radius)  * ( rwid_normy_get( wid )) );

      R_ASSERT_ERROR_INFO( sss, wid->name )
      glBegin(GL_QUADS);

      /* rule draw */
      {

        const double x_center = x + width * 0.5;
        rglColor3( sss->colors[rcolor_fg] );
        glVertex2d(x_center - stroke_size_half,  y + radius);
        glVertex2d(x_center + stroke_size_half,  y + radius);
        glVertex2d(x_center + stroke_size_half,  y + height - radius);
        glVertex2d(x_center - stroke_size_half,  y + height - radius);
      }
      /* cursor draw */
      {
        glVertex2d(c_x, c_y);
        glVertex2d(c_x + slider_w, c_y);
        glVertex2d(c_x + slider_w, c_y + slider_h);
        glVertex2d(c_x, c_y + slider_h);
      }
      /* cursor line */
      {
        const double cl_yy =  c_y + (slider_h * 0.5);
        const double cl_x2 = c_x + slider_w;
        rglColor3( sss->colors[rcolor_in_stroke] );
        glVertex2d(c_x, cl_yy - stroke_size_half );
        glVertex2d(c_x, cl_yy + stroke_size_half );
        glVertex2d(cl_x2, cl_yy + stroke_size_half );
        glVertex2d(cl_x2, cl_yy - stroke_size_half );
      }
      glEnd();
    }
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rvslider2_mouse_handler(rwid* wid, int button_id, int button_state)
{
  rssstyle* s;

  R_ASSERT_ERROR_INFO(wid->normy_dh, wid->name )

#ifdef DEBUG
  rwid_style_check( wid );
#endif

  s = rwid_style_get( wid );

  if (  button_state == GLFW_PRESS ) {

    if ( ( button_id == GLFW_MOUSE_BUTTON_LEFT ) || ( button_id == GLFW_MOUSE_BUTTON_RIGHT )) {

      /* normalisation */
      const double y_pushed = (double)rattr(mouse_y);

      const double yy1
        = wid->y
          + s->active_corner_curvature_radius;

      const double yy2
        = wid->y
          + wid->h
          - s->active_corner_curvature_radius;

      if ( y_pushed < yy1 ) {
        rdh_double_set( wid->normy_dh, 0.0 );
      } else {
        if ( y_pushed > yy2 ) {
          rdh_double_set( wid->normy_dh, 1.0 );
        }else{
          if ( (yy2 - yy1) != 0 ) {
            rdh_double_set( wid->normy_dh, ( y_pushed - yy1 ) / ( yy2 - yy1 ) );
          }
        }
      }
#ifdef DEBUG
      printf("[push vslider %s x:%f]\n", wid->name, wid->normy_dh->value);
#endif

      R_ASSERT_ERROR_INFO( wid->normy_dh, wid->name );
      return;
    }

    /* wheel center */
    if ( button_id == GLFW_MOUSE_BUTTON_MIDDLE ) {
      if ( wid->f_fire_wheel_center ) {
        wid->f_fire_wheel_center( wid->wdata );
      }else {
        rdh_double_reinit( wid->normy_dh );
      }
      return;
    }
  }
}

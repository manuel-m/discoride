#include "rstack_proxy.h"
#include "rbutton.h"
#include "rglfw_cairo.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rbutton_mouse_handler(rwid* wid, int button_id, int button_state)
{
  if ( button_state == GLFW_PRESS ) {

    switch ( button_id ) {
    case GLFW_MOUSE_BUTTON_LEFT:
    {
      if ( wid->f_fire_left ) {
        wid->f_fire_left( wid->wdata );
      }
      break;
    }
    case GLFW_MOUSE_BUTTON_RIGHT:
    {
      if ( wid->f_fire_right ) {
        wid->f_fire_right( wid->wdata );
      }
      break;
    }
    case GLFW_MOUSE_BUTTON_MIDDLE:
    {
      if ( wid->f_fire_wheel_center ) {
        wid->f_fire_wheel_center( wid->wdata );
      }
      break;
    }

    default:
    {
      ;
    }
    }
  }
}
/*========================================================================
 * rbutton_label_texrender
 *
 *
 *========================================================================*/
void rbutton_label_texrender(rwid* wid)
{
  rssstyle* sss = rwid_style_get( wid );
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );

  rglfw_bg(wid, 0);

  if ( wid->label_dh && sss->active_font_size ) {
    rglfw_label(wid, cairogl, 1);
  }
}
/*========================================================================
 * rbutton_retrigger
 *
 *
 *========================================================================*/
void rbutton_retrigger( rwid* wid)
{
  R_ASSERT_ERROR( wid )

  if ( wid->state_dh ) {
    if ( rdh_changed( wid->state_dh )) {
      rdh_retrigger( wid->state_dh );
    }
  }
  if ( wid->label_dh ) {
    if ( rdh_changed( wid->label_dh )) {
      rdh_retrigger( wid->label_dh );
    }
  }
  if ( rdh_changed( &wid->focus_dh )) {
    rdh_retrigger( &wid->focus_dh );
  }
}
/*========================================================================
 * rbutton_shall_compute_tex
 *
 *
 *========================================================================*/
int rbutton_shall_compute_tex( rwid* wid)
{
  R_ASSERT_ERROR( wid )

  if ( rdh_changed( wid->state_dh )) {
    return 1;
  }

  if ( wid->label_dh ) {
    if ( rdh_changed( wid->label_dh )) {
      return 1;
    }
  }

  return rdh_changed( &wid->focus_dh );
}
/*========================================================================
 * rbutton_label_draw
 *
 *
 *========================================================================*/
void rbutton_label_draw(rwid* wid)
{
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );

  /* texture render */
  if ( rattr( resize_flag ) || rbutton_shall_compute_tex(wid) ) {

    rbutton_label_texrender( wid );
    rcairogl_texbind( cairogl,
                      wid->w,
                      wid->h );
  }

  /* vertex render */
  if ( rattr( resize_flag) ||  rbutton_shall_compute_tex(wid) ) {

    rcairogl_texblit(cairogl,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h);
  }
}




#include "rstack_proxy.h"
#include "rjog.h"
#include "rdeckgauge.h"
#include "rglfw_cairo.h"

/*========================================================================
 * jog_shall_compute_tex
 *
 *
 *========================================================================*/
int rjog_shall_compute_tex(rwid* wid)
{
  R_ASSERT_ERROR( wid )
  return rdh_changed( wid->state_dh );
}
/*========================================================================
 * jog_shall_compute_vertex
 *
 *
 *========================================================================*/
int rjog_shall_compute_vertex(rwid* wid)
{
  int* straffing = (!wid->wdata) ? &rattr( chan0_straffing ) : &rattr( chan1_straffing );

  return ( rdeckgauge_shall_compute_vertex(wid) || (*straffing)  );
}
/*========================================================================
 * rjog_bg
 *
 *
 *========================================================================*/
void rjog_bg(rwid* wid)
{
  rssstyle* sss = rwid_style_get( wid );
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );
  const int w = wid->w;
  const int h = wid->h;
  const double xc = w * 0.5;
  const double yc = h * 0.5;
  cairo_t* cr = cairogl->cr;
  const double stroke_size = sss->active_stroke_size;
  const double half_stroke_size =  (stroke_size * 0.5);

  /* reset bg with parent widget bg color */
  {
    const rRGB *prgb = rwid_pseudo_alpha_color( wid );
    cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
  }
  cairo_rectangle(cr, 0, 0, w, h );
  cairo_fill(cr);

  /* out circle */
  cairo_arc(cr,
            xc,
            yc,
            R_MIN( xc - half_stroke_size, yc - half_stroke_size  ),
            0,
            MPIx2);

  cairo_close_path(cr);
  cairo_set_source_rgba(cr, 0.0f, 0.0f, 0.0f, 1.0f );

  if ( stroke_size ) {
    cairo_fill_preserve(cr);
    {
      const rRGB *prgb = &sss->colors[rcolor_out_stroke];
      cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
    }
    cairo_set_line_width(cr, stroke_size );
    cairo_stroke(cr);
  }else {
    cairo_fill(cr);
  }

  /* in circle */
  cairo_arc(cr,
            xc,
            yc,
            R_MIN( (xc - half_stroke_size) * 0.45, (yc - half_stroke_size) * 0.45  ),
            0,
            MPIx2);

  cairo_close_path(cr);
  {
    const rRGB *prgb = &sss->colors[rcolor_bg];
    cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
  }

  cairo_fill(cr);
}
/*========================================================================
 * rjog_texrender
 *
 *
 *========================================================================*/
void rjog_mouse_handler(rwid* wid, int button_id, int button_state)
{
  const int chan_state = (!wid->wdata) ? rval_get( chan0_state ) : rval_get( chan1_state );

  /* playing => punch */
  if ( chan_state == R_CHAN_LOADING_PLAY || chan_state == R_CHAN_PLAY ) {
    rdh_double* punch = (!wid->wdata) ? rdh_addr( chan0_punch ) : rdh_addr( chan1_punch );

    if ( button_state == GLFW_PRESS ) {

      switch ( button_id ) {
      case GLFW_MOUSE_BUTTON_LEFT:
      {
        rdh_double_set( punch, 1 - R_PUNCH);
      }
      break;
      case GLFW_MOUSE_BUTTON_RIGHT:
      {
        rdh_double_set( punch, 1 + R_PUNCH );
        break;
      }
      default:
      {
        ;
      }
      }
    }else {
      rdh_double_set( punch, 1);
    }
  }
  /* not playing => straf */
  else{
    /* straffing  */
    int* straffing = (!wid->wdata) ? &rattr( chan0_straffing ) : &rattr( chan1_straffing );
    if ( button_state == GLFW_PRESS ) {
      int* straffway = (!wid->wdata) ? &rattr( chan0_straffway ) : &rattr( chan1_straffway );
      *straffing = 1;

      switch ( button_id ) {
      case GLFW_MOUSE_BUTTON_LEFT:
      {
        *straffway = 1;
      }
      break;
      case GLFW_MOUSE_BUTTON_RIGHT:
      {
        *straffway = 0;
        break;
      }
      default:
      {
        ;
      }
      }
    }else {
      *straffing = 0;
    }
  }
}
/*========================================================================
 * rjog_wheel_up
 *
 *
 *========================================================================*/
void rjog_wheel_up(rwid* wid)
{
  rdh_double* depitch = (!wid->wdata) ? rdh_addr( chan0_depitch ) : rdh_addr( chan1_depitch );
  const double val = rdh_get(depitch);

  if ( val < (1 - wid->step) ) {
    rdh_double_set( depitch, val + wid->step );
  }else {
    rdh_double_set( depitch, 1.0 );
  }
}
/*========================================================================
 * rjog_wheel_down
 *
 *
 *========================================================================*/
void rjog_wheel_down(rwid* wid)
{
  rdh_double* depitch = (!wid->wdata) ? rdh_addr( chan0_depitch ) : rdh_addr( chan1_depitch );
  const double val = rdh_get(depitch);

  if ( val > wid->step ) {
    rdh_double_set( depitch, val - wid->step );
  }else {
    rdh_double_set( depitch, 0.0 );
  }
}
/*========================================================================
 * rjog_draw
 *
 *
 *========================================================================*/
void rjog_draw(rwid* wid)
{
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );

  /* texture render */
  if ( rattr( resize_flag ) ||  rjog_shall_compute_tex(wid) ) {
    rjog_texrender( wid );
    rcairogl_texbind( cairogl, wid->w, wid->h );
  }

  /* vertex render */
  if ( rattr( resize_flag ) || rjog_shall_compute_vertex(wid) ) {

    rcairogl_texblit(cairogl,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h );

    rjog_vertexrender(wid);
  }
}
/*========================================================================
 * rjog_texrender
 *
 *
 *========================================================================*/
void rjog_texrender(rwid* wid)
{
  rssstyle* sss = rwid_style_get( wid );
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );

  rjog_bg(wid);

  if ( sss->active_font_size ) {
    rglfw_label(wid, cairogl, 1.0);
  }
}

/*========================================================================
 * rjog_vertexrender
 *
 *
 *========================================================================*/
#define SECTOR_WIDTH 5.026548246                    /* MPIx2 * 0.8 */
#define SECTOR_WIDTH_PUNCH_UP 8.042477194           /* SECTOR_WIDTH * 1.6 */
#define SECTOR_WIDTH_PUNCH_DOWN 3.141592654         /* SECTOR_WIDTH / 1.6 */
#define MODULO33 80181                              /* 44100 * 60 / 33 */
#define MODULO33_INV 0.000012472
#define MODULO45 58800                              /* 44100 * 60 / 45 */
#define SEGMENTS 65
#define SEGMENTS_INV 0.013333333

void rjog_vertexrender(rwid* wid)
{
  rdh_double* punch = (!wid->wdata) ? rdh_addr( chan0_punch ) : rdh_addr( chan1_punch );
  rssstyle* sss = rwid_style_get( wid );

  rchan * chan = &(rattr(chans)[wid->wdata]);
  const int val = (int)chan->wavebuffer_offset % MODULO33;

  const double teta = MPIx2 - ((MPIx2 * val ) *  MODULO33_INV );
  const double Rmax = (R_MIN( wid->w, wid->h) * 0.5) - 2 * sss->active_stroke_size;
  const double Rmin = Rmax * 0.45;
  const double RmiddleMin = Rmin + 1;
  const double RmiddleMax = Rmax - 1;
  const double Xc = wid->x + wid->w * 0.5;
  const double Yc = wid->y + wid->h * 0.5;
  double sector_width = SECTOR_WIDTH;

  const float r = sss->colors[rcolor_fg].r;
  const float g = sss->colors[rcolor_fg].g;
  const float b = sss->colors[rcolor_fg].b;

  if (  rdh_get( punch  ) > 1 ) {
    sector_width = SECTOR_WIDTH_PUNCH_UP;
  }else if ( rdh_get( punch  )  < 1 ) {
    sector_width = SECTOR_WIDTH_PUNCH_UP;
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  {
    int i;
    const double delta_sector = sector_width * SEGMENTS_INV;
    for (i = 0; i < SEGMENTS; i++) {
      const double psi = teta + ( delta_sector * i );
      const double psi2 = psi + ( delta_sector );
      const double cos_psi = cos( psi );
      const double cos_psi2 = cos( psi2 );
      const double sin_psi = sin( psi );
      const double sin_psi2 = sin( psi2 );
      float alpha_half;

      float alpha = 1 - ((float)i * (float)SEGMENTS_INV);
      alpha *= (alpha);
      alpha_half = alpha * 0.5f;

      /* bottom anti alias */
      glBegin(GL_QUADS);
      glColor4f(r, g, b,  0.0  );
      glVertex2d( Xc + (Rmin * cos_psi ),  Yc + (Rmin * sin_psi ));
      glColor4f(r, g, b,  alpha  );
      glVertex2d( Xc + (RmiddleMin * cos_psi ),  Yc + (RmiddleMin * sin_psi ));
      glVertex2d( Xc + (RmiddleMin * cos_psi2 ),  Yc + (RmiddleMin * sin_psi2));
      glColor4f(r, g, b,  0.0  );
      glVertex2d( Xc + (Rmin * cos_psi2),  Yc + (Rmin * sin_psi2 ));
      glEnd();

      if ( i ) {
        glBegin(GL_QUADS);
        glColor4f(r, g, b,  alpha  );
        glVertex2d( Xc + (RmiddleMin * cos_psi ),  Yc + (RmiddleMin * sin_psi ));
        glVertex2d( Xc + (RmiddleMax * cos_psi ),  Yc + (RmiddleMax * sin_psi ));
        glVertex2d( Xc + (RmiddleMax * cos_psi2 ),  Yc + (RmiddleMax * sin_psi2 ));
        glVertex2d( Xc + (RmiddleMin * cos_psi2 ),  Yc + (RmiddleMin * sin( psi2 )));
        glEnd();
      }else {
        glBegin(GL_QUADS);
        glColor4f(r, g, b,  alpha_half  );
        glVertex2d( Xc + (RmiddleMin * cos_psi ),  Yc + (RmiddleMin * sin_psi));
        glVertex2d( Xc + (RmiddleMax * cos_psi ),  Yc + (RmiddleMax * sin_psi ));
        glColor4f(r, g, b,  alpha   );
        glVertex2d( Xc + (RmiddleMax * cos_psi2 ),  Yc + (RmiddleMax * sin_psi2 ));
        glVertex2d( Xc + (RmiddleMin * cos_psi2 ),  Yc + (RmiddleMin * sin_psi2 ));
        glEnd();
      }

      /* top anti alias */

      glBegin(GL_QUADS);
      glColor4f(r, g, b,  alpha  );
      glVertex2d( Xc + (RmiddleMax * cos_psi ),  Yc + (RmiddleMax * sin_psi ));
      glColor4f(r, g, b,  0.0  );
      glVertex2d( Xc + (Rmax * cos_psi ),  Yc + (Rmax * sin_psi ));
      glVertex2d( Xc + (Rmax * cos_psi2 ),  Yc + (Rmax * sin_psi2 ));
      glColor4f(r, g, b,  alpha  );
      glVertex2d( Xc + (RmiddleMax * cos_psi2 ),  Yc + (RmiddleMax * sin_psi2 ));
      glEnd();


    }
  }
  glDisable(GL_BLEND);

}









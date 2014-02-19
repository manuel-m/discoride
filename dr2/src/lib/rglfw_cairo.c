#include "rglfw_cairo.h"


/*========================================================================
 * rglfw_bg
 *
 *
 *========================================================================*/
void rglfw_bg(rwid* wid, const size_t tex_index)
{
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, tex_index );
  rssstyle* sss = rwid_style_get( wid );
  const int w = wid->w;
  const int h = wid->h;
  const double xc = w * 0.5;
  const double yc = h * 0.5;
  cairo_t* cr = cairogl->cr;
  ruint32 render_flags = sss->render_flags;
  const double stroke_size = sss->active_stroke_size;
  const double radius = sss->active_corner_curvature_radius;
  const double half_stroke_size =  (stroke_size * 0.5);

  /* reset bg with parent widget bg color */
  {
    const rRGB *prgb = rwid_pseudo_alpha_color( wid );
    cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
  }
  cairo_rectangle(cr, 0, 0, w, h );
  cairo_fill(cr);

  /* bg */
  if ( render_flags & R_CIRCLE ) {
    cairo_arc(cr,
              xc,
              yc,
              R_MIN( xc - half_stroke_size, yc - half_stroke_size  ),
              0,
              MPIx2);
  }else {

    const double X0 = radius + half_stroke_size;
    const double Y0 = radius + half_stroke_size;
    const double X1 = w - 1 - radius - half_stroke_size;
    const double Y1 = h - 1 - radius - half_stroke_size;

    cairo_arc(cr, X1, Y0, radius, -90 * DEGREE, 0);
    cairo_arc(cr, X1, Y1, radius, 0, 90 * DEGREE);
    cairo_arc(cr, X0, Y1, radius, 90 * DEGREE, 180 * DEGREE);
    cairo_arc(cr, X0, Y0, radius, 180 * DEGREE, 270 * DEGREE);
  }

  cairo_close_path(cr);
  {
    const rRGB *prgb = &sss->colors[rcolor_bg];
    cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
  }

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
}
/*========================================================================
 * rglfw_label
 *========================================================================*/
void rglfw_label(rwid* wid, rcairogl* cairogl, double coef)
{
  cairo_t* cr = cairogl->cr;
  rssstyle* sss = rwid_style_get( wid );
  double x, y;
  cairo_text_extents_t extents;
  const double stroke_size = sss->active_stroke_size;
  char* label;

  R_ASSERT_ERROR( cairogl )
  R_ASSERT_ERROR_INFO( sss, wid->name )

  label = rwid_label_get(wid);

  /* fg */
  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size(cr, sss->active_font_size );

  cairo_text_extents(cr, label, &extents);

  /* center */
  if ( sss->render_flags & R_CENTER ) {
    x = ( rwid_w( wid ) -  extents.width ) * 0.5 - extents.x_bearing;
    y = ( rwid_h( wid ) -  extents.height ) * 0.5 - extents.y_bearing;
  }else{
    /* left */
    if ( sss->render_flags & R_H_LEFT ) {
      x = -extents.x_bearing + stroke_size + sss->active_corner_curvature_radius;
      y = ( rwid_h( wid ) -  extents.height ) * 0.5 - extents.y_bearing;
    }else{
      /* right */
      x = rwid_w( wid ) -  extents.width - extents.x_bearing - stroke_size;
      y = ( rwid_h( wid ) -  extents.height ) * 0.5 - extents.y_bearing;
    }
  }
  cairo_move_to(cr, x, y );
  cairo_text_path(cr, label );

  /* stroke */
  if ( stroke_size && ( sss->render_flags & R_TXT_STROKE)  ) {
    /* sk */
    {
      const rRGB *prgb = &sss->colors[rcolor_bg];
      cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
    }
    cairo_fill_preserve(cr);
    {
      const rRGB *prgb = &sss->colors[rcolor_out_stroke];
      cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a );
    }
    cairo_set_line_width(cr, stroke_size );
    cairo_stroke(cr);
  }else {
    {
      const rRGB *prgb = &sss->colors[rcolor_fg];
      cairo_set_source_rgba(cr, prgb->r,   prgb->g,  prgb->b,  prgb->a * coef );
    }
    cairo_fill(cr);
  }
}



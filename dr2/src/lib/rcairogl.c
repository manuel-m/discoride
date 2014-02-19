#include "rcairogl.h"

/*========================================================================
 * rlsrcairogl
 *========================================================================*/
RLIST_IMPL( rlsrcairogl, rcairogl )


/*========================================================================
 * rcairogl_new
 *========================================================================*/
rcairogl * rcairogl_new(void){
  return R_CALLOC( 1, sizeof( rcairogl ));
}
/*========================================================================
 * rcairogl_texalloc
 *========================================================================*/
void rcairogl_texalloc( rcairogl * cairogl,
                        const int w,
                        const int h)
{
  R_ASSERT_ERROR( cairogl )

  if ( cairogl->data ) {
    free( cairogl->data );
    cairogl->data = NULL;
    /* [!!!] not free cr_surface => done by cairo */
    cairo_destroy(cairogl->cr);
    cairogl->cr = NULL;
  }

  cairogl->len = (size_t)(RCOLOR_DEPTH * w * h);
  cairogl->data = calloc(cairogl->len,  sizeof(unsigned char));

  cairogl->surface
    = cairo_image_surface_create_for_data(  cairogl->data,
                                            CAIRO_FORMAT_ARGB32,
                                            w,
                                            h,
                                            RCOLOR_DEPTH * w );
  cairogl->cr = cairo_create(cairogl->surface);
}
/*========================================================================
 * rcairogl_hscroll
 *========================================================================*/
void rcairogl_hscroll( rcairogl * cairogl,
                       const int x,
                       const int y,
                       const int w,
                       const int h,
                       const int offset )
{
  glEnable(GL_TEXTURE_RECTANGLE_ARB);

  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, cairogl->tex_id );
  glBegin(GL_QUADS);

  glTexCoord2d(offset, h); glVertex2d(x, y );
  glTexCoord2d(w + offset, h ); glVertex2d(w  + x, y);
  glTexCoord2d(w + offset, 0 ); glVertex2d(w  + x, h + y );
  glTexCoord2d(offset, 0 ); glVertex2d(x, h + y);

  glEnd();

  glDisable(GL_TEXTURE_RECTANGLE_ARB);

}
/*========================================================================
 * rcairogl_warp_hscroll
 *========================================================================*/
void rcairogl_warp_hscroll( rcairogl * cairogl,
                            const int x,
                            const int y,
                            const int w,
                            const int h,
                            const int offset )
{
  glEnable(GL_TEXTURE_RECTANGLE_ARB);

  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, cairogl->tex_id );
  glBegin(GL_QUADS);

  glTexCoord2d(offset, h); glVertex2d(x, y );
  glTexCoord2d(w, h ); glVertex2d(w  + x - offset, y);
  glTexCoord2d(w, 0 ); glVertex2d(w  + x - offset, h + y );
  glTexCoord2d(offset, 0 ); glVertex2d(x, h + y);

  glTexCoord2d(0, h); glVertex2d(x + w - offset, y );
  glTexCoord2d(offset, h ); glVertex2d(x + w, y);
  glTexCoord2d(offset, 0 ); glVertex2d(w  + x, h + y );
  glTexCoord2d(0, 0 ); glVertex2d(x + w - offset, h + y);

  glEnd();

  glDisable(GL_TEXTURE_RECTANGLE_ARB);
}
/*========================================================================
 * rcairogl_blit_black
 *========================================================================*/
void rcairogl_blit_black( rcairogl * cairogl,
                          const int x,
                          const int y,
                          const int w,
                          const int h )
{
  R_ASSERT_ERROR( cairogl )

  glBegin(GL_QUADS);

  glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
  glVertex2d(x, y );
  glVertex2d(x + w, y );
  glVertex2d(x + w, y + h );
  glVertex2d(x, y + h);

  glEnd();
}
/*========================================================================
 * rcairogl_texbind
 *========================================================================*/
void rcairogl_texbind(rcairogl * cairogl,
                      const int w,
                      const int h )
{
  glEnable(GL_TEXTURE_RECTANGLE_ARB);

  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, cairogl->tex_id );

  glTexImage2D(GL_TEXTURE_RECTANGLE_ARB,
               0,
               GL_RGBA,
               w, h,
               0,
               GL_BGRA,
               GL_UNSIGNED_BYTE,
               cairogl->data);

  glDisable(GL_TEXTURE_RECTANGLE_ARB);
}
/*========================================================================
 * rcairogl_texblit
 *========================================================================*/
void rcairogl_texblit(rcairogl * cairogl,
                      const double x,
                      const double y,
                      const double w,
                      const double h )
{
  glEnable(GL_TEXTURE_RECTANGLE_ARB);

  glBindTexture(GL_TEXTURE_RECTANGLE_ARB, cairogl->tex_id );
  glBegin(GL_QUADS);
  glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

  glTexCoord2d(0, h); glVertex2d(x, y );
  glTexCoord2d(w, h); glVertex2d(w  + x, y);
  glTexCoord2d(w, 0); glVertex2d(w  + x, h + y );
  glTexCoord2d(0, 0); glVertex2d(x, h + y);

  glEnd();

  glDisable(GL_TEXTURE_RECTANGLE_ARB);
}
/*========================================================================
 * rwid_texreset
 *
 * [!] to solve remaining alpha effects
 *========================================================================*/
void rcairogl_texreset(rcairogl * cairogl)
{
  R_ASSERT_ERROR( cairogl )
  memset(cairogl->data, 0, cairogl->len * sizeof(unsigned char ));
}


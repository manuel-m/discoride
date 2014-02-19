#ifndef __RCAIROGL_H__
#define __RCAIROGL_H__
/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include <GL/glfw.h>
#include <cairo.h>
#include "rcolor.h"
#include "rstyle.h"
#include "rglu.h"
/*========================================================================
 * struct
 *
 *
 *========================================================================*/
typedef struct _rcairogl {

  cairo_t *cr;
  cairo_surface_t* surface;
  unsigned char* data;
  size_t len;
  GLuint tex_id;

} rcairogl;
/*========================================================================
 * rlsrcairogl
 *========================================================================*/
RLIST_DECL( rlsrcairogl, rcairogl )


/*========================================================================
 * functions
 *========================================================================*/
rcairogl * rcairogl_new(void);

void rcairogl_texalloc( rcairogl * cairogl,
                        const int w,
                        const int h);

void rcairogl_hscroll( rcairogl * cairogl,
                       const int x,
                       const int y,
                       const int w,
                       const int h,
                       const int offset );

void rcairogl_warp_hscroll( rcairogl * cairogl,
                            const int x,
                            const int y,
                            const int w,
                            const int h,
                            const int offset );

void rcairogl_blit_black( rcairogl * cairogl,
                          const int x,
                          const int y,
                          const int w,
                          const int h );

void rcairogl_texbind(rcairogl * cairogl,
                      const int w,
                      const int h );

void rcairogl_texblit(rcairogl * cairogl,
                      const double x,
                      const double y,
                      const double w,
                      const double h );


void rcairogl_texreset(rcairogl * cairogl);


#endif /*__RCAIROGL_H__*/



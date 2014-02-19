#include "rstack_proxy.h"
#include "rframe.h"
#include "rglfw_cairo.h"

/*========================================================================
 * rframe_draw
 *
 *
 *========================================================================*/
void rframe_draw(rwid* wid)
{
  if ( rattr( resize_flag ) ) {

    rcairogl* cairogl = rlsrcairogl_get(&wid->textures, 0 );
    rglfw_bg(wid, 0);

    rcairogl_texbind( cairogl,
                      wid->w,
                      wid->h );

    rcairogl_texblit(cairogl,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h);
  }
}
/*========================================================================
 * rframe_trigger
 *
 *
 *========================================================================*/
void rframe_trigger(rwid* wid)
{
  (void)wid;
}

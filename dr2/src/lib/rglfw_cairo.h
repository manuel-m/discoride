#ifndef __RGLFW_CAIRO_H__
#define __RGLFW_CAIRO_H__


/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include <cairo.h>
#include "rwid.h"

/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rglfw_bg(rwid* wid, const size_t tex_index);
void rglfw_label(rwid* wid, rcairogl* cairogl, double coef);

#endif /* __RGLFW_CAIRO_H__ */

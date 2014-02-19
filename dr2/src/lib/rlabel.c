#include "rstack_proxy.h"
#include "rlabel.h"
#include "rglfw_cairo.h"


/*========================================================================
 * rlabel_texrender
 *
 *
 *========================================================================*/
void rlabel_texrender(rwid* wid, const size_t tex_index)
{
  rglfw_bg(wid, tex_index);
}


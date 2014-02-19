#ifndef __RLABEL_H__
#define __RLABEL_H__

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rwid.h"

void rlabel_texrender(rwid* wid, const size_t tex_index);

#define rlabel_new( NAME, \
                    PARENT_NAME, \
                    X, Y, W, H, \
                    STATE, \
                    LABEL, \
                    STYLE, \
                    RENDER_SPEC, \
                    WDATA ) \
  rwid_new(  NAME, \
             PARENT_NAME, \
             R_W_LABEL, \
             X, Y, W, H, \
             NULL, \
             0, 0, \
             STYLE, \
             RENDER_SPEC, \
             WDATA, \
             NULL_FDRAW_CB, \
             rwid_retrigger, \
             0, 0, 0, 0, 0, 0, 0, \
             rdh_addr( STATE ), \
             0,  \
             0,  \
             rdh_addr( LABEL ), \
             NULL_STEP, \
             BASIC_TEX)


#endif /*__RLABEL_H__*/
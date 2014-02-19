
#include "wid_painter.h"
#include "wid.h"

namespace dr {

    wid_painter::wid_painter(wid* wid_) {
        m_wid = wid_;
    }
    
    wid_painter::~wid_painter(){
        if(m_wid) {
            delete(m_wid);
        }
        
    }

}

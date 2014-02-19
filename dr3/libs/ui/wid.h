

#ifndef WID_H
#define	WID_H

#include <string.h>
#include "defs.h"
#include "color.h"

#define WID_DECK "deck"

namespace dr {

    class wid {
    public:

        wid(const char* type_, float x_, float y_, float w_, float h_, color_t& bg_, 
                uint32_t state_ = 0) {
            x = x_;
            y = y_;
            w = w_;
            h = h_;
            state = state_;
            memcpy(&bg, &bg_, sizeof(color_t));
            type = type_;
        };
        virtual ~wid(){};
        
        float x, y, w, h;
        color_t bg;
        uint32_t state;
        const char* type;
        
        
    protected:
        
        

    private:
        wid(const wid&);
        wid& operator=(const wid&);
    };


}







#endif	/* WID_H */


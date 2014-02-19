/* 
 * File:   deck.h
 * Author: jam
 *
 * Created on 4 août 2013, 23:02
 */

#ifndef DECK_H
#define	DECK_H

#include "wid_painter.h"

namespace dr {

    class deck_glfw : public wid_painter {
    public:
        deck_glfw(wid* wid_);
        virtual ~deck_glfw();
        virtual int drawv(float x_, float y_, float w_, float h_);
        
        
    };

}

#endif	/* DECK_H */


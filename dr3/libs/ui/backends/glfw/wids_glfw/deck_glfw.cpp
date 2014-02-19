/* 
 * File:   deck.cpp
 * Author: jam
 * 
 * Created on 4 août 2013, 23:02
 */

#include <GL/gl.h>
#include "deck_glfw.h"
#include "drtrace.h"
#include "wid.h"

namespace dr {

    deck_glfw::deck_glfw(wid* wid_) : wid_painter(wid_) {
    }

    deck_glfw::~deck_glfw() {
    }

    int deck_glfw::drawv(float x_, float y_, float w_, float h_) {

        glBegin(GL_QUADS);
        glColor3f(m_wid->bg.r, m_wid->bg.g, m_wid->bg.b);
        glVertex2d(x_, y_);
        glVertex2d(x_ + w_, y_);
        glVertex2d(x_ + w_, y_ + h_);
        glVertex2d(x_, y_ + h_);
        glEnd();

        return 0;
    }

}

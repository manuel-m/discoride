/* 
 * File:   ui_glfw.h
 * Author: jam
 *
 * Created on 3 août 2013, 13:53
 */

#ifndef UI_GLFW_H
#define	UI_GLFW_H

#include "ui.h"

class GLFWwindow;

namespace dr {

class ui_glfw : public ui {
public:

    ui_glfw(key_handler& kh_);
    virtual ~ui_glfw();
    
protected:    
    GLFWwindow* m_main_window;
    
    virtual wid_painter* create_painter(wid* wid_);
    virtual int init_backend(void);
    virtual int update_backend(void);
    virtual int open_backend(void);
    virtual int close_backend(void);
    
    
    
private:
  

};

}

#endif	/* UI_GLFW_H */


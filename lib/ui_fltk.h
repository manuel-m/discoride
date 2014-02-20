/* 
 * File:   ui_fltk.h
 * Author: jam
 *
 * Created on 3 août 2013, 13:53
 */

#ifndef UI_FLTK_H
#define	UI_FLTK_H

#include "uv.h"
#include "ui.h"

namespace dr {
    
class ui_window;    

class ui_fltk : public ui {
public:

    ui_fltk(key_handler& kh_);
    virtual ~ui_fltk();
    
protected:    
    ui_window* m_main_window;

    uv_timer_t m_timer;    
    
    virtual wid_painter* create_painter(wid* wid_){(void)wid_;return 0;};
    virtual int init_backend(void);
    virtual int update_backend(void);
    virtual int open_backend(void);
    virtual int close_backend(void);
    
    
    
private:
  

};

}

#endif	/* UI_GLFW_H */


/* 
 * File:   ui_minimal.h
 * Author: jam
 *
 * Created on 3 août 2013, 13:53
 */

#ifndef UI_GLFW_H
#define	UI_GLFW_H

#include "ui.h"

namespace dr {

class ui_minimal : public ui {
public:

    ui_minimal(key_handler& kh_);
    virtual ~ui_minimal();
    
protected:    
    
    virtual wid_painter* create_painter(wid* wid_){ (void)wid_; return NULL;};
    virtual int init_backend(void);
    virtual int update_backend(void);
    virtual int configure(void);
    virtual int open_backend(void);
    virtual int close_backend(void);
    
    
private:
  

};

}

#endif	/* UI_GLFW_H */


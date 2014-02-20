/* 
 * File:   ui.h
 * Author: jam
 *
 * Created on 3 août 2013, 13:26
 */

#ifndef UI_H
#define	UI_H

#include <vector>
#include <stdint.h>
//#include "xtime.h"
#include <time.h>


namespace dr {
    
    class key_handler;
    class wid_painter;
    class wid;
    
    class ui  {
        
    public:
        ui(key_handler& kh_);
        virtual ~ui();
        
        int open();
        int update();
        int close();
        int add_wid(wid* wid_);
        
        inline struct timeval* getCurrentTime(){return &m_current_time;};
        
    protected:
        
        struct timeval m_current_time;
        float m_w;
        float m_h;
        uint32_t m_state;
        key_handler& m_key_handler;
        std::vector<wid_painter*> m_wid_painters;
        
        virtual wid_painter* create_painter(wid* wid_) = 0;
        virtual int init_backend(void) = 0;
        virtual int open_backend(void) = 0;
        virtual int update_backend(void) = 0;
        virtual int close_backend(void) = 0;   
        
        int draw_wids();
        
                
    private:
        
        ui();
        ui(const ui&);
        ui& operator=(const ui&);
 
        int configure();
        
        

    };

}

#endif	/* UI_H */


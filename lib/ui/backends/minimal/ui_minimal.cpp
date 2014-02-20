
#include "wincompat.h"
#include "ui_minimal.h"
#include "defs.h"
#include "drtrace.h"
#include "kh.h"

namespace dr {

    int ui_minimal::open_backend(void) {
        return 0;
    }

    ui_minimal::ui_minimal(key_handler& kh_) : ui(kh_) {
    }

    ui_minimal::~ui_minimal() {
        close();
    }

    int ui_minimal::configure(void) {
        return 0;
    }
    
    int ui_minimal::init_backend(void) {
        return 0;
    }    

    int ui_minimal::update_backend(void) {
        
        int key;
        
        if (kbhit())
        {
            key = getch();
            m_key_handler.trigger_callback(key, 1);
            if(27 == key) return 1; /* ESC */
        }
        return 0;
    }

    int ui_minimal::close_backend(void) {
        return 0;
    }


}

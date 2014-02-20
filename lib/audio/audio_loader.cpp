/* 
 * File:   input.cpp
 * Author: jam
 * 
 * Created on 13 août 2013, 01:39
 */

#include "audio_loader.h"
#include "drtrace.h"
#include "defs.h"

namespace dr {

    audio_loader::audio_loader() {
    }
    int audio_loader::load(const char* filename_,
            audio_buffer_t& audio_buffer_){
        int res = 0;
        if (NULL == filename_) {
            R_ERR("loader:invalid filename");
            return 1;
        }
        audio_buffer_.offset = 0;
        
        R_INFO("loader start: %s", filename_);
        res |= loadv(filename_, audio_buffer_);
        R_INFO("loader end: %s", filename_);
        
        audio_buffer_.state |= DR_LOAD;
                
        
        return res;
    }

}

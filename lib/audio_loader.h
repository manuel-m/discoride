/* 
 * File:   input.h
 * Author: jam
 *
 * Created on 13 août 2013, 01:39
 */

#ifndef LOADER_H
#define	LOADER_H

#include "audio_defs.h"

namespace dr {

    class audio_loader {
    public:
        audio_loader();
        int load(const char*, audio_buffer_t&);
        
    protected:
        virtual int loadv(const char*, audio_buffer_t&)=0;
            
    private:
        audio_loader(const audio_loader&);
        audio_loader &operator=(const audio_loader &);
    };
    
    class audio_loader_dummy : public audio_loader {
    public:
        audio_loader_dummy(){};
        
    protected:
        virtual int loadv(const char* f_, audio_buffer_t& b_){
            (void)f_;
            (void)b_;
            return 0;
        };

    };    

}

#endif	/* LOADER_H */


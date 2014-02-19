/* 
 * File:   loader_mpg123.h
 * Author: jam
 *
 * Created on 14 août 2013, 15:23
 */

#ifndef LOADER_MPG123_H
#define	LOADER_MPG123_H

#include "audio_loader.h"

namespace dr {

    class loader_mpg123 : public audio_loader {
    public:
        loader_mpg123();
        virtual ~loader_mpg123();
        
    protected:
        virtual int loadv(const char*, audio_buffer_t&);
        
    private:

    };
}

#endif	/* LOADER_MPG123_H */


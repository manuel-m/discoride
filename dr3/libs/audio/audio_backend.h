/* 
 * File:   audio.h
 * Author: jam
 *
 * Created on 9 août 2013, 16:16
 */

#ifndef AUDIO_H
#define	AUDIO_H

#include <stdint.h>
#include "audio_defs.h"
#include "drtrace.h"

namespace dr {
    
    class audio_backend {
    public:

        audio_backend();
        virtual ~audio_backend();
        int open(audio_process_callback_t*);
        int close();
        
    protected:

        virtual int openv(audio_process_callback_t*) = 0;
        virtual int closev() = 0;

    private:
        audio_backend(const audio_backend&);
        audio_backend &operator=(const audio_backend &);
    };
    
    class audio_backend_dummy : public audio_backend {
    public:

        audio_backend_dummy();
        virtual ~audio_backend_dummy() {};
        
    protected:

        virtual int openv(audio_process_callback_t*);
        virtual int closev(){return 0; };


    };    



}

#endif	/* AUDIO_H */


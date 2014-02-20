/* 
 * File:   audio_process.h
 * Author: jam
 *
 * Created on 15 août 2013, 19:59
 */

#ifndef AUDIO_PROCESS_H
#define	AUDIO_PROCESS_H

#include "audio_callbacks_c.h"

namespace dr {

    class audio_process {
    public:
        audio_process() {
        };
        virtual audio_process_callback_t* getProcessCallback() = 0;
    private:
        audio_process(const audio_process&);
        audio_process&operator=(const audio_process&);
    };

    class audio_process_dummy : public audio_process {
    public:
        audio_process_dummy() {
        };
        virtual audio_process_callback_t* getProcessCallback() {
            return cb00dummy;
        };
    };

    class audio_process_mix1 : public audio_process {
    public:
        audio_process_mix1() {
        };

        virtual audio_process_callback_t* getProcessCallback() {
            return cb01mix1;
        };
    };

    class audio_process_zero : public audio_process {
    public:
        audio_process_zero() {
        };

        virtual audio_process_callback_t* getProcessCallback() {
            return cb02zero;
        };
    };
    
    class audio_process_sin : public audio_process {
    public:
        audio_process_sin() {
        };

        virtual audio_process_callback_t* getProcessCallback() {
            return cb03sin;
        };
    };    

}

#endif	/* AUDIO_PROCESS_H */


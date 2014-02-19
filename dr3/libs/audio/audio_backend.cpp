/* 
 * File:   audio.cpp
 * Author: jam
 * 
 * Created on 9 août 2013, 16:16
 */

#include "audio_backend.h"
#include "drtrace.h"
#include "audio_proxy.h"
#include "defs.h"
#include "audio_proxy.h"

namespace dr {

    audio_backend::audio_backend() {
    }

    audio_backend::~audio_backend() {
    }

    int audio_backend::open(audio_process_callback_t* process_callback_) {
        int res = openv(process_callback_);
        audio_proxy_get()->backend.state |= DR_OPEN;
        return res;
    }

    int audio_backend::close() {
        int res = 0;
        R_INFO("audio backend request close");

        if (audio_proxy_get()->backend.state & DR_OPEN) {
            res |= closev();
            R_INFO("audio backend closed");
            audio_proxy_get()->backend.state &= ~DR_OPEN;
        } else {
            R_INFO("audio backend already close");
        }
        return res;
    }

    audio_backend_dummy::audio_backend_dummy() {
        R_INFO("using dummy audio backend");
    }

    int audio_backend_dummy::openv(audio_process_callback_t* process_callback_) {
        (void)process_callback_;
        audio_proxy_get()->backend.sample_rate = DR_DEFAULT_BACKEND_SAMPLE_RATE;
        return 0;
    }
}



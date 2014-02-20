/* 
 * File:   audio_rtaudio.h
 * Author: jam
 *
 * Created on 9 août 2013, 16:27
 */

#ifndef AUDIO_RTAUDIO_H
#define	AUDIO_RTAUDIO_H

#include "RtAudio.h"
#include "audio_backend.h"

namespace dr {

    class audio_rtaudio : public audio_backend {
    public:
        audio_rtaudio();
        virtual ~audio_rtaudio();

    protected:
        RtAudio m_dac;
        RtAudio::StreamParameters m_parameters;
        
        virtual int openv(audio_process_callback_t*);
        virtual int closev();

    private:

    };

}

#endif	/* AUDIO_RTAUDIO_H */


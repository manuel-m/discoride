/* 
 * File:   audio_rtaudio.h
 * Author: jam
 *
 * Created on 9 août 2013, 16:27
 */

#ifndef AUDIO_RTAUDIO_H
#define	AUDIO_RTAUDIO_H

#include <cmath>

#include "portaudiocpp/PortAudioCpp.hxx"
#include "drtrace.h"
#include "audio_backend.h"


#ifndef M_PI
#define M_PI  (3.14159265)
#endif

namespace dr {

    class audio_portaudio : public audio_backend {
    public:
        audio_portaudio();
        virtual ~audio_portaudio();

    protected:
        PaStream *m_pstream;
        
        virtual int openv(audio_process_callback_t*);
        virtual int closev();        



    private:

    };

}

#endif	/* AUDIO_RTAUDIO_H */


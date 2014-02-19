/* 
 * File:   audio_rtaudio.cpp
 * Author: jam
 * 
 * Created on 9 août 2013, 16:27
 */
#include "RtAudio.h"
#include "audio_rtaudio.h"
#include "audio_callbacks_c.h"
#include "drtrace.h"
#include "audio_proxy.h"

static int audio_process_1_rtaudio_wrapper(void *outputBuffer_, 
        void *inputBuffer_,
        unsigned int framesPerBuffer_,
        double streamTime_,
        RtAudioStreamStatus status_,
        void *userData_) {
    
    S_MIX_HW_SMP_t *out = (S_MIX_HW_SMP_t*) outputBuffer_;
    audio_process_callback_t* cb = (audio_process_callback_t*)userData_;  
    
    (void) inputBuffer_;
    (void) streamTime_;
    (void) status_;
        
    audio_channel_t* chan0 = &(audio_proxy_get()->channels[0]);
    cb(out, framesPerBuffer_, chan0, 1);
            
    return 0;
}

namespace dr {

    audio_rtaudio::audio_rtaudio() {
        R_INFO("using rtaudio audio backend");
    }

    audio_rtaudio::~audio_rtaudio() {
    }

    int audio_rtaudio::openv(audio_process_callback_t* process_callback_) {

        audio_proxy_t* proxy = audio_proxy_get();
        if (1 > m_dac.getDeviceCount()) {
            R_ERR("No audio device found");
            return 1;
        }
        m_parameters.deviceId = m_dac.getDefaultOutputDevice();
        m_parameters.nChannels = DR_STEREO;
        m_parameters.firstChannel = 0;

        try {
             m_dac.openStream(&m_parameters,
                    NULL,
                    RTAUDIO_FLOAT32,
                    DR_DEFAULT_BACKEND_SAMPLE_RATE,
                    &proxy->backend.buffer_frames,
                    &audio_process_1_rtaudio_wrapper,
                    (void*)process_callback_);
            
            proxy->backend.sample_rate =(double)m_dac.getStreamSampleRate();
           
            R_INFO("audio rtaudio on openstream sample_rate:%ld buffer_frames:%u",
                    (long int)proxy->backend.sample_rate, proxy->backend.buffer_frames);            

            m_dac.startStream();

        } catch (RtError& e) {
            R_ERR("%s : sample_rate %u", e.getMessage().c_str(), 
                    proxy->backend.sample_rate);
            return 1;
        }

        R_INFO("audio OK");
        return 0;
    }

    int audio_rtaudio::closev() {

        int res = 0;
        try {
            // Stop the stream
            m_dac.stopStream();
        } catch (RtError& e) {
            R_ERR("%s", e.getMessage().c_str());
            res = 1;
        }
        if (m_dac.isStreamOpen()) m_dac.closeStream();
        return res;
    }


}


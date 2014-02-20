
#include "audio_portaudio.h"
#include "audio_callbacks_c.h"
#include "drtrace.h"
#include "audio_proxy.h"
#include "defs.h"

namespace dr {

 static  int audio_process_1_portaudio_wrapper(const void *inputBuffer_,
        void *outputBuffer_,
        unsigned long framesPerBuffer_,
        const PaStreamCallbackTimeInfo* timeInfo_,
        PaStreamCallbackFlags statusFlags_,
        void *userData_) {

    S_MIX_HW_SMP_t *out = (S_MIX_HW_SMP_t*) outputBuffer_;
    audio_process_callback_t* cb = (audio_process_callback_t*)userData_;  

    (void) timeInfo_;
    (void) statusFlags_;
    (void) inputBuffer_;

    audio_channel_t* chan0 = &(audio_proxy_get()->channels[0]);

    cb(out, framesPerBuffer_, chan0, 1);
    return paContinue;
}

    /*
     * This routine is called by portaudio when playback is done.
     */
    static void audio_stream_finished(void* userData) {
        (void) userData;
    }

    audio_portaudio::audio_portaudio() {
        
        R_INFO("using portaudio audio backend");
        m_pstream = NULL;



    }

    audio_portaudio::~audio_portaudio() {
    }

    int audio_portaudio::openv(audio_process_callback_t* process_callback_) {

        PaError err = Pa_Initialize();
        PaStreamParameters outParams;
        const PaDeviceInfo *deviceInfo;
        
        audio_proxy_t* proxy = audio_proxy_get();

        if (paNoError != err) {
            R_ERR("portaudio init failed");
            goto error;
        }


        outParams.device = Pa_GetDefaultOutputDevice(); /* default output device */
        if (paNoDevice == outParams.device) {
            R_ERR("No default audio output device");
            goto error;
        }

        outParams.channelCount = DR_STEREO;
        outParams.sampleFormat = DR_AUDIO_MIX_FMT; /* 32 bit floating point output */
        outParams.suggestedLatency = Pa_GetDeviceInfo(outParams.device)->defaultLowOutputLatency;
        outParams.hostApiSpecificStreamInfo = NULL;

        deviceInfo = Pa_GetDeviceInfo(outParams.device);
        proxy->backend.sample_rate = deviceInfo->defaultSampleRate;

        err = Pa_OpenStream(
                &m_pstream,
                NULL, /* no input */
                &outParams,
                proxy->backend.sample_rate,
                proxy->backend.buffer_frames,
                paClipOff, /* we won't output out of range samples so don't bother clipping them */
                /*audio_process_test,*/
                audio_process_1_portaudio_wrapper,
                (void*)process_callback_);
        if (err != paNoError) {
            R_ERR("audio portaudio on openstream sample_rate:%ld buffer_frames:%u",
                    (long int)proxy->backend.sample_rate, proxy->backend.buffer_frames);
            goto error;
        } else {
            R_INFO("audio portaudio on openstream sample_rate:%ld buffer_frames:%u",
                    (long int)proxy->backend.sample_rate, proxy->backend.buffer_frames);
        }

        err = Pa_SetStreamFinishedCallback(m_pstream, &audio_stream_finished);
        if (err != paNoError) goto error;

        err = Pa_StartStream(m_pstream);
        if (err != paNoError) goto error;

        return 0;

error:
        return 1;
    }

    int audio_portaudio::closev() {

        PaError err = Pa_StopStream(m_pstream);
        if (err != paNoError) {
            R_ERR("portaudio stop stream");
            goto end;
        } else {
            R_INFO("portaudio stop stream");
        }

        err = Pa_CloseStream(m_pstream);
        if (err != paNoError) {
            R_ERR("portaudio close stream");
            goto end;
        } else {
            R_INFO("portaudio close stream");
        }

end:
        Pa_Terminate();
        return (paNoError != err);
    }
}


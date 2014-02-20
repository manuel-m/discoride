/* 
 * File:   audio_proxy.h
 * Author: jam
 *
 * Created on 13 août 2013, 17:32
 */

#ifndef AUDIO_PROXY_H
#define	AUDIO_PROXY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "audio_defs.h"    

    typedef struct audio_backend_t_ {
        double sample_rate;
        unsigned int buffer_frames;
        uint32_t state;
    } audio_backend_t;

    typedef struct audio_proxy_t_ {
        uint32_t state;
        audio_backend_t backend;
        size_t nb_channels;
        audio_channel_t* channels;
    } audio_proxy_t;


    int audio_proxy_init(size_t nb_channels_);
    int audio_proxy_close();
    
    int audio_play(size_t,int);
    int audio_play_toggle(size_t);
    int audio_reverse_toggle(size_t);
    
    int audio_mute(size_t,int);
    int audio_mute_toggle(size_t);
    
    int audio_depitch(size_t,int);
    int audio_pitch_reset(size_t channel_index_);
    int audio_volume(size_t,int);
    
    int audio_nav(size_t, int);
    
    audio_proxy_t* audio_proxy_get();

    

#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_PROXY_H */


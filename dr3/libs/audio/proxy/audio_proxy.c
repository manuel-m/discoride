#include <string.h>
#include <stdlib.h>
#include "audio_proxy.h"
#include "drtrace.h"
#include "defs.h"

audio_proxy_t audio_proxy = {0};

audio_proxy_t* audio_proxy_get(){
    return &audio_proxy;
}

int audio_play(size_t channel_index_, int play_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("channel:%d ", (int)channel_index_);
        return 1;
    }
    if(play_){
        audio_proxy.channels[channel_index_].state |= DR_ENABLE;
    }else
    {
        audio_proxy.channels[channel_index_].state &= ~DR_ENABLE;
    }
    return 0;
}

int audio_play_toggle(size_t channel_index_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("invalid channel:%d", (int)channel_index_);
        return 1;
    }
    audio_proxy.channels[channel_index_].state ^= DR_ENABLE;
    return 0;
}

int audio_reverse_toggle(size_t channel_index_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("invalid channel:%d", (int)channel_index_);
        return 1;
    }
    audio_proxy.channels[channel_index_].state ^= DR_REVERSE ;
    return 0;
}

int audio_mute(size_t channel_index_, int mute_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("channel:%d ", (int)channel_index_);
        return 1;
    }
    if(mute_){
        audio_proxy.channels[channel_index_].state |= DR_BYPASS;
    }else
    {
        audio_proxy.channels[channel_index_].state &= ~DR_BYPASS;
    }
    return 0;
}

int audio_mute_toggle(size_t channel_index_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("invalid channel:%d", (int)channel_index_);
        return 1;
    }
    audio_proxy.channels[channel_index_].state ^= DR_BYPASS;
    
    return 0;
}

int audio_volume(size_t channel_index_, int volume_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("channel:%d ", (int)channel_index_);
        return 1;
    }
    if(volume_){
        audio_proxy.channels[channel_index_].volume += 0.03;
    }else
    {
        audio_proxy.channels[channel_index_].volume -= 0.03;
    }
    return 0;
}

int audio_depitch(size_t channel_index_, int pitch_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("channel:%d ", (int)channel_index_);
        return 1;
    }
    if(pitch_){
        audio_proxy.channels[channel_index_].depitch += 0.01;
    }else
    {
        audio_proxy.channels[channel_index_].depitch -= 0.01;
        if(audio_proxy.channels[channel_index_].depitch < 0) {
            audio_proxy.channels[channel_index_].depitch = 0;
        }
    }   return 0;
}

int audio_pitch_reset(size_t channel_index_){
    
    if(channel_index_ >= audio_proxy.nb_channels){
        R_ERR("invalid channel:%d", (int)channel_index_);
        return 1;
    }
    audio_proxy.channels[channel_index_].depitch = 1.0;
    return 0;
}

int audio_nav(size_t channel_index_, int forward_) {

    if (channel_index_ >= audio_proxy.nb_channels) {
        R_ERR("channel:%d ", (int) channel_index_);
        return 1;
    }
    
    audio_channel_t* pchan = &audio_proxy.channels[channel_index_];
    
    const double step = forward_ ? 44100 * 0.3 * pchan->normal_ratio : -44100 * 0.3 * pchan->normal_ratio;

    if (pchan->state & DR_REVERSE) {
        pchan->buffer.offset += step;
    } else {
        pchan->buffer.offset -= step;
    }

    if (pchan->buffer.offset < 0) {
        pchan->buffer.offset = 0;
    }
    return 0;
}


int audio_proxy_init(size_t nb_channels_) {

    /* backend */
    audio_proxy.backend.buffer_frames = DR_FRAMES_PER_BUFFER;

    /* channels buffer */
    {
        size_t i;
        audio_proxy.nb_channels = nb_channels_;
        
        audio_proxy.channels = (audio_channel_t*) calloc(nb_channels_, sizeof (audio_channel_t));

        if (NULL == audio_proxy.channels) {
            R_ERR("audio proxy channels init error");
            return 1;
        }

        const size_t bbl = DR_CHAN_BIG_BUFFER / nb_channels_;

        for (i = 0; i < audio_proxy.nb_channels; i++) {
            audio_channel_t* chan = &audio_proxy.channels[i];
            chan->volume = 1.0;
            chan->depitch = 1.0;
            chan->buffer.len = bbl;
            chan->buffer.left = (S_MIX_HW_SMP_t*) calloc(bbl, sizeof ( S_MIX_HW_SMP_t));
            if (NULL == chan->buffer.left) {
                R_ERR("left channel init failed, not enought memory");
                return 1;
            } else {
                R_INFO("left channel(%d) init", (int) i);
            }
            chan->buffer.right = (S_MIX_HW_SMP_t*) calloc(bbl, sizeof ( S_MIX_HW_SMP_t));
            if (NULL == chan->buffer.right) {
                R_ERR("right channel init failed, not enought memory");
                return 1;
            } else {
                R_INFO("right channel(%d) init", (int) i);
            }

            R_INFO("channel %d initialized", (int) i);
        }
    }
    audio_proxy.state |= DR_INIT;
    return 0;
}

int audio_proxy_close() {
    size_t i;
    for (i = 0; i < audio_proxy.nb_channels; i++) {
        audio_channel_t* channel = &audio_proxy.channels[i];
        R_INFO("free channel %d (left)", (int) i);
        free(channel->buffer.left);
        R_INFO("free channel %d (right)", (int) i);
        free(channel->buffer.right);
    }
    R_INFO("free channels container ");
    free(audio_proxy.channels);
    return 0;
}

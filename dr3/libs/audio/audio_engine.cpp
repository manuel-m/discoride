/* 
 * File:   audio_engine.cpp
 * Author: jam
 * 
 * Created on 13 août 2013, 14:27
 */

#include <string.h>
#include <stdlib.h>
#include "audio_engine.h"
#include "audio_backend.h"
#include "audio_process.h"
#include "audio_loader.h"
#include "audio_proxy.h"
#include "drtrace.h"
#include "defs.h"


namespace dr {

    audio_engine::audio_engine(audio_backend& backend_,
            audio_loader& loader_, audio_process& process_) :
            m_backend(backend_), m_loader(loader_), m_process(process_) {
    }

    int audio_engine::open(size_t nb_channels_) {
        if (audio_proxy_get()->state & DR_OPEN) {
            R_ERR("audio already open");
            return 1;
        }
        if (!(audio_proxy_get()->state & DR_INIT)) {
            if( init(nb_channels_)){
                return 1;
            }
        }
        return m_backend.open(m_process.getProcessCallback());
    }

    int audio_engine::init(size_t nb_channels_) {
        return audio_proxy_init(nb_channels_);
    }
    
    int audio_engine::load(const char* filename_, size_t num_channel_){
        int res = 0;
        if(NULL == filename_){
            R_ERR("invalid filename");
            return 1;
        }
        if (!(audio_proxy_get()->state & DR_INIT)) {
            R_ERR("audio load without init");
            return 1;
        }        

        if (!(audio_proxy_get()->backend.state & DR_OPEN)) {
            R_ERR("audio load without backend open");
            return 1;
        }        
        
        if (audio_proxy_get()->nb_channels <= num_channel_) {
            R_ERR("not enought channels, requested:%d max:%d", 
                    num_channel_,
                    (audio_proxy_get()->nb_channels - 1));
            return 1;
        }        
        audio_channel_t &channel = audio_proxy_get()->channels[num_channel_];
        res = m_loader.load(filename_, channel.buffer);
        channel.normal_ratio = ((double)channel.buffer.sample_rate) / audio_proxy_get()->backend.sample_rate;
        
        
        return res;                
    }
    
    void audio_engine::give_back() {

        if ((audio_proxy_get()->state & DR_INIT)) {

            if (DR_OPEN & audio_proxy_get()->backend.state) {
                R_ERR("free audio ressources on opened state");
                return;
            }
            audio_proxy_close();
            audio_proxy_get()->state &= ~DR_INIT;
        }
    }

    int audio_engine::close() {
        int res = 0;
        res = m_backend.close();
        give_back();
        return res;
    }

    audio_engine::~audio_engine() {
        
        if(DR_OPEN & audio_proxy_get()->backend.state){
          R_WARN("free audio ressources on opened state");
          m_backend.close();
        }
        
        give_back();
    }

}

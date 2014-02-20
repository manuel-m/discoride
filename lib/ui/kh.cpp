/* 
 * File:   key.cpp
 * Author: jam
 * 
 * Created on 3 août 2013, 16:41
 */

#include <stddef.h>
#include "kh.h"
#include "drtrace.h"
#include "defs.h"

namespace dr {

    key_handler::key_handler() {
        m_state = 0;
    }

    key_handler::~key_handler() {
        std::map<int, key_info_t*>::iterator it = m_callbacks.begin();
        while (it != m_callbacks.end()) {
            key_info_t* key_info = it->second;
            free(key_info);
            it++;
        }
    }

    int key_handler::addCallback(int code_, key_callback_t* cb_, const char* help_) {

        if (get_key_info(code_)) {
            R_ERR("key %d already registered");
            return 1;
        }
        key_info_t* kh = (key_info_t*) calloc(1, sizeof (key_info_t));

        if (NULL == kh) {
            R_ERR("internal error");
            return 1;
        }
        kh->cb = cb_;
        kh->help = help_;
        m_callbacks[code_] = kh;
        return 0;
    }

    key_info_t* key_handler::get_key_info(int code_) {

        std::map<int, key_info_t*>::iterator it = m_callbacks.find(code_);
        if (it == m_callbacks.end()) {
            return NULL;
        } else {
            return it->second;
        }
    }

    void key_handler::trigger_callback(int key_, int state_) {

        key_info_t* key_info = get_key_info(key_);
        if (key_info && key_info->cb) {
            R_INFO("key:%d => %s", key_, key_info->help);
            key_info->cb(key_, state_);
        } else {
            R_INFO("key:%d not binded", key_);
        }
    }

    int key_handler::init() {
        int res = 0;
        R_INFO("key init");
        res |= configure();
        if (res) return res;
        R_INFO("key configure");
        m_state |= (DR_INIT | DR_CONFIGURE);
        return res;
    }

}


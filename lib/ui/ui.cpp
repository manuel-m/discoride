/* 
 * File:   ui.cpp
 * Author: jam
 * 
 * Created on 3 août 2013, 13:26
 */

#include "ui.h"
#include "kh.h"
#include "wid.h"
#include "wid_painter.h"
#include "drtrace.h"

namespace dr {

    ui::ui(key_handler& kh_) : m_key_handler(kh_) {
        m_state = 0;
        memset(&m_current_time, 0, sizeof(m_current_time));
        m_w = 0;
        m_h = 0;
    }

    ui::~ui() {
        close();
        std::vector<wid_painter*>::iterator it = m_wid_painters.begin();
        while (it != m_wid_painters.end()) {
            delete(*it);
            it++;
        }
    }

    int ui::add_wid(wid* wid_) {
        wid_painter* wp = create_painter(wid_);
        
        if(NULL == wp){
            R_ERR("could not create painter");
            return 1;
        }

        
        m_wid_painters.push_back(wp);

        return 0;
    }

    int ui::open() {
        int res = 0;

        /* already open exit with error */
        if (m_state & DR_OPEN) {
            R_ERR("ui already open");
            return 1;
        }
        res |= init_backend();
        if (res) return res;
        m_state |= DR_INIT;
        R_INFO("ui init");

        /* wids */
        res |= ui::configure();
        if (res) return res;

        /* shortcuts */
        res |= m_key_handler.init();
        if (res) return res;

        m_state |= DR_CONFIGURE;
        R_INFO("ui configure");

        res |= open_backend();
        if (res) return res;
        m_state |= DR_OPEN;
        R_INFO("ui open");

        return res;
    }

    int ui::update() {
        return update_backend();
    }

    int ui::close() {
        int res = 0;
        if (m_state & DR_OPEN) {
            R_INFO("ui close");
            close_backend();
            m_state &= ~DR_OPEN;
        }

        return res;
    }

    int ui::draw_wids() {
        std::vector<wid_painter*>::iterator it = m_wid_painters.begin();
        while (it != m_wid_painters.end()) {
            const wid* pwid = (*it)->m_wid;
            const float x = pwid->x * m_w;
            const float y = pwid->y * m_h;
            const float w = pwid->w * m_w;
            const float h = pwid->h * m_h;

            (*it)->drawv(x, y, w, h);
            it++;
        }
        return 0;
    }

}
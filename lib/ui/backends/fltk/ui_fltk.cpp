
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshadow"

#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>

#pragma GCC diagnostic error "-Wsign-conversion"
#pragma GCC diagnostic error "-Wshadow"

#include <sys/time.h>

#include "ui_fltk.h"
#include "defs.h"
#include "drtrace.h"
#include "kh.h"

namespace dr {



    class ui_window : public Fl_Window {
    private:
        key_handler& m_key_handler;
        int handle_key(int key_, int state_);

    public:

        ui_window(int width_, int height_, key_handler& kh_) :
        Fl_Window(width_, height_), m_key_handler(kh_) {

        };
        int handle(int e_);
    };

    int ui_window::handle(int e_) {

        switch (e_) {

            case FL_KEYDOWN:
            {
                if (FL_Escape == Fl::event_key()) {
                    exit(0);
                    return 1;
                }
                R_INFO("up %d", Fl::event_key());
                return handle_key(Fl::event_key(), 0);
            }
            case FL_KEYUP:
            {
                R_INFO("down %d", Fl::event_key());
                return handle_key(Fl::event_key(), 1);
            }
            default:
                return Fl_Window::handle(e_);
        };
    }

    int ui_window::handle_key(int key_, int state_) {

        key_info_t* key_info = m_key_handler.get_key_info(key_);
        if (key_info) label(key_info->help);
        if (!state_) m_key_handler.trigger_callback(key_, state_);
        return 1;
    }
    
    static void ui_refresh_main_timer(uv_timer_t* timer_, int status_) {
        (void) status_;
        dr::ui_fltk* ui = (dr::ui_fltk*) timer_->data;
        gettimeofday(ui->getCurrentTime(), 0);
       
    }    

    int ui_fltk::open_backend(void) {
        m_main_window->show();

        uv_timer_start(&m_timer, ui_refresh_main_timer, 0, 1000);
        return 0;
    }

    ui_fltk::ui_fltk(key_handler& kh_) : ui(kh_) {
    }

    ui_fltk::~ui_fltk() {
        close();
    }

    int ui_fltk::init_backend(void) {
        int w, h;
        w = Fl::w() / 3;
        h = Fl::h() / 3;
        m_w = (float) w;
        m_h = (float) h;
        m_main_window = new ui_window(w, h, m_key_handler);
        m_main_window->begin();


        m_main_window->end();
        uv_timer_init(uv_default_loop(), &m_timer);
        m_timer.data = (void*)this;        
        
        return 0;
    }

    int ui_fltk::update_backend(void) {
        return Fl::run();
    }

    int ui_fltk::close_backend(void) {
        return 0;
    }

}

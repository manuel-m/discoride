#include <typeinfo>

#include "glfw3.h"
#include <GL/glu.h>

#include "ui_glfw.h"
#include "defs.h"
#include "drtrace.h"
#include "deck_glfw.h"
#include "wid.h"

namespace dr {
    
    static void ui_glfw_error_callback(int error_, const char* description_) {
        R_ERR("(%d) %s", error_, description_);
    }

    static void ui_glfw_key_callback(GLFWwindow* window_, int key_, int scancode_, int action_, int mods_) {

        (void) window_;
        (void) scancode_;
        (void) mods_;

        R_INFO("key %d\tscancode %d\t action %d\tmod:%d", key_, scancode_,
                action_, mods_);

        if (key_ == GLFW_KEY_ESCAPE && action_ == GLFW_PRESS) {
            glfwSetWindowShouldClose(window_, GL_TRUE);
        }
    }
        
    wid_painter* ui_glfw::create_painter(wid* wid_){
        
        if(!strcmp(WID_DECK, wid_->type)) return new deck_glfw(wid_);
        
        /* we are here ... we are in trouble */
        R_ERR("type unknown %s", typeid(*wid_).name());        
        
        return NULL;
    }

    int ui_glfw::open_backend(void) {

        const GLFWvidmode* desktopMode;
        int w, h;

        desktopMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        w = desktopMode->width / 2;
        h = desktopMode->height / 2;

        m_w = (float) w;
        m_h = (float) h;

        glfwSetErrorCallback(ui_glfw_error_callback);

        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        m_main_window = glfwCreateWindow(w, h, "dr3", NULL, NULL);
        if (NULL == m_main_window) goto err;

        glfwMakeContextCurrent(m_main_window);
        glfwSwapInterval(1);
        glfwSetKeyCallback(m_main_window, ui_glfw_key_callback);

        /*glfwDisable( GLFW_MOUSE_CURSOR );*/

        /* Select and setup the projection matrix */
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, m_w, 0, m_h);
        glMatrixMode(GL_MODELVIEW);


        return 0;

err:
        glfwTerminate();
        return 1;

    }

    ui_glfw::ui_glfw(key_handler& kh_) : ui(kh_) {
    }

    ui_glfw::~ui_glfw() {
        close();
    }

    int ui_glfw::init_backend(void) {

        if (GL_FALSE == glfwInit()) return 1;
        glfwSetTime(0);
        return 0;
    }
    

    int ui_glfw::update_backend(void) {

        /* ===[ current time ] ==================*/
        xt_set_current_time(&m_xt_current);

        /* ===[ clean screen  ]==================*/
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        draw_wids();



        glfwSwapBuffers(m_main_window);
        glfwPollEvents();

        return glfwWindowShouldClose(m_main_window);
    }

    int ui_glfw::close_backend(void) {
        if (NULL != m_main_window) {
            glfwDestroyWindow(m_main_window);
        }
        glfwTerminate();
        return 0;
    }
}

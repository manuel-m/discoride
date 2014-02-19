#include <stdio.h>
#include "kh.h"
#include "defs.h"
#include "drtrace.h"
#include "deck_glfw.h"
#include "ui_glfw.h"
#include "color.h"
#include "wid.h"

int dr::ui::configure(void) {

    color_t bg_0 = {1, 1, 1, 0};
    color_t bg_1 = {1, 1, 1, 1};
    color_t bg_2 = {1, 0, 1, 1};
    color_t bg_3 = {1, 1, 0, 0};

    add_wid(new wid(WID_DECK, 0, 0, 0.5, 0.5, bg_0));
    add_wid(new wid(WID_DECK,0.5, 0, 0.5, 0.5, bg_1));
    add_wid(new wid(WID_DECK,0.5, 0.5, 0.5, 0.5, bg_2));
    add_wid(new wid(WID_DECK,0.6f, 0.6f, 0.2f, 0.2f, bg_3));

    return 0;
}

int dr::key_handler::configure(void) {
    return 0;
}

/*========================================================================
 * main
 *========================================================================*/
int main(int argc, char **argv) {

    (void) argc;
    (void) argv;

    rtrace_level(RTRACE_LEVEL_INFO);
    int quit = 0;

    dr::key_handler kh;
    dr::ui_glfw ui(kh);


    ASSERT_ZERO_GOTO_ERR(ui.open());
    do {
        quit |= ui.update();
    } while (!quit);
    ASSERT_ZERO_GOTO_ERR(ui.close());


    R_INFO("exit ok");
    return 0;

err:
    R_ERR("exit on error");

    return 1;

}



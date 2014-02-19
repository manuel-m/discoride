
#include "ui_minimal.h"
#include "kh.h"
#include "defs.h"
#include "drtrace.h"

int dr::ui::configure() {
    return 0;
}

int dr::key_handler::configure(void) {
    return 0;
}

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;

    dr::key_handler kh;
    dr::ui_minimal ui(kh);
    int quit = 0;

    ASSERT_ZERO_GOTO_ERR(ui.open());
    do {
        quit |= ui.update();
    } while (!quit);
    ASSERT_ZERO_GOTO_ERR(ui.close());

    R_INFO("happy end");
    return (0);

err:
    R_ERR("sad end");
    return (1);

}



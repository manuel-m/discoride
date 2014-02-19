#include "mpg123.h"
#include "drtrace.h"
#include "audio_defs.h"

#include "loader_mpg123.h"
#include "audio_portaudio.h"
#include "audio_engine.h"
#include "audio_process.h"
#include "kh.h"
#include "ui_fltk.h"
#include "drtrace.h"
#include "defs.h"



int main(int argc, char** argv) {

    const char* mp3_file = NULL;
    
    dr::audio_portaudio backend;
    dr::loader_mpg123 loader;
    dr::audio_process_mix1 process;
    dr::audio_engine au(backend, loader, process);
    dr::key_handler kh;
    dr::ui_fltk ui(kh);
      
    
    int quit = 0;
        
    if (2 != argc) {
        R_ERR("missing filename (%d)", argc);
        goto err;
    }
    mp3_file = argv[1];
    R_INFO("loading %s", mp3_file);

    ASSERT_ZERO_GOTO_ERR( au.open(1)); /* nb channels */
    ASSERT_ZERO_GOTO_ERR( au.load(mp3_file, 0) ); /* channel index */
        
    ASSERT_ZERO_GOTO_ERR(ui.open());
    do {
        quit |= ui.update();
    } while (!quit);
    ASSERT_ZERO_GOTO_ERR(ui.close());    

    
    ASSERT_ZERO_GOTO_ERR(au.close());

    R_INFO("happy end");
    return (0);

err:
    R_ERR("sad end");
    return (1);

}


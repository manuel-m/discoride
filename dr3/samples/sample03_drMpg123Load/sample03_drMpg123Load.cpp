#include <iostream>
#include <cstdlib>

#include "mpg123.h"
#include "drtrace.h"
#include "audio_defs.h"

#include "loader_mpg123.h"
#include "audio_engine.h"
#include "audio_process.h"
#include "drtrace.h"
#include "defs.h"
#include "audio_backend.h"

#define DR_NB_CHANNELS 1
#define DR_CHANNEL_INDEX 0

int main(int argc, char** argv) {

    const char* mp3_file = NULL;
    
    dr::audio_backend_dummy backend;
    dr::loader_mpg123 loader;
    dr::audio_process_dummy process;
    dr::audio_engine au(backend, loader, process);
    
    if (2 != argc) {
        R_ERR("missing filename (%d)", argc);
        goto err;
    }
    mp3_file = argv[1];
    R_INFO("loading %s", mp3_file);

    ASSERT_ZERO_GOTO_ERR( au.open(DR_NB_CHANNELS));
    ASSERT_ZERO_GOTO_ERR( au.load(mp3_file, DR_CHANNEL_INDEX) );
    
    ASSERT_ZERO_GOTO_ERR(au.close());

    R_INFO("happy end");
    return (0);

err:
    R_ERR("sad end");
    return (1);

}


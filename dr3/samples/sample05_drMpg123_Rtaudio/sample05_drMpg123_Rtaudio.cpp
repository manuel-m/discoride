#include <iostream>
#include <cstdlib>

#include "mpg123.h"
#include "drtrace.h"
#include "audio_defs.h"

#include "loader_mpg123.h"
#include "audio_rtaudio.h"
#include "audio_engine.h"
#include "audio_process.h"
#include "drtrace.h"
#include "defs.h"
#include "audio_proxy.h"


int main(int argc, char** argv) {

    const char* mp3_file = NULL;
    
    dr::audio_rtaudio backend;
    dr::loader_mpg123 loader;
    dr::audio_process_mix1 process;
    dr::audio_engine au(backend, loader, process);
    
    if (2 != argc) {
        R_ERR("missing filename (%d)", argc);
        goto err;
    }
    mp3_file = argv[1];
    R_INFO("loading %s", mp3_file);

    ASSERT_ZERO_GOTO_ERR( au.open(1));
    ASSERT_ZERO_GOTO_ERR( au.load(mp3_file, 0) ); /* channel 0 */
        
    char input;
    std::cout << "\nWaiting ... press <enter> to play.\n";
    std::cin.get(input);    
    
        audio_play(0, 1); /* play channel index 0 */
    
    std::cout << "\nPlaying ... press <enter> to quit.\n";
    std::cin.get(input);
    
    ASSERT_ZERO_GOTO_ERR(au.close());

    R_INFO("happy end");
    return (0);

err:
    R_ERR("sad end");
    return (1);

}



#include <iostream>
#include <cstdlib>
#include "audio_portaudio.h"
#include "audio_engine.h"
#include "audio_process.h"
#include "audio_loader.h"
#include "drtrace.h"
#include "defs.h"

int main() {
    dr::audio_portaudio backend;
    dr::audio_loader_dummy loader;
    dr::audio_process_sin process;
    dr::audio_engine au(backend, loader, process);
    
    ASSERT_ZERO_GOTO_ERR(au.open(1));

    char input;
    std::cout << "\nPlaying ... press <enter> to quit.\n";
    std::cin.get(input);

    ASSERT_ZERO_GOTO_ERR(au.close());

    R_INFO("happy end");
    return (0);

err:
    R_ERR("sad end");
    return (1);
}
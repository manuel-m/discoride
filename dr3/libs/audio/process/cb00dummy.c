#include <string.h>
#include "drtrace.h"
#include "audio_callbacks_c.h"
#include "audio_proxy.h"
#include "defs.h"



void cb00dummy(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_) {

    (void) out_;
    (void) framesPerBuffer_;
    (void) nb_channels_;
    (void) chan_;
}





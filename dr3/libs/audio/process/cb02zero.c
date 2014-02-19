#include <string.h>
#include "audio_callbacks_c.h"

void cb02zero(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_) {

    (void) nb_channels_;
    (void) chan_;

    memset(out_, 0, 2 * framesPerBuffer_ * sizeof (S_MIX_HW_SMP_t));

}





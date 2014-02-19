#include <math.h>
#include "audio_callbacks_c.h"

#define DR_SIN_TABLE_SIZE   (200)
#define DR_M_PI		3.14159265358979323846	/* pi */

typedef struct {
    int is_init;
    S_MIX_HW_SMP_t sine[DR_SIN_TABLE_SIZE];
    int left_phase;
    int right_phase;
} sin_data_t;



void cb03sin(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_) {

    static sin_data_t sin_data = {0};
    unsigned long i;
    (void) nb_channels_;
    (void) chan_;

    if (!sin_data.is_init) {
        for (i = 0; i < DR_SIN_TABLE_SIZE; i++) {
            sin_data.sine[i] = (S_MIX_HW_SMP_t) sin(((double) i / (double) DR_SIN_TABLE_SIZE) * DR_M_PI * 2.);
        }
        sin_data.left_phase = sin_data.right_phase = 0;
        sin_data.is_init = 1;
    }

    for (i = 0; i < framesPerBuffer_; i++) {
        *out_++ = sin_data.sine[sin_data.left_phase];
        *out_++ = sin_data.sine[sin_data.right_phase];
        sin_data.left_phase += 1;
        if (sin_data.left_phase >= DR_SIN_TABLE_SIZE) sin_data.left_phase -= DR_SIN_TABLE_SIZE;
        sin_data.right_phase += 3; /* higher pitch so we can distinguish left and right. */
        if (sin_data.right_phase >= DR_SIN_TABLE_SIZE) sin_data.right_phase -= DR_SIN_TABLE_SIZE;
    }


}










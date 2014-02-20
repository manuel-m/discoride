#include <string.h>
#include "drtrace.h"
#include "audio_callbacks_c.h"
#include "audio_proxy.h"
#include "defs.h"

void cb01mix1(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_) {
    unsigned long i;
    
    (void)nb_channels_;
    
    const double volume = chan_->volume;
    double offset_incr =  chan_->normal_ratio * chan_->depitch;
    const double offset_incr0 = (chan_->state & DR_REVERSE) ?  -offset_incr : offset_incr;  
    
    i = framesPerBuffer_;

    if (!(chan_->state & DR_ENABLE)) goto not_playing;
    if (chan_->state & DR_BYPASS) goto muted;

    do {
        /* chan_ : val = (valmax - valmin) ( x - offset ) + valmin */
        const int offset_0 = (int) (chan_->buffer.offset);
        const double opt1_0 = chan_->buffer.offset - (double) (offset_0);

        const double valmax_left_0 = chan_->buffer.left[ offset_0 + 1 ];
        const double valmin_left_0 = chan_->buffer.left[ offset_0 ];

        const double val_left_0
                = (valmax_left_0 - valmin_left_0) * opt1_0 + valmin_left_0;

        const double valmax_right_0 = chan_->buffer.right[ offset_0 + 1 ];
        const double valmin_right_0 = chan_->buffer.right[ offset_0 ];
        const double val_right_0
                = (valmax_right_0 - valmin_right_0) * opt1_0 + valmin_right_0;

        /* mixing */
        *out_++ = (S_MIX_HW_SMP_t) (val_left_0 * volume);
        *out_++ = (S_MIX_HW_SMP_t) (val_right_0 * volume);

        /* next value */
        chan_->buffer.offset += offset_incr0;

    } while (--i);

    /* stop when all has been read  */
    if (chan_->buffer.offset >= chan_->buffer.len) {
        chan_->state &= ~DR_ENABLE;
        R_INFO("chan buffer depleted");
    }
    return;
    
muted:
    chan_->buffer.offset += offset_incr0 * (double)framesPerBuffer_;
    
    
not_playing:
    memset(out_, 0, 2 * framesPerBuffer_ * sizeof (S_MIX_HW_SMP_t));

}





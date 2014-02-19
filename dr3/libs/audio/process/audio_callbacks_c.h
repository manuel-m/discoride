/* 
 * File:   audio_process.h
 * Author: jam
 *
 * Created on 9 août 2013, 18:53
 */

#ifndef AUDIO_CPROCESS_H
#define	AUDIO_CPROCESS_H

#include "audio_defs.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    
void cb00dummy(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
             audio_channel_t* chan_, int nb_channels_);
    
void cb01mix1(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_);

void cb02zero(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_);

void cb03sin(S_MIX_HW_SMP_t *out_, unsigned long framesPerBuffer_,
        audio_channel_t* chan_, int nb_channels_);


#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_CPROCESS_H */


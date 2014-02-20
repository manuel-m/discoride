/* 
 * File:   audio_defs.h
 * Author: jam
 *
 * Created on 13 août 2013, 02:01
 */

#ifndef AUDIO_DEFS_H
#define	AUDIO_DEFS_H

#include <stddef.h>
#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#define DR_STEREO (2)    
#define DR_FRAMES_PER_BUFFER  (64)
#define DR_DEFAULT_BACKEND_SAMPLE_RATE (44100)    
   
#define DR_CHAN_BIG_BUFFER (100 * 1000 * 1000)
#define DR_MP3_DECODE_BUFFER (10000)
#define DR_AUDIO_FRAMES_PER_BUFFER  (512)

#define DR_AUDIO_MIX_FMT         paFloat32
typedef float S_MIX_HW_SMP_t;
#define S_MIX_HW_SMP_ZERO         (0.0)
/*#define S_MEM_2_SMP(x) ((S_MIX_HW_SMP_t)(x) / 32767)*/
#define S_MEM_2_SMP(x) ((S_MIX_HW_SMP_t)(x) * 0.000030519f)
#define R_AUDIO_MIX_FMT_NAME         "Float 32 Bit"
typedef float S_MEM_SMP_t;

typedef struct audio_buffer_t_ {
    long sample_rate;
    S_MIX_HW_SMP_t* left;
    S_MIX_HW_SMP_t* right;
    size_t len;
    uint32_t state;
    double offset; 
    
} audio_buffer_t;

typedef struct audio_channel_t_ {
    audio_buffer_t buffer;
    double normal_ratio;
    double depitch;
    double volume;
    
    /* double last_audio_buffer_offset;  !!! */
    uint32_t state;

} audio_channel_t;

typedef void audio_process_callback_t(S_MIX_HW_SMP_t*, unsigned long,
        audio_channel_t*, int);


#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_DEFS_H */


#ifndef __RCHAN_H__
#define __RCHAN_H__

/*========================================================================
 * includes
 *========================================================================*/
#include "rtrack.h"
#include "rglu.h"

/*========================================================================
 * chan state
 *========================================================================*/
#define R_CHAN_DISABLED     0
#define R_CHAN_LOADING_STOP 1
#define R_CHAN_STOP 2
#define R_CHAN_LOADING_PLAY 3
#define R_CHAN_PLAY 4
#define R_CHAN_STATES 5

#define R_WAVEFORM_SAMPLING 392

/*========================================================================
 * HW mixing
 *========================================================================*/
#define S_MIX_HW_UINT8    (0)
#define S_MIX_HW_INT8     (0)
#define S_MIX_HW_INT16    (0)
#define S_MIX_HW_FLOAT32  (1)

#if S_MIX_HW_UINT8
#define R_AUDIO_MIX_FMT         paUInt8
typedef unsigned char S_MIX_HW_SMP_t;
#define S_MIX_HW_SMP_ZERO         (0x80)
#define R_AUDIO_MIX_FMT_NAME         "Unsigned 8 Bit"

#elif S_MIX_HW_INT8
#define R_AUDIO_MIX_FMT         paInt8
typedef char S_MIX_HW_SMP_t;
#define S_MIX_HW_SMP_ZERO         (0)
#define R_AUDIO_MIX_FMT_NAME         "Signed 8 Bit"

#elif S_MIX_HW_INT16
#define R_AUDIO_MIX_FMT         paInt16
typedef short S_MIX_HW_SMP_t;
#define S_MIX_HW_SMP_ZERO         (0)
#define S_MEM_2_SMP(x) ((S_MIX_HW_SMP_t)(x))
#define R_AUDIO_MIX_FMT_NAME         "Signed 16 Bit"

#elif S_MIX_HW_FLOAT32
#define R_AUDIO_MIX_FMT         paFloat32
typedef float S_MIX_HW_SMP_t;
#define S_MIX_HW_SMP_ZERO         (0.0)
/*#define S_MEM_2_SMP(x) ((S_MIX_HW_SMP_t)(x) / 32767)*/
#define S_MEM_2_SMP(x) ((S_MIX_HW_SMP_t)(x) * 0.000030519f)
#define R_AUDIO_MIX_FMT_NAME         "Float 32 Bit"
#endif

/*========================================================================
 * rchan
 *========================================================================*/
typedef struct _rchan {

  /* mpg123 */
  long sample_rate;

  /* portaudio buffer */
  S_MIX_HW_SMP_t* left;
  S_MIX_HW_SMP_t* right;
  size_t buffer_len;

  /* waveform buffer */
  float* waveform_min;
  float* waveform_max;

  rchar255 filename;

  double normal_ratio;

  double audio_buffer_offset;
  double last_audio_buffer_offset;

  double wavebuffer_offset;

  rtimer last_action_date;

  int is_loading;
  int is_playing;

  rtrack* track;

} rchan;


double rchan_pos( rchan* chan, double x1, double w, double x_pushed );


#endif /*__RCHAN_H__ */
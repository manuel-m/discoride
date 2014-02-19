#ifndef __RAUDIO_H__
#define __RAUDIO_H__

/*========================================================================
 * includes
 *========================================================================*/
#include <stdio.h>
#include <strings.h>
#include <mpg123.h>
#include <math.h>
#include <portaudio.h>

#include "rplaylist.h"
#include "rchan.h"
#include "raudio_meter.h"

/*========================================================================
 * audio define
 *========================================================================*/
#define RDECK_A 0
#define RDECK_B 1
#define R_CHAN_BIG_BUFFER 100000000
#define R_MP3_DECODE_BUFFER 10000
#define S_STREAM_PLAY_RATE 44100
#define R_AUDIO_CHANNELS 2
#define R_AUDIO_FRAMES_PER_BUFFER  (512)

#define R_PUNCH 0.15

#define R_DEPITCH 0.01
#define R_DEVOL 0.05
#define R_DEGAIN 0.05
#define R_DEXFADE 0.03
#define R_DENAV 0.02

#define R_STRAF_LEFT 0
#define R_STRAF_RIGHT 1
#define R_STRAF_SPEED R_WAVEFORM_SAMPLING * 2

/*========================================================================
 * Sample memory
 *========================================================================*/
#define S_MEM_SMP_UINT8    (0)
#define S_MEM_SMP_INT8     (0)
#define S_MEM_SMP_INT16    (1)
#define S_MEM_SMP_FLOAT32  (0)

#if S_MEM_SMP_UINT8
typedef unsigned char S_MEM_SMP_t;
#elif S_MEM_SMP_INT8
typedef char S_MEM_SMP_t;
#elif S_MEM_SMP_INT16
typedef short S_MEM_SMP_t;
#elif S_MEM_SMP_FLOAT32
typedef float S_MEM_SMP_t;
#endif




/*========================================================================
 * raudiotag
 *========================================================================*/
typedef struct _raudiotag {
  rchar255 title;
  rchar255 artist;
} raudiotag;

typedef rchan rchans[R_AUDIO_CHANNELS];

/*========================================================================
 * raudio
 *
 *
 *========================================================================*/
typedef struct _raudio {

  /* mpg123 */
  unsigned char* mp3decode_buffer;
  size_t mp3_decode_buffer_size;
  mpg123_handle *mh;

  /* portaudio */
  PaStream *stream;
  PaStreamParameters outputParameters;
  double device_rate;
  unsigned short device_ok;
  PaError paerr;
} raudio;

void raudio_config(void);
void raudio_display(void );
void raudio_init(void);
void raudio_playlist_populate(void);

void raudio_device( const unsigned short wanted_nbChannels,
                    const PaSampleFormat format );

int raudio_portaudio_error( void );
void raudio_close( void );

int raudio_decode( rtrack* track, const int channel);

void raudio_start( void  );
void raudio_stop( void );

void raudio_xfader_right( void );
void raudio_xfader_left( void );

void raudio_xfader_right_auto( const int);
void raudio_xfader_left_auto( const int );
void raudio_xfader_toggle_auto( const int);
void raudio_chan_load( const int  );

void f_play0_label_update(void*);
void f_play1_label_update(void*);

/*========================================================================
 * playback
 *========================================================================*/
int raudio_playbuffer_cb( const void *inputBuffer,
                          void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData );

/*========================================================================
 * wid callbacks
 *========================================================================*/
void f_cue0_fire(const int);
void f_cue1_fire(const int);

void f_cue0_fire_key(void);
void f_cue1_fire_key(void);

void f_cue0_fire_set_on_fly_key(void);
void f_cue1_fire_set_on_fly_key(void);

void f_play_fire(const int);
void f_play0_fire(void);
void f_play1_fire(void);

/*========================================================================
 * decode audio callbacks
 *========================================================================*/
int raudio_chan0_decode_callback_TS(void* );
int raudio_chan1_decode_callback_TS(void* );

/*========================================================================
 * main loop callbacks
 *
 *
 *========================================================================*/
void f_loading_chan0(void);
void f_loading_chan1(void);
void f_straffing_chan0(void);
void f_straffing_chan1(void);

/*========================================================================
 * callbacks ???
 *========================================================================*/
void raudio_save_depitch_context(void);



#endif /*__RAUDIO_H__*/

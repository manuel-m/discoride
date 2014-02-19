#ifndef __RDISPLAY_H__
#define __RDISPLAY_H__

/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rkey.h"
#include "rglfw.h"
#include "rbutton.h"
#include "rframe.h"
#include "rdeckgauge.h"
#include "rdeckwave4.h"
#include "rlabel.h"
#include "rjog.h"
#include "rvslider2.h"
#include "rhslider2.h"
#include "rvmeter.h"

/*========================================================================
 * defines
 *
 *
 *========================================================================*/
#define RCOLOR_DEFAULT    0
#define RCOLOR_DISABLED   1
#define RCOLOR_ACTIVATED  2
#define RCOLOR_PUSHED     3
#define RCOLOR_OVER       4
#define RNB_COLOR_STATES  5

/*window mode*/
#define RDISPLAY_WINDOW         0
#define RDISPLAY_FULLSCREEN     1
#define RDISPLAY_DESKTOP        2

#define R_EVT_TIMEPERIOD      200

/*========================================================================
 * rpoll_cb
 *
 *
 *========================================================================*/
typedef struct _rpoll_cb {
  int* state;
  void (*f_action)(void);
} rpoll_cb;

RLIST_DECL( rlspoll_cb, rpoll_cb )


/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rdisplay_window_resize(void);
void rdisplay_ratio_compute(void);
void rdisplay_window_caption(void* addr);

void rdisplay_rwid_label_compute( rwid* wid );
void rdisplay_config(void);

void rdisplay_key_quit(void);
void rdisplay_window_mode_toggle(const size_t widex);

void rdisplay_mainloop_cb_add(int*, void (*f_action)(void));

void rdisplay_poll_user_evts( void );
void rdisplay_poll_cbs( void);

#endif /*__RDISPLAY_H__*/



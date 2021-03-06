#ifndef __RGLFW_H__
#define __RGLFW_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glfw.h>

/*========================================================================
 * ruser_evtQ
 *
 * emit from non main loop thread
 *========================================================================*/
typedef struct _ruser_evtQ {
  size_t len;
  void(*f_evts[RMAX_EVTS_Q]) (void);
} ruser_evtQ;



/*========================================================================
 * functions
 *
 *
 *========================================================================*/

/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rglfw_init(void);
void rglfw_mainLoop(void);
void rglfw_push_evt(  void (*f_evt)(  void ) );






#endif /* __RGLFW_H__ */
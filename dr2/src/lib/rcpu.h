#ifndef __RCPU_H__
#define __RCPU_H__
/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include <sys/time.h>
#include <sys/resource.h>
#include "rglu.h"
/*========================================================================
 * struct rcpu_clamp
 *
 *
 *========================================================================*/
typedef struct _rcpu {

  struct rusage usage_after;
  struct rusage usage_before;
  rtimer timer_before;
  rtimer timer_after;
  double cpu_user;
  double cpu_sys;

} rcpu;

/*========================================================================
 * functions
 *
 *
 *========================================================================*/
void rcpu_init(rcpu*);
void rcpu_update(void);
void rcpu_clamp(const size_t limitcpu,
                const int wait4milli);

/*========================================================================
 * rtimeval_subtract
 *
 *
 *========================================================================*/
int rtimeval_subtract(struct timeval *result,
                      struct timeval *x,
                      struct timeval *y);

#endif /*__RCPU_H__*/



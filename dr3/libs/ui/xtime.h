/* 
 * File:   xtime.h
 * Author: jam
 *
 * Created on 3 août 2013, 14:50
 */

#ifndef XTIME_H
#define	XTIME_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "tinycthread.h"    

#define xt_cpy( TDEST, TSRC ) (TDEST).sec = (TSRC).sec; (TDEST).nsec = (TSRC).nsec

#define xt_add_nano( TIMER, NANO ) \
  { \
    (TIMER).nsec += NANO; \
    if ((TIMER).nsec >= 1000000000L) { \
      (TIMER).sec++; \
      (TIMER).nsec -= 1000000000L; } \
  }    
    
#define xt_set_current_time( PTIMER ) xtime_get( (PTIMER), TIME_UTC  )    



#ifdef	__cplusplus
}
#endif

#endif	/* XTIME_H */


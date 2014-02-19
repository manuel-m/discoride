#ifndef __RSTDDEFINES_H__
#define __RSTDDEFINES_H__

#include "rmacro.h"



/*========================================================================
 * typedef
 *
 *
 *========================================================================*/
typedef unsigned long int ruint32;
typedef char rchar80[81];
typedef char rchar255[256];
typedef void (*rfunc)(void);

/*========================================================================
 * defines
 *
 *
 *========================================================================*/
#define RCOLOR_DEPTH 4
#define RMAX_EVTS_Q 256

#define RK_LAST 333
#define DEGREE 0.017453293  /*M_PI / 180.0*/
#define MPIx2 6.283185307   /*M_PI * 2*/

#define NULL_FANIMATE_CB 0
#define NULL_FOVER_IN 0
#define NULL_FOVER_OUT 0
#define NULL_LABEL 0
#define NULL_STEP 0
#define NULL_WDATA 0
#define NULL_NORMX 0
#define NULL_NORMY 0
#define NULL_FMOUSE_HANDLER 0
#define NULL_FWHEEL_UP_HANDLER 0
#define NULL_FWHEEL_DOWN_HANDLER 0
#define NULL_FDRAW 0
#define NULL_FWHEEL_DOWN 0
#define NULL_FWHEEL_UP 0
#define NULL_FWHEEL_CENTER 0
#define NULL_FFIRE0 0
#define NULL_FFIRE1 0
#define NULL_RENDER_SPEC 0
#define NULL_FDRAW_CB 0
#define BASIC_TEX 1, 1, 1


#define rall_states -1
#define rmasked 0
#define rdisabled 1
#define rnormal 2
#define ractivated 3
#define R_NB_RSTATE_STATES 4


#ifdef DEBUG

#define rstrcpy( DEST, SRC ) \
  R_ASSERT_ERROR_INFO( strlen( SRC ) < ( sizeof( DEST ) / sizeof( char ) ), SRC ); \
  strcpy( DEST,  SRC);

#else

#define rstrcpy( DEST, SRC ) \
  strcpy( DEST,  SRC);
#endif




#endif /*__RSTDDEFINES_H__*/
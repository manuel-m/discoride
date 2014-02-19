#ifndef __RMACRO_H__
#define __RMACRO_H__

#include "rtrace.h"

#if defined(__unix__)
    #define RFOLDER_SEP '/'
#else
/*TODO*/
#endif



/* -------------------------------------------------------------------------*/
/* standards macro                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
#ifndef R_ABS
#define R_ABS(a)     (((a) < 0) ? -(a) : (a))
#endif

#ifndef R_CLAMP
#define R_CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#endif

#ifndef R_MAX
#define R_MAX(x, y) ((x) > (y) ? (x) : (y))
#endif

#ifndef R_MIN
#define R_MIN(x, y) ((x) < (y) ? (x) : (y))
#endif

#ifndef R_ROUND
#define R_ROUND(x) ((int)((x) + 0.5))
#endif



/*********************************/
/*    utility macros             */
/*********************************/
#define R_INNER(BIG, INNER, BDSIZE) \
  { \
    (INNER).x = (BIG).x + (BDSIZE); \
    (INNER).y = (BIG).y + (BDSIZE);  \
    (INNER).w = (BIG).w - ((BDSIZE) << 1); \
    (INNER).h = (BIG).h - ((BDSIZE) << 1);  \
  }

#define R_TRANSLATE_RINNER_IN_DX_DY(BIG, INNERW, INNERH, DX, DY, RES) \
  { \
    (RES).x = (BIG).x + ( DX ); \
    (RES).y = (BIG).y + ( DY ); \
    (RES).w = (INNERW); \
    (RES).h = (INNERH); \
  }

#define R_TRANSLATE_RINNER_IN_CENTER(BIG, INNERW, INNERH, RES) \
  { \
    (RES).x = (BIG).x + ( ( (BIG).w - (INNERW) ) >> 1 ); \
    (RES).y = (BIG).y + ( ( (BIG).h - (INNERH) ) >> 1 ); \
    (RES).w = (INNERW); \
    (RES).h = (INNERH); \
  }

#define R_TRANSLATE_RINNER_IN_CENTER_LEFT(BIG, INNERW, INNERH, RES) \
  { \
    (RES).x = (BIG).x; \
    (RES).y = (BIG).y + ( ( (BIG).h - (INNERH) ) >> 1 ); \
    (RES).w = (INNERW); \
    (RES).h = (INNERH); \
  }

#define R_INSIDE(X, Y, RECT) \
  ( (RECT).x <= (X) ) && \
  ( (RECT).x + (RECT).w  >= (X) ) && \
  ( (RECT).y <= (Y)) && \
  ( (RECT).y + (RECT).h  >= (Y)) \


#define R_FORCE_INSIDE(X, Y, RECT) \
  { \
    if ( (X) < (RECT).x) X = (RECT).x; \
    else if ( (X) > ((RECT).x + (RECT).w ) ) X = ( (RECT).x + (RECT).w ); \
    if ( (Y) < (RECT).y) Y = (RECT).y; \
    else if ( (Y) > ((RECT).y + (RECT).h ) ) Y = ( (RECT).y + (RECT).h ); \
  }


#endif /*__RMACRO_H__*/
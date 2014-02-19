/* 
 * File:   drRect.h
 * Author: jam
 *
 * Created on 21 mars 2013, 00:43
 */

#ifndef DRRECT_H
#define	DRRECT_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _drRecti_t {

  int x;
  int y;
  int w;
  int h;

} drRecti_t;


typedef struct _drRectf_t {

  float x;
  float y;
  float w;
  float h;

} drRectf_t;


#define R_INSIDE(X, Y, RECT) \
  ( (RECT).x <= (X) ) && \
  ( (RECT).x + (RECT).w  >= (X) ) && \
  ( (RECT).y <= (Y)) && \
  ( (RECT).y + (RECT).h  >= (Y))


#ifdef	__cplusplus
}
#endif

#endif	/* DRRECT_H */


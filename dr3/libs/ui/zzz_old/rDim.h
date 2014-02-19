/* 
 * File:   drDim.h
 * Author: jam
 *
 * Created on 24 mars 2013, 17:55
 */

#ifndef DRDIM_H
#define	DRDIM_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _drDimi_t {

  int w;
  int h;

} drDimi_t;



typedef struct _drPointi_t {

  int x;
  int y;

} drPointi_t;

typedef struct _drMousei_t {

  int x;
  int y;
  int wheel;

} drMousei_t;


#ifdef	__cplusplus
}
#endif

#endif	/* DRDIM_H */


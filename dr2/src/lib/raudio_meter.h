#ifndef __RAUDIOMETER_H__
#define __RAUDIOMETER_H__

/*********************************/
/*    depedencies includes       */
/*********************************/

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rdata.h"
/*********************************/
/*    defines                    */
/*********************************/
#define R_PEAK_CPT 1


typedef struct _raudio_meter {
  size_t cpt;
  float peak_left;
  float peak_right;
} raudio_meter;

#endif
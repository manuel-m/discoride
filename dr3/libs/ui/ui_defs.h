/* 
 * File:   drUiDefs.h
 * Author: jam
 *
 * Created on 22 mars 2013, 23:34
 */


#include "defs.h"
#include "rRect.h"
#include "rDim.h"


#ifndef DRDISPLAYDEFS_H
#define	DRDISPLAYDEFS_H

#ifdef DISPLAY_WITH_GLFW
#include "key_glfw.h"
#endif

#ifdef	__cplusplus
extern "C" {
#endif
    
#define RDISPLAY_W 640
#define RDISPLAY_H 480
    
#define MAX_DEFAULT_CHAR 255    

#define RFLAG_INIT           (1u << 0)
#define RFLAG_VISIBLE        (1u << 1)
#define RFLAG_ENABLED        (1u << 2)
#define RFLAG_ACTIVATED      (1u << 3)
    
#define RFLAG_MOUSE_OVER     (1u << 4)
#define RFLAG_FOCUS          (1u << 5)
#define RFLAG_AUTOFOCUS      (1u << 6)
#define RCLIC_LEFT           (1u << 7)
#define RCLIC_RIGHT          (1u << 8)
#define RFLAG_FREE1          (1u << 9)
#define RFLAG_FREE2          (1u << 10)
#define RFLAG_RESIZE         (1u << 11)
#define RFLAG_LABEL_CHANGED  (1u << 12)
#define RFLAG_NORM_CHANGED   (1u << 13)
#define RFLAG_STATE_CHANGED  (1u << 14)
#define RFLAG_FULLSCREEN     (1u << 15)    
    
#define RMOUSE_LEFT  0    
#define RMOUSE_RIGHT 1
    
#define RMOUSE_UP   0
#define RMOUSE_DOWN 1
    
#define ROVER_IN   0
#define ROVER_OUT  1
    
#define RWHEEL_DOWN   0
#define RWHEEL_UP     1
    
    
#define REV_TAB            0
#define REV_SPACE          1
    
    
#include "xtime.h"
    
#ifdef	__cplusplus
}
#endif

#endif	/* DRDISPLAYDEFS_H */


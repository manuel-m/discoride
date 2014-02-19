/* 
 * File:   drWid.h
 * Author: jam
 *
 * Created on 21 mars 2013, 00:39
 */

#ifndef DRWIDGET_H
#define	DRWIDGET_H

#include <stdint.h>


#include "ui_defs.h"

#ifdef	__cplusplus
extern "C" {
#endif
    



typedef struct _drWid_t {
    
  int user_data;
  int index;
  int parent_index;
  drRectf_t ratio;
  drRecti_t bb;
  int type;
  uint32_t state;
  
  void (*f_draw)(  struct _drWid_t* );
  void (*f_close)( struct _drWid_t* );
  void (*f_mouseclic)( struct _drWid_t*, int, int  );
  void (*f_mouseover)( struct _drWid_t* , int, int  );
  void (*f_mousewheel)( struct _drWid_t*, int, int  );
  void (*f_init)(  struct _drWid_t* );
    
} drWid_t;

typedef struct _drWids_t {

  uint_fast8_t n;
  drWid_t *t;

} drWids_t;  



#define DR_WID_CB_DECL(TYPE) \
void TYPE##_init(drWid_t* wid);\
void TYPE##_close(drWid_t* wid);\
void TYPE##_draw(drWid_t* wid);\
void TYPE##_mouseclic(drWid_t* wid, int, int);\
void TYPE##_mouseover(drWid_t* wid, int, int);\
void TYPE##_mousewheel(drWid_t* wid, int, int);

#define DR_WID_CB_STUB(TYPE) \
void TYPE##_init(drWid_t* wid){ (void) wid;}; \
void TYPE##_close(drWid_t* wid){ (void) wid;}; \
void TYPE##_draw(drWid_t* wid){ (void) wid;}; \
void TYPE##_mouseclic(drWid_t* wid, int b, int s){(void) wid;(void)b; (void)s;}; \
void TYPE##_mouseover(drWid_t* wid, int b , int s){(void) wid;(void)b; (void)s;}; \
void TYPE##_mousewheel(drWid_t* wid, int b , int s){(void) wid;(void)b; (void)s;};



#define DR_WID_BIND(TYPE,NAME,ID,PARENT,RX,RY,RW,RH,STATE)\
    [NAME##_##ID] =\
    {\
        .parent_index = PARENT,\
        .ratio = \
        { \
           .x = RX,\
           .y = RY, \
           .w = RW, \
           .h = RH \
        }, \
        .type = T_##TYPE, \
        .state = STATE, \
       .f_draw = TYPE##_draw, \
       .f_close = TYPE##_close,\
       .f_mouseclic = TYPE##_mouseclic,\
       .f_mouseover = TYPE##_mouseover,\
       .f_mousewheel = TYPE##_mousewheel,\
       .f_init = TYPE##_init \
    }


DR_WID_CB_DECL(drWid);



#ifdef	__cplusplus
}
#endif

#endif	/* DRWIDGET_H */


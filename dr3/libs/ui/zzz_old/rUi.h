/* 
 * File:   drUi.h
 * Author: jam
 *
 * Created on 20 mars 2013, 22:41
 */

#ifndef DRDISPLAY_H
#define	DRDISPLAY_H

#include "rWid_old.h"
#include "rKey.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct _rRatio_t {
        float w;
        float h;
        float g;

    } rRatio_t;

    typedef struct _drKeysSet {
        int n;
        int cur;
        rKey_t t[][RKEY_NB];

    } drKeysSet_t;

    typedef struct _drUiMod {
        
        int (*f_init)(void);
        int (*f_open)(const char*);
        int (*f_close)(void);
        int (*f_mainloop)(void);

    } drUiMod_t;

    typedef struct _drUi {
        
        uint32_t state;
        drDimi_t desktop;
        drDimi_t window;
        rRatio_t ratio;
        drMousei_t mouse;
        xtime xt_lag_resize;
        xtime xt_current;
        drWid_t* wid_over;

        drWids_t* wids;
        drKeysSet_t ksets;

        drUiMod_t* mod;


    } drUi_t;

    int drUi_init(drUiMod_t* _mod);
    /* -> expected bind => ex: drGlfw_bind*/
    
    int drUi_load(drWids_t* _wids);
#define drUi_open(TITLE) g_ui->mod->f_open(TITLE)
#define drUi_mainloop(NOT_USED) g_ui->mod->f_mainloop()
    
    int drUi_terminate(void);
    int drUi_close(void);
    
    int drUi_ratioCompute(void);
    int drUi_recomputeBb(void);
    int drUi_redrawAll(void);
     
    int drUi_mouseClic(int _id, int _state);
    int drUi_key(int _code, int _state);
    int drUi_mouseMove(int _x, int _y);
    int drUi_mouseWheel(int _wheel);
    

    drUi_t* g_ui; /* global definition */


#define DR_UI_MOD_CB_DECL(TYPE) \
    drUiMod_t* TYPE##_new(void);\
    int TYPE##_init(void);\
    int TYPE##_close(void);\
    int TYPE##_open(const char*);\
    int TYPE##_mainloop(void);
    
#define DR_UI_MOD_CB_BIND(MOD, TYPE) \
    (MOD)->f_init=&TYPE##_init;\
    (MOD)->f_close=&TYPE##_close;\
    (MOD)->f_open=&TYPE##_open;\
    (MOD)->f_mainloop=&TYPE##_mainloop;



#ifdef	__cplusplus
}
#endif

#endif	/* DRDISPLAY_H */


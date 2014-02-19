
#include "drButtonPlay.h"

/*typedef enum {
    PLAY_TEX_NORMAL = 0,
    PLAY_TEX_SELECTED,
    PLAY_TEX_NORMAL_FOCUS,
    PLAY_TEX_SELECTED_FOCUS,
    PLAY_NB_TEX
} tex_drButtonPlay_e;


 drTex_t _texs_play[2][PLAY_NB_TEX];
 */

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_init(drWid_t* wid) {
    (void) wid;
    /*  DR_WID_CB_BINDING(wid, drButtonPlay);

    wid->f_close = drButtonPlay_close;
    wid->f_clicLeft = drButtonPlay_clicLeft;
    wid->f_clicRight = drButtonPlay_clicRight;
      
    wid->f_overIn = drButtonPlay_overIn;
    wid->f_overOut = drButtonPlay_clicRight;
    wid->f_wheelUp = drButtonPlay_wheelUp;
    wid->f_wheelDown = drButtonPlay_wheelDown;
    wid->f_wheelCenter = drButtonPlay_wheelCenter;

    drTex_init(_texs_play[wid->user_data],
                PLAY_NB_TEX,
                0,0,1,1);
     */

}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_draw(drWid_t* wid) {
    (void)wid;
/*
    const size_t idx = (wid->user_data) ? 1: 0;
    const rcolor3f_t* frameBgColor = getColor(FRAME_COLOR_BG);
    const rcolor3f_t* buttonBgColor = getColor(BUTTON_COLOR_BG_DARK);
    const rcolor3f_t* buttonTxtColorSelected = (!wid->user_data) ? getColor(DOCK0_COLOR_NORMAL) : getColor(DOCK1_COLOR_NORMAL);
    drTex_t* t_normal = &_texs_play[idx][PLAY_TEX_NORMAL];
    drTex_t* t_selected = &_texs_play[idx][PLAY_TEX_SELECTED];
    drTex_t* t_normal_focus = &_texs_play[idx][PLAY_TEX_NORMAL_FOCUS];
    drTex_t* t_selected_focus = &_texs_play[idx][PLAY_TEX_SELECTED_FOCUS];
       if (wid->state & RFLAG_RESIZE) {
           
           drTex_prepareLayoutFree(_texs_play[idx], PLAY_NB_TEX, &wid->bb);
        
        drDrawCairo_labelButton(t_normal,
                "play",
                frameBgColor, 
                buttonBgColor, 
                buttonTxtColorSelected, 
                buttonTxtColorSelected,
                0);
    
        drDrawCairo_labelButton(t_selected,
                "play",
                frameBgColor,
                buttonBgColor,
                buttonTxtColorSelected, 
                buttonTxtColorSelected,
                RFLAG_ACTIVATED);
    
        drDrawCairo_labelButton(t_normal_focus,
                "play",
                frameBgColor,
                buttonBgColor,
                buttonTxtColorSelected, 
                buttonTxtColorSelected,
                RFLAG_FOCUS);
    
        drDrawCairo_labelButton(t_selected_focus,
                "play",
                frameBgColor,
                buttonBgColor, 
                buttonTxtColorSelected, 
                buttonTxtColorSelected,
                RFLAG_ACTIVATED | RFLAG_FOCUS);
    
        drTex_finalize(_texs_play[idx], PLAY_NB_TEX);
    
        wid->state &= ~RFLAG_RESIZE;
    
       }
    
        if (wid->state & RFLAG_ACTIVATED) {
            if (wid->state & RFLAG_FOCUS) {
                drTex_blit(t_selected_focus);
            } else {
                drTex_blit(t_selected);
            }
        } else {
            if (wid->state & RFLAG_FOCUS) {
                drTex_blit(t_normal_focus);
            } else {
                drTex_blit(t_normal);
            }
        }
 */ 
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_clicLeft(drWid_t* wid, const int val) {
    (void) val;
    wid->state ^= RFLAG_ACTIVATED;
    /*wid->f_draw(wid);*/
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_clicRight(drWid_t* wid, const int val) {
    (void) wid;
    (void) val;
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_overIn(drWid_t* wid, const int val) {
    (void) val;
    /* printf("i %p\n", wid);*/
    drButtonPlay_draw(wid);
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_overOut(drWid_t* wid, const int val) {
    (void) val;
    /* printf("o %p\n", wid);*/
    drButtonPlay_draw(wid);
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_wheelUp(drWid_t* wid, const int val) {
    (void) wid;
    (void) val;
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_wheelDown(drWid_t* wid, const int val) {
    (void) wid;
    (void) val;
}

/*========================================================================
 *
 *========================================================================*/
void drButtonPlay_wheelCenter(drWid_t* wid, const int val) {
    (void) wid;
    (void) val;
}







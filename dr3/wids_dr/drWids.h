
#ifndef DRWIDS_H
#define	DRWIDS_H

#include "rWid_old.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
enum TWIDS_ID {
    T_drWid,
    T_drDock,
    T_drJog,
    T_drPlay,
    T_drLoop,
    T_drCue,
    T_drWavnav,
    T_drDepitch,
    T_drXfader,
    T_drGain,
    T_drVol,
    T_drWavmove,
    T_drPlaylist,
    NB_TWIDS
};    

    DR_WID_CB_DECL(drDock);
    DR_WID_CB_DECL(drJog);
    DR_WID_CB_DECL(drPlay);
    DR_WID_CB_DECL(drLoop);
    DR_WID_CB_DECL(drCue);
    DR_WID_CB_DECL(drWavnav);
    DR_WID_CB_DECL(drDepitch);
    DR_WID_CB_DECL(drXfader);
    DR_WID_CB_DECL(drGain);
    DR_WID_CB_DECL(drVol);
    DR_WID_CB_DECL(drWavmove);
    DR_WID_CB_DECL(drPlaylist);


#ifdef	__cplusplus
}
#endif

#endif	/* DRWIDS_H */


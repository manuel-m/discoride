#include <string.h>
#include <float.h>

#include "CUnit.h" 

#include "tests.h"
#include "rUi.h"
#include "drWids.h"

extern drUi_t* g_ui;


enum WIDS_ID {
    DOCK_LEFT_0,
    JOG_LEFT_0,
    NB_WIDS
};

static drWid_t ___twids[NB_WIDS] = {
    
    DR_WID_BIND(drDock,DOCK_LEFT,0,-1,0.0f,0.0f,0.33f,0.39f,RFLAG_VISIBLE | RFLAG_FOCUS),
    DR_WID_BIND(drJog,JOG_LEFT,0,DOCK_LEFT_0,0.27f,0.05f,0.5f,0.7f,RFLAG_VISIBLE )

};



static drWids_t ___wids = {
    .n = NB_WIDS,
    .t = ___twids
};

void TEST_drUi_load() {

    drUiMod_t modDummy;
    memset(&modDummy, 0, sizeof (drUiMod_t));

    CU_ASSERT(0 == drUi_init(&modDummy));
    CU_ASSERT(0 == g_ui->wids);


    CU_ASSERT(0 == drUi_load(&___wids));
    CU_ASSERT(0 != g_ui->wids->t);
    CU_ASSERT(NB_WIDS == g_ui->wids->n);


}

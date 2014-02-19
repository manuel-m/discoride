#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*     display                                                              */
/* -------------------------------------------------------------------------*/
void rdisplay_config(void)
{
  /*
     rval_set( rdh_ruint32, window_bg_color, 0xFF000000);
     rval_set( rdh_int, window_mode, RDISPLAY_WINDOW );
     rrstrcpy( rdh_char255, window_caption, "discoride AAA");
     rval_set(  rdh_double, global_font_coef, 1.0 );
     rval_set( rdh_int, display_state, rnormal );
   */



/* -------------------------------------------------------------------------*/
/*     rdata_sync_cbs                                                       */
/* -------------------------------------------------------------------------*/
/*rsync_add( rdh_char255, window_caption, rdisplay_window_caption,  0 );*/
/* -------------------------------------------------------------------------*/
/*     keys                                                                 */
/* -------------------------------------------------------------------------*/
  rkey_register_down( RKEY_ESC, rdisplay_key_quit, display_state );

  /*rkey_register_down( SDLK_F11, rdisplay_window_mode_toggle, display_state );*/
}
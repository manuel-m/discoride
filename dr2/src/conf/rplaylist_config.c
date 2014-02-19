#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_config(void)
{


/* -------------------------------------------------------------------------*/
/* widgets                                                                  */
/* -------------------------------------------------------------------------*/



/* -------------------------------------------------------------------------*/
/*     keys                                                                 */
/* -------------------------------------------------------------------------*/
  rkey_register_down( RKEY_PAGEDOWN, rplaylist_key_pgdown, playlist_state );
  rkey_register_down( RKEY_PAGEUP, rplaylist_key_pgup, playlist_state );
  rkey_register_down( RKEY_UP, rplaylist_key_down, playlist_state );
  rkey_register_down( RKEY_DOWN, rplaylist_key_up, playlist_state );

}



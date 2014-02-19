#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rkey_init_up( const int code,
                   void (*f_run)(void),
                   rdh_int* state_dh )
{
  R_ASSERT_ERROR( f_run )
  R_ASSERT_ERROR( state_dh )
  R_ASSERT_ERROR( code < RK_LAST )

  rattr( keys ).keys_up[code].f_run = f_run;
  rattr( keys ).keys_up[code].state_dh = state_dh;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rkey_init_down( const int code,
                     void (*f_run)(void),
                     rdh_int* state_dh )
{
  R_ASSERT_ERROR( f_run )
  R_ASSERT_ERROR( state_dh )
  R_ASSERT_ERROR( code < RK_LAST )

  rattr( keys ).keys_down[code].f_run = f_run;
  rattr( keys ).keys_down[code].state_dh = state_dh;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rkey_down_evt(int kindex)
{
  rkey* key = &((rattr( keys )).keys_down[kindex]);

  if ( key->f_run && ( key->state_dh->value > rdisabled ) ) {
    key->f_run();
  }
#ifdef DEBUG
  else{
    R_LOG_INFO("key is disabled")
  }
#endif
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rkey_up_evt(int kindex)
{
  rkey* key =  &((rattr( keys )).keys_up[kindex]);

  if ( key->f_run && ( key->state_dh->value > rdisabled ) ) {
    key->f_run();
  }
}

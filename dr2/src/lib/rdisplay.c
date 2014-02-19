#include "rstack_proxy.h"


RLIST_IMPL( rlspoll_cb, rpoll_cb )


/*========================================================================
 * rdisplay_mainloop_cb_add
 *
 *
 *========================================================================*/
void rdisplay_mainloop_cb_add(int* state, void (*f_action)(void))
{
  rlspoll_cb* ls = &(rattr(poll_cbs));
  rpoll_cb* pc = R_CALLOC( 1, sizeof( rpoll_cb ) );

  pc->state = state;
  pc->f_action = f_action;
  rlspoll_cb_add( ls, pc );
}

/*========================================================================
 * rdisplay_poll_user_evts
 *
 *
 *========================================================================*/
void rdisplay_poll_user_evts( void )
{
  ruser_evtQ* Q = &(rattr(user_evtQ));
  size_t i;

  rmutex_stack_lock( user_evts_mutex );

  for (i = 0; i < Q->len; i++) {
    Q->f_evts[i]();
    Q->f_evts[i] = NULL;
  }
  Q->len = 0;

  rmutex_stack_unlock( user_evts_mutex );
}

/*========================================================================
 * rdisplay_poll_cbs
 *
 *
 *========================================================================*/
void rdisplay_poll_cbs( void )
{
  rlspoll_cb* ls = &(rattr(poll_cbs));
  rlspoll_cb_iterator iter;
  rpoll_cb* poll_cb = rlspoll_cb_first( &iter, ls );

  while (poll_cb) {

    if (*(poll_cb->state)) {
      poll_cb->f_action();
    }
    poll_cb = rlspoll_cb_next( &iter );
  }
}


/*========================================================================
 * rdisplay_ratio_compute
 *
 *
 *========================================================================*/
void rdisplay_ratio_compute(void)
{
  double lratio, lratio_width, lratio_height;

  if ( (( rval_get( window_mode ) ) == RDISPLAY_FULLSCREEN) ) {

    lratio_width =  (double)( rval_get( desktop_width ) ) / (double)( rattr( design_width ) );
    lratio_height = (double)( rval_get( desktop_height ) ) / (double)( rattr( design_height ) );

  } else {

    lratio_width =   (double)( rval_get( window_width ) ) / (double)( rattr( design_width ) );
    lratio_height = (double)( rval_get( window_height ) ) / (double)( rattr( design_height ) );

  }
  lratio = R_MIN( lratio_width, lratio_height);

  rval_set( rdh_double, ratio_width, lratio_width);
  rval_set( rdh_double, ratio_height, lratio_height);
  rval_set( rdh_double, ratio, lratio);

  /* styles refresh */
  {
    rlsstyle_iterator iter;
    rlsstyle* ls = &( rattr( styles ) );
    rstyle* style = rlsstyle_first( &iter, ls );
    while (style) {
      rstyle_refresh( style, lratio, lratio_width, lratio_height);
      style = rlsstyle_next( &iter );
    }
  }

  /* wid ratio/blit */
  {
    rlswid_iterator iter;
    rlswid* ls = &( rattr( wids ) );
    rwid* wid = rlswid_first( &iter, ls );
    while (wid) {

      /* [!] wid list shall sorted with parents first */
      rwid_bb_compute( wid );
      wid = rlswid_next( &iter );
    }
  }
}
/*========================================================================
 * rdisplay_key_quit
 *========================================================================*/
void rdisplay_key_quit(void)
{
  rval_set( rdh_int, quit, 1 );
}







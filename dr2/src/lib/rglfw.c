#include "rstack_proxy.h"

/*========================================================================
 * rglfw_redraw_all
 *
 *
 *========================================================================*/
static void rglfw_redraw_all(void)
{
  rlswid_iterator iter;
  rlswid* ls = &(rattr( wids ));
  rwid* wid = rlswid_first( &iter, ls );

  while (wid) {
    wid->f_draw(wid);
    wid = rlswid_next( &iter );
  }
  wid = rlswid_first( &iter, ls );
  while (wid) {
    wid->f_retrigger(wid);
    wid = rlswid_next( &iter );
  }
}
/*========================================================================
 * rglfw_rescale
 *
 *
 *========================================================================*/
static void rglfw_rescale(void)
{
  rlswid_iterator iter;
  rlswid* ls = &(rattr( wids ));
  const int w = rval_get( window_width);
  const int h = rval_get( window_height);
  GLsizei tex_len = 0;

  /* iter on wids to evaluate tex len */
  {
    rwid* wid = rlswid_first( &iter, ls );
    while ( wid ) {
      tex_len += (GLsizei)wid->textures.len;
      wid = rlswid_next( &iter );
    }
  }

  rdisplay_ratio_compute();
  glViewport( 0, 0, w, h );

  /* Select and setup the projection matrix */
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h );
  glMatrixMode(GL_MODELVIEW);

  /* iter on wids to realloc tex to fit new size */
  {
    rwid* wid = rlswid_first( &iter, ls );
    /*size_t tex_id_offset = 0;*/

    while ( wid ) {
      rwid_texalloc(wid);
      wid = rlswid_next( &iter );
    }
  }
}
/*========================================================================
 * resize_callback
 *
 *
 *========================================================================*/
static void rglfw_window_resize_cb(int w, int h)
{
  glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
  glClear( GL_COLOR_BUFFER_BIT );

  rval_set( rdh_int, window_width, w);
  rval_set( rdh_int, window_height, h);

  rtimer_stack_cpy(  lag_resize, current );

  rattr( check_resize ) = 1;

  /* 0.4 sec */
  rtimer_stack_add_nano( lag_resize, 400000000L );

}
/*========================================================================
 * rglfw_mouse_cb
 *
 *
 *========================================================================*/
static void rglfw_mouse_cb(int button_id, int button_state )
{
  rlswid_iterator iter;
  rlswid* list = &(rattr( cwids ));
  rwid* wid = rlswid_last( &iter, list );

  /* mouse clic */
  while ( wid ) {
    if ( rwid_state_get( wid ) > rdisabled ) {
      if ( R_INSIDE(rattr(mouse_x), rattr(mouse_y), *wid )  ) {
        wid->f_clic_handler(wid, button_id, button_state);
        return;
      }
    }
    wid = rlswid_previous( &iter );
  }
}
/*========================================================================
 * rglfw_key_cb
 *
 *
 *========================================================================*/
static void rglfw_key_cb(int key_code, int key_state )
{
  rkey* key = &((rattr( keys )).keys_down[key_code]);

  if ( key_state != GLFW_PRESS) {
    return;
  }

  if ( key->f_run && ( key->state_dh->value > rdisabled ) ) {
    key->f_run();
  }
#ifdef DEBUG
  else{
    R_LOG_INFO("key is disabled")
  }
#endif
}
/*========================================================================
 * rglfw_mouse_wheel_cb
 *
 *
 *========================================================================*/
static void rglfw_mouse_wheel_cb(int wheel )
{
  rwid* over = rattr( rwid_over );

  if ( over  ) {
    if (wheel > rattr(mouse_wheel)  ) {
      rattr(mouse_wheel) = wheel;

      if ( over->f_fire_wheel_up ) {
        over->f_fire_wheel_up( over->wdata );
        return;
      }
      if ( over->f_wheel_up ) {
        over->f_wheel_up( over );
      }
    }else {
      if (wheel < rattr(mouse_wheel)  ) {
        rattr(mouse_wheel) = wheel;
        if ( over->f_fire_wheel_down ) {
          over->f_fire_wheel_down( over->wdata );
          return;
        }
        if ( over->f_wheel_down ) {
          over->f_wheel_down( over );
        }
      }
    }
  }
}
/*========================================================================
 * mouse_move_callback
 *
 *
 *========================================================================*/
static void rglfw_mouse_move_cb(int x, int y )
{
  rlswid_iterator iter;
  rlswid* list = &(rattr( cwids ));
  rwid* wid = rlswid_last( &iter, list );
  rwid* wid_found = NULL;
  int flip_y = rval_get( window_height ) - y;

  rattr(mouse_x) = x;
  rattr(mouse_y) = rval_get( window_height ) - y;

  /* wid found */
  while ( wid && !wid_found ) {
    if ( R_INSIDE(x, flip_y, *wid ) ) {
      wid_found = wid;
    }
    wid = rlswid_previous( &iter );
  }

  /**************/
  /* focus out  */
  /**************/
  if ( rattr( rwid_over ) != wid_found ) {

    rwid* wid_over = rattr( rwid_over );

    /* focus out callback */
    if ( wid_over ) {
      if (  wid_over->f_fire_over_out  ) {
        wid_over->f_fire_over_out( wid_over->wdata );
      }

      /* autofocus unset */
      if ( wid_over->render_spec & R_AUTO_FOCUS ) {
        rdh_int_set(&(wid_over->focus_dh), 0);
      }
    }
    /**************/
    /* focus in   */
    /**************/
    rattr( rwid_over ) = wid_found;

    if ( wid_found  && rwid_state_get( wid_found ) > rdisabled ) {

      /* fire cb if exists */
      if ( wid_found->f_fire_over_in ) {
        wid_found->f_fire_over_in( wid_found->wdata );
      }

      /* autofocus set */
      if ( wid_found->render_spec & R_AUTO_FOCUS ) {
        rdh_int_set(&(wid_found->focus_dh), 1);
      }
    }
  }
}
/*========================================================================
 * rglfw_init
 *
 *
 *========================================================================*/
void rglfw_init(void)
{
  int w, h;

  rtime_init;

  if ( !glfwInit() ) {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    exit( EXIT_FAILURE );
  }

  /* Open a window and create its OpenGL context */
  if ( !glfwOpenWindow( 640, 480, 0, 0, 0, 0, 0, 0, GLFW_WINDOW ) ) {
    glfwTerminate();
    exit( EXIT_FAILURE );
  }
  glfwGetWindowSize( &w, &h  );
  rval_set( rdh_int, window_width, w);
  rval_set( rdh_int, window_height, h);

  glfwSetMouseButtonCallback( rglfw_mouse_cb );
  glfwSetKeyCallback( rglfw_key_cb );
  glfwSetWindowSizeCallback( rglfw_window_resize_cb );
  glfwSetMousePosCallback( rglfw_mouse_move_cb );
  glfwSetMouseWheelCallback( rglfw_mouse_wheel_cb );

  /* disable unuseful */
  glDisable(GL_DEPTH_TEST);
  glDepthMask(GL_FALSE);
  glDisable( GL_LIGHTING );
  glDisable( GL_DITHER );

  glfwSetWindowTitle( "dr2" );

  /* Ensure we can capture the escape key being pressed below */
  glfwEnable( GLFW_STICKY_KEYS );

  /* Enable vertical sync (on cards that support it) */
  glfwSwapInterval( 1 );

  /* work around =>  glfwSetWindowSizeCallback is called during display init */
  rattr( check_resize ) = 0;
}
/*========================================================================
 * rglfw_push_event
 *
 *
 *========================================================================*/
void rglfw_push_evt(  void (*f_evt)(  void ) )
{
  ruser_evtQ* Q = &(rattr(user_evtQ));

  rmutex_stack_lock( user_evts_mutex );

  R_ASSERT_ERROR( Q->len < (RMAX_EVTS_Q - 1) )
  R_ASSERT_ERROR( f_evt )
  Q->f_evts[Q->len] = f_evt;
  Q->len++;

  rmutex_stack_unlock( user_evts_mutex );
}

/*========================================================================
 * M A I N    L O O P
 *
 *
 *========================================================================*/
void rglfw_mainLoop(void)
{
  /* ===[ first rescale ] ===================*/
  {
    int w, h;
    glfwGetWindowSize( &w, &h );
    rval_set( rdh_int, window_width, w);
    rval_set( rdh_int, window_height, h);
    rattr( resize_flag ) = 1;
    rglfw_rescale( );
  }

  while ( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
          glfwGetWindowParam( GLFW_OPENED ) ) {

    /* ===[ refresh current time ] ==========*/
    rtimer* tcur = &(rtimer_stack_get( current ));
    rtimer* tlag_resize = &(rtimer_stack_get( lag_resize ));
    rtimer_set_current_time( tcur );

    /* ===[ check_resize ] ==================*/
    if ( (rattr( check_resize )) ) {
      if (  (tcur->sec > tlag_resize->sec)
            ||
            (( tcur->sec == tlag_resize->sec)
             && ( tcur->nsec > tlag_resize->nsec) )  ) {

        rattr( resize_flag ) = 1;
        rglfw_rescale( );
        rattr( check_resize ) = 0;
      }
    }

    raudio_save_depitch_context();

    rcpu_update();

    /* from external threads */
    rdisplay_poll_user_evts();

    /* cb registered and activated  */
    rdisplay_poll_cbs();

    /* no redraw during resize */
    if ( !rattr( check_resize )  ) rglfw_redraw_all();

    glfwSwapBuffers();
    rattr( resize_flag ) = 0;


  }                  /* while( !quit ) */
  glfwTerminate();
}



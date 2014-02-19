#ifndef __RGLU_H__
#define __RGLU_H__

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rdata.h"

/*********************************/
/*    attr                      */
/*********************************/
#define rattr( NAME ) btin._attr_ ## NAME
#define rattrib_declare( TYPE, NAME ) TYPE _attr_ ## NAME;

/*********************************/
/*    datas                      */
/*********************************/
#define rdh_declare( TYPE, DATA ) TYPE _ ## DATA ## _dh;
#define rdh_addr( DATA ) & (btin._ ## DATA ## _dh )
#define rval_get( DATA ) btin._ ## DATA ## _dh.value
#define rval_changed( DATA ) btin._ ## DATA ## _dh.changed

#define rval_set(ALIAS, DATA, VALUE) ALIAS ## _set( rdh_addr( DATA ), VALUE )
#define rrstrcpy(ALIAS, DATA, VALUE) ALIAS ## _strcpy( rdh_addr( DATA ), VALUE )

#define rinit(ALIAS, DATA, VALUE) ALIAS ## _init( rdh_addr( DATA ), VALUE )
#define rreinit(ALIAS, DATA) ALIAS ## _reinit( rdh_addr( DATA ) )

#define rcpy(ALIAS, DATA, VALUE) ALIAS ## _cpy( rdh_addr( DATA ), VALUE )

/*********************************/
/*    key                        */
/*********************************/
#define rkey_register_up( KEY_CODE, F_RUN, STATE ) \
  rkey_init_up( KEY_CODE, F_RUN, rdh_addr( STATE ) )

#define rkey_register_down( KEY_CODE, F_RUN, STATE ) \
  rkey_init_down( KEY_CODE, F_RUN, rdh_addr( STATE ) )

/*********************************/
/*    automation                 */
/*********************************/
/* [!] only for rdh_double ...*/
/*
   #define rautomation( DATA, DURATION, PERIOD ) \
   rdh_double_automation_init(rdh_addr( DATA ), &(rval_get( DATA )), DURATION, PERIOD)

   #define rautomation_start( ALIAS, DATA, TARGET ) \
   ALIAS ## _automation_start( rdh_addr( DATA ),  TARGET )

   #define rautomation_stop( ALIAS, DATA ) \
   ALIAS ## _automation_stop( rdh_addr( DATA ) )

   #define rautomation_isactive( ALIAS, DATA ) \
   ALIAS ## _automation_isactive( rdh_addr( DATA ) )
 */

/*========================================================================
 * T H R E A D S
 *
 *
 *========================================================================*/
#define S_SDL_THREAD      (0)
#define S_GLFW_THREAD     (1)
/*========================================================================
 * GLFW threads
 *========================================================================*/
#if S_GLFW_THREAD
#define rmutex_stack_decl( NAME )  mtx_t mux_ ## NAME;
#define rmutex_stack_init( NAME ) mtx_init(&(btin.mux_ ## NAME), mtx_plain)
#define rmutex_stack_lock( NAME ) mtx_lock( &(btin.mux_ ## NAME) )
#define rmutex_stack_unlock( NAME ) mtx_unlock( &(btin.mux_ ## NAME) )
#define rmutex_stack_destroy( NAME )  mtx_destroy( &(btin.mux_ ## NAME) )

#define rthread_stack_declare( NAME )  thrd_t thr_ ## NAME;
#define rthread_stack_create( NAME ) thrd_create(&(btin.thr_ ## NAME), NAME, (void*)0)

#define rtimer_stack_declare( NAME ) xtime xt_ ## NAME;
#define rtimer_stack_get( NAME ) btin.xt_ ## NAME
#define rtimer_set_current_time( TIMER ) xtime_get( (TIMER), TIME_UTC  )
#define rtimer xtime
#define rtime_init glfwSetTime( 0 )

#define rtimer_cpy( TDEST, TSRC ) (TDEST)->sec = (TSRC)->sec; (TDEST)->nsec = (TSRC)->nsec
#define rtimer_add_nano( TIMER, NANO ) \
  { \
    (TIMER)->nsec += NANO; \
    if ((TIMER)->nsec >= 1000000000L) { (TIMER)->sec++; (TIMER)->nsec -= 1000000000L; } \
  }

#define rtimer_add_milli( TIMER, MILLI ) \
  { \
    (TIMER)->nsec += (MILLI * 1000000); \
    if ((TIMER)->nsec >= 1000000000L) { (TIMER)->sec++; (TIMER)->nsec -= 1000000000L; } \
  }

#define rtimer_stack_add_nano( TIMER, NANO ) \
  { \
    (rtimer_stack_get(TIMER)).nsec += NANO; \
    if ((rtimer_stack_get(TIMER)).nsec >= 1000000000L) { \
      (rtimer_stack_get(TIMER)).sec++; \
      (rtimer_stack_get(TIMER)).nsec -= 1000000000L; } \
  }

#define rtimer_stack_cpy( TDEST, TSRC ) \
  { \
    (rtimer_stack_get(TDEST)).sec = (rtimer_stack_get(TSRC)).sec; \
    (rtimer_stack_get(TDEST)).nsec = (rtimer_stack_get(TSRC)).nsec; \
  }

#define rtimer_delta_sec( T1, T2 ) \
  (-( ((T2)->sec - (T1)->sec) * 1000000L + ((T2)->nsec - (T1)->nsec + 500L) / 1000L ) / 1000000.0 )

#endif
/*========================================================================
 * SDL threads
 *========================================================================*/
#if S_SDL_THREAD
#include <SDL/SDL.h>
#define rmutex_stack_decl( NAME )  SDL_mutex *  m_ ## NAME;
#define rmutex_stack_init( NAME ) btin.m_ ## NAME  = SDL_CreateMutex();
#define rmutex_stack_lock( NAME ) SDL_mutexP( btin.m_ ## NAME );
#define rmutex_stack_unlock( NAME ) SDL_mutexV( btin.m_ ## NAME );
#define rmutex_stack_destroy( NAME )
#define rthread_stack_declare( NAME )
#define rthread_stack_create( NAME ) SDL_CreateThread( NAME, (void*)0)

#define rtimer_stack_declare( NAME )
#define rtimer_stack_get( NAME )
#define rtimer_stack_set_current_time( NAME )
#define rtimer
#endif
/*========================================================================
 * alias
 *
 *
 *========================================================================*/
#define rdisplay_init rglfw_init
#define rdisplay_mainLoop rglfw_mainLoop

#define RKEY_SPACE GLFW_KEY_SPACE
#define RKEY_ESC GLFW_KEY_ESC
#define RKEY_F1 GLFW_KEY_F1
#define RKEY_F2 GLFW_KEY_F2
#define RKEY_F3 GLFW_KEY_F3
#define RKEY_F4 GLFW_KEY_F4
#define RKEY_F5 GLFW_KEY_F5
#define RKEY_F6 GLFW_KEY_F6
#define RKEY_F7 GLFW_KEY_F7
#define RKEY_F8 GLFW_KEY_F8
#define RKEY_F9 GLFW_KEY_F9
#define RKEY_F10 GLFW_KEY_F10
#define RKEY_F11 GLFW_KEY_F11
#define RKEY_F12 GLFW_KEY_F12
#define RKEY_UP GLFW_KEY_UP
#define RKEY_DOWN GLFW_KEY_DOWN
#define RKEY_LEFT GLFW_KEY_LEFT
#define RKEY_RIGHT GLFW_KEY_RIGHT
#define RKEY_LSHIFT GLFW_KEY_LSHIFT
#define RKEY_RSHIFT GLFW_KEY_RSHIFT
#define RKEY_LCTRL GLFW_KEY_LCTRL
#define RKEY_RCTRL GLFW_KEY_RCTRL
#define RKEY_LALT GLFW_KEY_LALT
#define RKEY_RALT GLFW_KEY_RALT
#define RKEY_LSUPER GLFW_KEY_LSUPER
#define RKEY_RSUPER GLFW_KEY_RSUPER
#define RKEY_TAB GLFW_KEY_TAB
#define RKEY_ENTER GLFW_KEY_ENTER
#define RKEY_BACKSPACE GLFW_KEY_BACKSPACE
#define RKEY_INSERT GLFW_KEY_INSERT
#define RKEY_DEL GLFW_KEY_DEL
#define RKEY_PAGEUP GLFW_KEY_PAGEUP
#define RKEY_PAGEDOWN GLFW_KEY_PAGEDOWN
#define RKEY_HOME GLFW_KEY_HOME
#define RKEY_END GLFW_KEY_END
#define RKEY_KP_0 GLFW_KEY_KP_0
#define RKEY_KP_1 GLFW_KEY_KP_1
#define RKEY_KP_2 GLFW_KEY_KP_2
#define RKEY_KP_3 GLFW_KEY_KP_3
#define RKEY_KP_4 GLFW_KEY_KP_4
#define RKEY_KP_5 GLFW_KEY_KP_5
#define RKEY_KP_6 GLFW_KEY_KP_6
#define RKEY_KP_7 GLFW_KEY_KP_7
#define RKEY_KP_8 GLFW_KEY_KP_8
#define RKEY_KP_9 GLFW_KEY_KP_9
#define RKEY_KP_DIVIDE GLFW_KEY_KP_DIVIDE
#define RKEY_KP_MULTIPLY GLFW_KEY_KP_MULTIPLY
#define RKEY_KP_SUBTRACT GLFW_KEY_KP_SUBTRACT
#define RKEY_KP_ADD GLFW_KEY_KP_ADD
#define RKEY_KP_DECIMAL GLFW_KEY_KP_DECIMAL
#define RKEY_KP_EQUAL GLFW_KEY_KP_EQUAL
#define RKEY_KP_ENTER GLFW_KEY_KP_ENTER
#define RKEY_KP_NUM_LOCK GLFW_KEY_KP_NUM_LOCK
#define RKEY_CAPS_LOCK GLFW_KEY_CAPS_LOCK
#define RKEY_SCROLL_LOCK GLFW_KEY_SCROLL_LOCK
#define RKEY_PAUSE GLFW_KEY_PAUSE
#define RKEY_MENU GLFW_KEY_MENU





#endif /*__RGLU_H__*/
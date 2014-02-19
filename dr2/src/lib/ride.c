#include "ride.h"

#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rargs(int argc, char **argv)
{
  rlschar255* ls;
  rchar255* char255;

  if (argc > 0) {
    size_t argc_size = (size_t)argc;

    /* args  init */
    rlschar255_init( &(rattr( args )), argc_size, 1);
    ls = &(rattr( args ));

    while (argc--) {
      char255 = R_CALLOC( 1, sizeof( rchar255 ) );
      strcpy( char255[0], *argv++);
      R_LOG_INFO( char255[0] );
      rlschar255_add( ls, char255);
    }
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rpreinit(void)
{
  R_CLEAR_NO_CHECK( &btin, rbtin );
  rproxy_init();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rclose(void)
{
  rproxy_destroy();
}
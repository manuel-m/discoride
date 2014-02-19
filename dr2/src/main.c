#include "ride.h"


/* -------------------------------------------------------------------------*/
/*                                                                          */
/* -------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  R_LOG_INFO("debug version")

  rpreinit();
  rstyle_preinit();
  rargs( argc, argv );

  rdisplay_init();

  rdisplay_config();

  rstyle_config();

  raudio_config();
  rplaylist_init();
  rplaylist_config();

  rpanels();

  raudio_init();
  raudio_playlist_populate();

  /*rattr( alloc_disable ) = 1; */    /* disable allocation */

  rdisplay_mainLoop();

  raudio_close( );

  rclose();
  return 0;
}

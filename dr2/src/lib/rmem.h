#ifndef __RMEM_H__
#define __RMEM_H__

/*********************************/
/*    standard includes          */
/*********************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>
#include <time.h>
#include <execinfo.h>

#define R_CLEAR( P, TYPE ) if ( (P) ) { memset(P, 0, sizeof( TYPE )); }
#define R_CLEAR_NO_CHECK( P, TYPE ) memset(P, 0, sizeof( TYPE ))

#ifdef DEBUG

void *r_calloc_dbg(size_t nmemb, size_t size);
void *r_malloc_dbg(size_t size);
void *r_realloc_dbg(void *ptr, size_t size);

#define R_CALLOC( NMEMB, SIZE ) r_calloc_dbg( NMEMB, SIZE )
#define R_REALLOC( PTR, SIZE ) r_realloc_dbg( PTR, SIZE )

#else

#define R_CALLOC( NMEMB, SIZE ) calloc( NMEMB, SIZE )
#define R_REALLOC( PTR, SIZE ) realloc( PTR, SIZE )

#endif




#endif /*__RMEM_H__*/

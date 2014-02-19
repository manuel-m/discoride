#ifndef __RSTL_H__
#define __RSTL_H__

#include "rstd_defines.h"
#include "rmem.h"

/* -------------------------------------------------------------------------*/
/* callbacks types                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
typedef int (*f_cmp)(const void*, const void* );

/* -------------------------------------------------------------------------*/
/* map                                                                      */
/*                                                                          */
/* -------------------------------------------------------------------------*/
typedef struct _rmap {
  void ***index;
  void **data;
  size_t len;
  size_t maxlen;
} rmap;

rmap*  rmap_new(const size_t max);
rmap*  rmap_clone(rmap* in);
void rmap_cpy(rmap *out, rmap *in);
size_t rmap_getLen(const rmap *map);
size_t rmap_getMaxLen(const rmap *map);
int rmap_set(rmap *map, const size_t key, void* data);
void* rmap_get(const rmap *map, const size_t key);
int rmap_add(rmap *map, void* data);
void* rmap_next(rmap *map, size_t* index);

/* -------------------------------------------------------------------------*/
/* vect                                                                     */
/*                                                                          */
/* -------------------------------------------------------------------------*/
typedef struct _rvect {
  void** addrs;
  size_t len;
  size_t maxlen;
} rvect;

void rvect_init( rvect* vect, void** addrs, const size_t maxlen );
void rvect_push( rvect* vect, void* addr );
void* rvect_pop( rvect* vect );
void* rvect_get( rvect* vect, void* data,  f_cmp cmp );
void* rvect_next( rvect* vect, int* index );
void* rvect_previous( rvect* vect, size_t* index );
int rvect_is_something( const rvect* vect );
#define rvect_exe( VECT, F_EXE, DATA ) \
  { \
    size_t i = VECT->len; \
    while (--i) F_EXE( vect->addrs[i], data); \
  }
/*========================================================================
 * strings
 *
 *
 *========================================================================*/
void rstrcpy_ASCII(char *dest, const char *src);


#endif /*__RSTL_H__*/

#include "rstl.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rmap* rmap_clone(rmap* in)
{
  size_t maxlen;
  size_t len;
  rmap * out;
  size_t i;

  R_ASSERT_ERROR( in );

  maxlen = in->maxlen;
  len = in->len;
  out =  rmap_new(maxlen);

  for (i = len; i; --i) {
    out->index[i] = in->index[i];
    out->data[i] = in->data[i];
  }
  out->len = len;

  return out;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rmap_cpy(rmap *out, rmap *in) /*to check*/
{
  size_t len;
  size_t i;

  R_ASSERT_ERROR( in );
  R_ASSERT_ERROR( out );
  R_ASSERT_ERROR( out->maxlen >= in->len );

  len = in->len;
  out->len = in->len;

  for (i = len; i; --i) {
    out->index[i] = in->index[i];
    out->data[i] = in->data[i];
  }
  out->len = len;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rmap* rmap_new(const size_t maxlen)
{
  rmap * out;
  size_t mx;

  R_ASSERT_ERROR( maxlen );
  out = R_CALLOC( 1, sizeof(rmap) );
  out->maxlen = maxlen;
  out->len = 0;
  mx = maxlen + 1;
  out->data = R_CALLOC( mx, sizeof(void*));
  out->index = R_CALLOC( mx, sizeof(void**));
  return out;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
size_t rmap_getLen(const rmap *map)
{
  R_ASSERT_ERROR( map );
  return map->len;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
size_t rmap_getMaxLen(const rmap *map)
{
  R_ASSERT_ERROR( map );
  return map->maxlen;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rmap_set(rmap *map, const size_t key, void* data)
{
  void **pdata;

  R_ASSERT_ERROR( map );
  if ( key >= map->maxlen ) {
    return 0;
  }
  pdata = map->index[key];
  if (!pdata) {
    map->data[map->len] = data;
    map->index[key] = &(map->data[map->len]);
    map->len++;
  } else {
    *pdata = data;
  }
  return 1;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rmap_add(rmap *map, void* data)
{
  size_t key;

  R_ASSERT_ERROR( map );
  R_ASSERT_ERROR( data );

  if ( map->maxlen <= map->len) {
    return 0;
  }
  key = map->len;
  map->data[key] = data;
  map->index[key] = &(map->data[key]);
  map->len++;

  return 1;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rmap_get(const rmap *map, const size_t key)
{
  void **pdata;

  R_ASSERT_ERROR( map );

  if ( key >= map->maxlen  ) {
    return NULL;
  }

  pdata = map->index[key];

  if (pdata) {
    return *pdata;
  }
  return NULL;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rmap_next(rmap *map, size_t* i)
{
  R_ASSERT_ERROR( map );
  R_ASSERT_ERROR( i );
  R_ASSERT_ERROR( (map->maxlen >= map->len) );
  if (map->len > *i) {
    return map->data[(*i)++];
  }
  return NULL;
}
/* -------------------------------------------------------------------------*/
/* vect                                                                     */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rvect_init( rvect* vect,
                 void** addrs,
                 const size_t maxlen )
{
  size_t mx;

  vect->len = 0;
  vect->maxlen = maxlen;
  vect->addrs = addrs;
  mx = maxlen;
  memset(vect->addrs, 0, sizeof(void*) * mx);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rvect_push( rvect* vect, void* addr )
{
  R_ASSERT_ERROR( vect->len < vect->maxlen );
  vect->addrs[vect->len++] = addr;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rvect_get( rvect* vect, void* data,  f_cmp cmp  )
{
  size_t i;

  R_ASSERT_ERROR( vect );
  R_ASSERT_ERROR( data );
  R_ASSERT_ERROR( cmp );

  for (i = 0; i < vect->len; i++) {
    void* addr = vect->addrs[i];
    if ( !cmp( addr, data )  ) {
      return addr;
    }
  }
  return 0;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rvect_pop( rvect* vect )
{
  if ( vect->len ) {
    return vect->addrs[--vect->len];
  }
  return 0;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rvect_next( rvect* vect, int* i )
{
  R_ASSERT_ERROR( vect );
  R_ASSERT_ERROR( i );
  return vect->addrs[*i++]; /*to check*/
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void* rvect_previous( rvect* vect, size_t* i )
{
  R_ASSERT_ERROR( vect );
  R_ASSERT_ERROR( i );
  return vect->addrs[*i--]; /*to check*/
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rvect_is_something( const rvect* vect )
{
  return (vect->len > 0);
}
/*========================================================================
 * rstrcpy_ASCII
 *
 *
 *========================================================================*/
void rstrcpy_ASCII(char *dest, const char *src)
{
  R_ASSERT_ERROR( dest )
  R_ASSERT_ERROR( src )

  /*
     if(strlen( dest ) < strlen( src )){
     strncpy( dest, src, sizeof( dest) );
     }else
     {
     strcpy( dest, src );
     }
   */
  strcpy( dest, src );


  {
    size_t i;
    for (i = 0; i < strlen(dest); i++) {
      if ( (dest[i] < ' ') || (dest[i] > '~' ) ) {
        dest[i] = ' ';
      }
    }
  }
}








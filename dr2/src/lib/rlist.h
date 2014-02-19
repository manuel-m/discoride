#ifndef __RLIST_H__
#define __RLIST_H__

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rstd_defines.h"
#include "rmem.h"

/*********************************/
/*    macros                     */
/*********************************/
#define RLIST_DECL( NAME, TYPE ) \
  typedef struct _ ## NAME { \
    TYPE **data; \
    size_t len; \
    size_t maxlen; \
    size_t step; \
    int valid; \
  } NAME; \
  typedef struct _ ## NAME ## _iterator { \
    NAME *ls; \
    size_t index; \
  } NAME ## _iterator; \
  NAME* NAME ## _new(const size_t maxlen, const size_t step); \
  void NAME ## _init(NAME * ls, const size_t maxlen, const size_t step); \
  int NAME ## _add(NAME * ls, TYPE * data); \
  TYPE* NAME ## _get(const NAME * ls, const size_t index); \
  TYPE* NAME ## _first(NAME ## _iterator * iterator, NAME * ls); \
  TYPE* NAME ## _next(NAME ## _iterator * iterator ); \
  TYPE* NAME ## _last(NAME ## _iterator * iterator, NAME * ls); \
  TYPE* NAME ## _previous(NAME ## _iterator * iterator); \
  TYPE* NAME ## _rotate(NAME ## _iterator * iterator); \
  void NAME ## _reverse(NAME * ls); \
  void NAME ## _cpy(NAME * out, NAME * in); \
  void NAME ## _clone(NAME * out, NAME * in); \

RLIST_DECL( rlsfunc, rfunc )
RLIST_DECL( rlschar255, rchar255 )
RLIST_DECL( rlsint, int )

/*********************************/
/*    shorcuts macros            */
/*********************************/
#define rlist_len( PRLS ) PRLS->len
#define rlist_max_len( PRLS ) PRLS->maxlen
#define rlist_is_full( PRLS ) ( ls->len == ls->maxlen )

#define RLIST_IMPL( NAME, TYPE ) \
  void NAME ## _init(NAME * ls, const size_t maxlen, const size_t step) \
  { \
    R_ASSERT_ERROR( ls ); \
    ls->maxlen = maxlen; \
    ls->step = step; \
    ls->len = 0; \
    ls->data = R_CALLOC( maxlen + 1, sizeof(TYPE*) ); \
    ls->valid = 0; \
  } \
  NAME* NAME ## _new(const size_t maxlen, const size_t step) \
  { \
    NAME * ls = R_CALLOC( 1, sizeof( NAME ) ); \
    R_ASSERT_ERROR( step ); \
    NAME ## _init(ls, maxlen, step); \
    return ls; \
  } \
  int NAME ## _add(NAME * ls, TYPE * data) \
  { \
    size_t mx; \
    R_ASSERT_ERROR( ls ); \
    if ( (!ls->maxlen) && ( !ls->step  )) { \
      NAME ## _init(ls, 1, 1); \
    } \
    if ( ls->maxlen <= ls->len ) { \
      mx = ls->maxlen + ls->step; \
      ls->data = R_REALLOC( ls->data,  mx * sizeof( TYPE )  ); \
      if ( !ls->data ) { \
        return 0; \
      } \
      ls->maxlen += ls->step; \
    } \
    ls->data[ls->len] = data; \
    ls->len++; \
    return 1; \
  } \
  TYPE* NAME ## _get(const NAME * ls, const size_t i) \
  { \
    return ( ( i < ls->len   ) ? ls->data[i] : NULL  ); \
  } \
  TYPE* NAME ## _next(NAME ## _iterator * iterator) \
  { \
    R_ASSERT_ERROR( iterator ); \
    R_ASSERT_ERROR( iterator->ls ); \
    if (iterator->ls->len > iterator->index) { \
      return iterator->ls->data[iterator->index++]; \
    } \
    iterator->ls->valid = 0; \
    return NULL; \
  } \
  TYPE* NAME ## _previous(NAME ## _iterator * iterator) \
  { \
    R_ASSERT_ERROR( iterator ); \
    R_ASSERT_ERROR( iterator->ls ); \
    if (iterator->index > 0) { \
      return iterator->ls->data[iterator->index--]; \
    }else{ \
      if (iterator->ls->valid) { \
        iterator->ls->valid = 0; \
        return iterator->ls->data[0]; \
      } \
    } \
    return NULL; \
  } \
  TYPE* NAME ## _first(NAME ## _iterator * iterator, NAME * ls) \
  { \
    R_ASSERT_ERROR( iterator ); \
    R_ASSERT_ERROR( ls ); \
    iterator->ls = ls; \
    if (ls->len) { \
      iterator->index = 1; \
      ls->valid = 1; \
      return ls->data[0]; \
    } \
    return NULL; \
  } \
  TYPE* NAME ## _last(NAME ## _iterator * iterator, NAME * ls) \
  { \
    R_ASSERT_ERROR( iterator ); \
    R_ASSERT_ERROR( ls ); \
    iterator->ls = ls; \
    if (ls->len) { \
      iterator->index = ls->len - 1; \
      ls->valid = 1; \
      return ls->data[iterator->index]; \
    } \
    ls->valid = 0; \
    return NULL; \
  } \
  TYPE* NAME ## _rotate(NAME ## _iterator * iterator) \
  { \
    R_ASSERT_ERROR( iterator ); \
    R_ASSERT_ERROR( iterator->ls ); \
    if (iterator->ls->len <= iterator->index) { \
      iterator->index = 0; \
    } \
    return iterator->ls->data[iterator->index++]; \
  } \
  void NAME ## _cpy(NAME * out, NAME * in) \
  { \
    R_ASSERT_ERROR( in ); \
    R_ASSERT_ERROR( out ); \
    if ( out->maxlen < in->len ) { \
      out->data = R_REALLOC( out->data, ( in->len * sizeof( TYPE ) ) ); \
      R_ASSERT_ERROR( out->data ) \
      out->maxlen = in->len; \
    } \
    out->len = in->len; \
    memcpy(out->data, in->data, ( in->len * sizeof( TYPE ) ) ); \
  } \
  void NAME ## _reverse(NAME * ls) \
  { \
    size_t i; \
    size_t max; \
    size_t len; \
    TYPE* aux; \
    R_ASSERT_ERROR( ls ); \
    len = ls->len - 1; \
    if ( (ls->len % 2) == 0 ) { \
      max = (len + 1) / 2; \
    }else { \
      max = len  / 2; \
    } \
    for (i = 0; i < max; i++) { \
      aux =  ls->data[i]; \
      ls->data[i] = ls->data[len - i]; \
      ls->data[len - i] = aux; \
    } \
    ls->valid = 0; \
  } \
  void NAME ## _clone(NAME * out, NAME * in) \
  { \
    R_ASSERT_ERROR( in ); \
    R_ASSERT_ERROR( out ); \
    if ( out->maxlen < in->len ) { \
      out->data = R_REALLOC( out->data, ( in->len * sizeof( TYPE ) ) ); \
      R_ASSERT_ERROR( out->data ) \
      out->maxlen = in->len; \
    } \
    out->len = in->len; \
    { \
      size_t i; \
      void* new_item; \
      for (i = 0; i < out->len; i++) { \
        new_item = R_CALLOC( 1, sizeof( TYPE ) ); \
        memcpy( new_item, in->data[i], sizeof( TYPE ) ); \
        out->data[i] = ( TYPE* )new_item; \
      } \
    } \
  }


#endif /* __RLIST_H__ */
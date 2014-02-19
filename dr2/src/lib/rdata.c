#include "rdata.h"

/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define RDH_IMPL_PRIMITIF( TYPE, ALIAS ) \
  void ALIAS ## _set( ALIAS * dh, TYPE value) \
  { \
    R_ASSERT_ERROR( dh ) \
    if ( dh->value != value) { \
      dh->changed =  1; \
      dh->value = value; \
    } \
  } \
  void ALIAS ## _init( ALIAS * dh, TYPE value) \
  { \
    R_ASSERT_ERROR( dh ) \
    dh->def =  value; \
    dh->value = value; \
    dh->changed = 1; \
  } \
  void ALIAS ## _reinit( ALIAS * dh ) \
  { \
    R_ASSERT_ERROR( dh ) \
    if (dh->def !=  dh->value) { \
      dh->value = dh->def; \
      dh->changed = 1; \
    } \
  }

#define RDH_IMPL_STRING( TYPE, ALIAS ) \
  void ALIAS ## _strcpy( ALIAS * dh, const char *s) \
  { \
    R_ASSERT_ERROR( dh ) \
    R_ASSERT_ERROR( s ) \
    if ( strcmp( s, &dh->value[0] )) { \
      rstrcpy( dh->value, s); \
      dh->changed = 1; \
    } \
  } \
  void ALIAS ## _init( ALIAS * dh, const char *s) \
  { \
    R_ASSERT_ERROR( dh ) \
    R_ASSERT_ERROR( s ) \
    rstrcpy( dh->def, s); \
    rstrcpy( dh->value, s); \
    dh->changed = 1; \
  } \
  void ALIAS ## _reinit( ALIAS * dh ) \
  { \
    R_ASSERT_ERROR( dh ) \
    if ( strcmp( &dh->def[0], &dh->value[0] )) { \
      rstrcpy( dh->value, &dh->def[0]); \
      dh->changed = 1; \
    } \
  }

#define RDH_IMPL_COMPLEX( TYPE, ALIAS ) \
  void ALIAS ## _cpy( ALIAS * dh, TYPE * addr) \
  { \
    R_ASSERT_ERROR( dh ) \
    R_ASSERT_ERROR( addr ) \
    if ( memcmp( &dh->def[0], &dh->value[0], sizeof( TYPE ) )) { \
      memcpy(&dh->previous, &dh->current, sizeof( TYPE )); \
      dh->changed = 1; \
    } \
  }




RDH_IMPL_PRIMITIF( int, rdh_int )
RDH_IMPL_PRIMITIF( size_t, rdh_size )
RDH_IMPL_PRIMITIF( float, rdh_float )
RDH_IMPL_PRIMITIF( double, rdh_double )
RDH_IMPL_PRIMITIF( ruint32, rdh_uint32 )
RDH_IMPL_STRING( rchar255, rdh_char255 )



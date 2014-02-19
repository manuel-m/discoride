#ifndef __RDATAS_H__
#define __RDATAS_H__

/*********************************/
/*    depedencies includes       */
/*********************************/

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rstl.h"
#include "rlist.h"
#include "tinycthread.h"
/*********************************/
/*    macro                      */
/*********************************/

/*********************************/
/*    set states                 */
/*********************************/
#define RD_PREVIOUS_INVALID      0
#define RD_CURRENT_INVALID       1
/*********************************/
/*    types                      */
/*********************************/
#define RD_DATA_BASE             0
#define RD_DATA_BURST_FILTER     1

/* states */
#define RD_BURST_LOCK   0x0001


/*********************************/
/*    data handler               */
/*********************************/
#define RDH_STRUCT_COMMON( TYPE ) \
  int size; \
  int changed; \
  TYPE value; \
  TYPE def;

#define rdh_get( DH ) (DH)->value
#define rdh_changed( DH ) (DH)->changed

#define rdh_retrigger( DH ) (DH)->changed = 0


#define RDH_STRUCT_BASE( TYPE, ALIAS ) \
  typedef struct _ ## ALIAS { \
    RDH_STRUCT_COMMON( TYPE ) \
  } ALIAS;

#define RDH_DECL_FCT_COMMON( TYPE, ALIAS ) \
  void ALIAS ## _reinit( ALIAS * dh );

#define RDH_DECL_PRIMITIF( TYPE, ALIAS ) \
  RDH_STRUCT_BASE( TYPE, ALIAS ) \
  RDH_DECL_FCT_COMMON( TYPE, ALIAS ) \
  void ALIAS ## _set( ALIAS * dh, TYPE value ); \
  void ALIAS ## _init( ALIAS * dh, TYPE value );


#define RDH_DECL_STRING( TYPE, ALIAS ) \
  RDH_STRUCT_BASE( TYPE, ALIAS ) \
  RDH_DECL_FCT_COMMON( TYPE, ALIAS ) \
  void ALIAS ## _strcpy( ALIAS * dh, const char *s); \
  void ALIAS ## _init( ALIAS * dh, const char *s);

#define RDH_DECL_COMPLEX( TYPE, ALIAS ) \
  RDH_STRUCT_BASE( TYPE, ALIAS ) \
  RDH_DECL_FCT_COMMON( TYPE, ALIAS ) \
  void ALIAS ## _cpy( ALIAS * dh, TYPE * addr); \
  void ALIAS ## _init( ALIAS * dh, TYPE * addr);



RDH_DECL_PRIMITIF( int, rdh_int )
RDH_DECL_PRIMITIF( size_t, rdh_size )
RDH_DECL_PRIMITIF( float, rdh_float )
RDH_DECL_PRIMITIF( double, rdh_double )
RDH_DECL_PRIMITIF( ruint32, rdh_uint32 )

RDH_DECL_STRING( rchar255, rdh_char255 )




#endif /*__RDATAS_H__*/

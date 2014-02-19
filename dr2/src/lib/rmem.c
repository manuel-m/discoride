#include "rmem.h"
#include "rstack_proxy.h"

#ifdef DEBUG

/*========================================================================
 *
 *
 *
 *========================================================================*/
void *r_calloc_dbg(size_t nmemb, size_t size)
{
  R_ASSERT_ERROR(  ( rattr( alloc_disable ) ) == 0  );
  return calloc( nmemb, size );
}
/*========================================================================
 *
 *
 *
 *========================================================================*/
void *r_malloc_dbg(size_t size)
{
  R_ASSERT_ERROR(  ( rattr( alloc_disable ) ) == 0  );
  return malloc( size );
}
/*========================================================================
 *
 *
 *
 *========================================================================*/
void *r_realloc_dbg(void *ptr, size_t size)
{
  R_ASSERT_ERROR(  ( rattr( alloc_disable ) ) == 0  );
  return realloc( ptr, size );
}

#endif
#ifndef __RTRACE_H__
#define __RTRACE_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
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
#include <tre/tre.h>
#include <libgen.h>
#include <time.h>
#include <execinfo.h>
#include <math.h>
/* -------------------------------------------------------------------------*/
/* debug                                                                    */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void r_print_trace(void);

void rlog(FILE *file,
          const char* s1,
          const char* s2,
          const int level,
          const char* filename,
          const unsigned int line);

#ifdef DEBUG

#define R_LOG(S1, S2, LEVEL) r_log( stdout, S1, S2, LEVEL, __FILE__, __LINE__)

#define R_LOG_ERROR(MESSAGE) { fprintf(stderr, "ERROR:  %s %s %d\n", (MESSAGE), __FILE__, __LINE__); r_print_trace(); }
#define R_LOG_WARNING(MESSAGE) { fprintf(stderr, "WARNING : %s %s %d\n", (MESSAGE), __FILE__, __LINE__); }

#define R_LOG_INFO(MESSAGE) { fprintf(stderr, "INFO : %s %s %d\n", (MESSAGE), __FILE__, __LINE__); }

#define R_ASSERT(TEST, MESSAGE) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "INFO:!(" # TEST " [%s])  : %s %d\n", (MESSAGE), __FILE__, __LINE__); }

#define R_ASSERT_ERROR_INFO(TEST, MESSAGE) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "ERROR:!(" # TEST " [%s])  : %s %d\n", (MESSAGE), __FILE__, __LINE__); r_print_trace(); }

#define R_ASSERT_WARNING(TEST) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "WARNING:!(" # TEST ")  : %s %d\n", __FILE__, __LINE__); }

#define R_ASSERT_WARNING_INFO(TEST, MESSAGE) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "WARNING:!(" # TEST " [%s])  : %s %d\n", (MESSAGE), __FILE__, __LINE__);  }

#define R_ASSERT_ERROR(TEST) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "ERROR:!(" # TEST ") : %s %d\n", __FILE__, __LINE__);  r_print_trace(); }

#define R_ASSERT_EXIT(TEST) \
  if ( ( TEST ) == 0 ) \
  { fprintf(stderr, "ERROR:!(" # TEST ") : %s %d\n", __FILE__, __LINE__);  exit(1); }

#define S_FREE(POINTER) \
  if ( ( POINTER ) ) \
    free( ( POINTER ) ); ( POINTER ) = NULL;


/***********************************************************/
/* NO DEBUG                                                */
/***********************************************************/
#else

#define R_LOG(S1, S2, LEVEL)
#define R_LOG_ERROR(MESSAGE)
#define R_LOG_INFO(MESSAGE)
#define R_LOG_WARNING(MESSAGE)

#define R_ASSERT(TEST, MESSAGE)
#define R_ASSERT_ERROR_INFO(TEST, MESSAGE)
#define R_ASSERT_WARNING_INFO(TEST, MESSAGE)
#define R_ASSERT_WARNING(TEST)
#define R_ASSERT_ERROR(TEST)
#define R_ASSERT_EXIT(TEST)

#define S_FREE(POINTER) if ( ( POINTER ) ) free( ( POINTER ) ); ( POINTER ) = NULL;


#endif


#endif /*__RTRACE_H__*/
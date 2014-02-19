#include "rtrace.h"

int log_level = 1;  /*global*/

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void r_print_trace(void)
{
  void *array[32];
  int size;
  char **strings;
  int i;
  int* sf;

  size = backtrace(array, 32);
  strings = backtrace_symbols(array, size);

  printf("Obtained %d stack frames.\n", size);

  for (i = 0; i < size; i++)
    printf("%s\n", strings[i]);

  free(strings);

  /* provoke coredump */
  sf = 0; (*sf)++;
  /* alternative raise(SIGTRAP) for gdb to trigger breakpoint  */

}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rlog(FILE *file,
          const char* s1,
          const char* s2,
          const int level,
          const char* filename,
          const unsigned int line)
{
  if ( log_level < level) {
    return;
  }
  if ( s1 && (!s2) ) {
    fprintf(file, "[info %s][%s:(%d)]\n", s1, filename, line);
  }else
  if ( s2 && (!s1) ) {
    fprintf(file, "[info %s][%s:(%d)]\n", s2, filename, line);
  }
  if ( s2 && s1 ) {
    fprintf(file, "[info %s %s][%s:(%d)]\n", s1, s2, filename, line);
  }
}
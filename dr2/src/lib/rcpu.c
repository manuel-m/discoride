#include "rcpu.h"
#include "rstack_proxy.h"

/*========================================================================
 * rtimeval_subtract
 *
 *
 *========================================================================*/
int rtimeval_subtract(struct timeval *result,
                      struct timeval *x,
                      struct timeval *y)
{
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}
/*========================================================================
 * rcpu_init
 *
 *
 *========================================================================*/
void rcpu_init(rcpu* cl)
{
  R_ASSERT_ERROR(cl)
  R_CLEAR_NO_CHECK( cl, sizeof( rcpu  ) );

  rtimer_set_current_time( &cl->timer_before );
  getrusage(RUSAGE_SELF, &cl->usage_before);

}
/*========================================================================
 * rcpu_clamp
 *
 *
 *========================================================================*/
void rcpu_clamp(const size_t limitcpu,
                const int wait4milli)
{
  rcpu* cpu = &(rattr( cpu ) );

  /* ====== [ clamp cpu ] =============*/
  if ( (cpu->cpu_user > limitcpu) || (cpu->cpu_sys > limitcpu) ) {
    rtimer wait4;
    rtimer_set_current_time( &wait4 );
    rtimer_add_milli( &wait4, wait4milli );

    R_LOG_INFO("sleep")

    /* Sleep... */
    thrd_sleep(&wait4);
  }

}
/*========================================================================
 * rcpu_update
 *
 *
 *========================================================================*/
void rcpu_update(void)
{
  double elapsed;
  rcpu* cpu = &(rattr( cpu ) );

  rtimer_set_current_time( &cpu->timer_after );
  elapsed = rtimer_delta_sec( &cpu->timer_after, &cpu->timer_before);


  if (elapsed > 0) {

    const double inv_elapsed = 1 / elapsed;

    struct timeval user_result, sys_result;

    getrusage(RUSAGE_SELF, &cpu->usage_after);

    rtimeval_subtract(&user_result,
                      &cpu->usage_after.ru_utime,
                      &cpu->usage_before.ru_utime);

    rtimeval_subtract(&sys_result,
                      &cpu->usage_after.ru_stime,
                      &cpu->usage_before.ru_stime);

    {
      const double user = ( (  (double)user_result.tv_sec + ((double)user_result.tv_usec * 0.000001)  ) * inv_elapsed);
      const double sys = ( (  (double)sys_result.tv_sec + ((double)sys_result.tv_usec * 0.000001)  ) * inv_elapsed);

      if ( user ) {
        cpu->cpu_user = R_CLAMP( user, 0, 1);
      }
      if ( sys ) {
        cpu->cpu_sys = R_CLAMP( sys, 0, 1);
      }
    }

    /*
       printf("%3.2f %3.2f \n ", cpu->cpu_user, cpu->cpu_sys );
     */

    /* save  */
    cpu->usage_before = cpu->usage_after;

  }

  rtimer_cpy( &cpu->timer_before, &cpu->timer_after );


}




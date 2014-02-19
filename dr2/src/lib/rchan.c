#include "rchan.h"


/*========================================================================
 * rchan_pos
 *========================================================================*/
double rchan_pos( rchan* chan, double x1, double w, double x_pushed )
{
  const double x_norm = ( x_pushed - x1 ) / w;
  const double off0 = chan->wavebuffer_offset;
  const double sample_window = w * R_WAVEFORM_SAMPLING;

  return (off0 + ( sample_window * x_norm ) - sample_window * 0.5);
}
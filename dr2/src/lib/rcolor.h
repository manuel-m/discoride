#ifndef __RCOLOR_H__
#define __RCOLOR_H__

#include "rstd_defines.h"

/*========================================================================
 * macros
 *
 *
 *========================================================================*/
#define rglColor3( COLOR ) glColor3f( COLOR.r, COLOR.g, COLOR.b)

#define rglColor4( COLOR ) glColor4f( COLOR.r, COLOR.g, COLOR.b, COLOR.a)


/*********************************/
/*    masks                      */
/*********************************/
#define R_ARGB_R  0x00FF0000
#define R_ARGB_G  0x0000FF00
#define R_ARGB_B  0x000000FF
#define R_ARGB_A  0xFF000000

/*********************************/
/*    defines                    */
/*********************************/
typedef enum _rcolor_type {
  rcolor_bg = 0,
  rcolor_fg = 1,
  rcolor_out_stroke = 2,
  rcolor_in_stroke = 3,
  R_NB_COLOR_TYPES = 4
} rcolor_type;


typedef struct {
  ruint32 color_argb;
  float a, r, g, b;
} rRGB;

typedef rRGB rcolors[R_NB_COLOR_TYPES];

typedef struct {
  float h, s, v, a;
} rHSV;

typedef struct {
  float h, s, l, a;
} rHSL;

#define rcolor_from_argb(RGB_COLOR, INT32_COLOR) \
  { \
    (RGB_COLOR).r = (( INT32_COLOR & 0x00FF0000 ) >> 16) * 0.003921569; \
    (RGB_COLOR).g = (( INT32_COLOR & 0x0000FF00 ) >> 8) * 0.003921569; \
    (RGB_COLOR).b = ( INT32_COLOR & 0x000000FF ) * 0.003921569; \
    (RGB_COLOR).a = ( INT32_COLOR >> 24 ) * 0.003921569; \
    (RGB_COLOR).color_argb = INT32_COLOR; \
  }

ruint32 rcolor_rgb_2_l_int(const ruint32 color);


void rcolor_rgb_2_hsl(const rRGB *rgb, rHSL  *hsl);
void rcolor_hsl_2_rgb(const rHSL *hsl,  rRGB  *rgb);
ruint32 rcolor_rgb_2_hsl_int(const ruint32 color);
ruint32 rcolor_hsl_2_rgb_int(const ruint32 color);

double rcolor_rgb_min(const rRGB *rgb);
double rcolor_rgb_max(const rRGB *rgb);

void rcolor_rgb_2_hsv(const rRGB *rgb,  rHSV  *hsv);
void rcolor_hsv_2_rgb(const rHSV *hsv, rRGB       *rgb);

double rcolor_hsl_value(double n1, double n2,  double hue);
ruint32 rcolor_hsl_value_int(double n1, double n2, double hue);



#endif /* __RCOLOR_H__ */
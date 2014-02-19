#include "rcolor.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
double rcolor_rgb_max(const rRGB *rgb)
{
  R_ASSERT_ERROR( rgb );

  if (rgb->r > rgb->g)
    return (rgb->r > rgb->b) ? rgb->r : rgb->b;
  else
    return (rgb->g > rgb->b) ? rgb->g : rgb->b;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
double rcolor_rgb_min(const rRGB *rgb)
{
  R_ASSERT_ERROR( rgb );

  if (rgb->r < rgb->g)
    return (rgb->r < rgb->b) ? rgb->r : rgb->b;
  else
    return (rgb->g < rgb->b) ? rgb->g : rgb->b;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rcolor_rgb_2_hsv(const rRGB *rgb,  rHSV  *hsv)
{
  double max, min, delta;

  R_ASSERT_ERROR( rgb );
  R_ASSERT_ERROR( hsv );

  max = rcolor_rgb_max(rgb);
  min = rcolor_rgb_min(rgb);

  hsv->v = max;
  delta = max - min;

  if (delta > 0.0001) {
    hsv->s = delta / max;
    if (rgb->r == max) {
      hsv->h = (rgb->g - rgb->b) / delta;
      if (hsv->h < 0.0)
        hsv->h += 6.0;
    } else if (rgb->g == max) {
      hsv->h = 2.0 + (rgb->b - rgb->r) / delta;
    } else if (rgb->b == max) {
      hsv->h = 4.0 + (rgb->r - rgb->g) / delta;
    }
    hsv->h /= 6.0;
  } else {
    hsv->s = 0.0;
    hsv->h = 0.0;
  }
  hsv->a = rgb->a;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rcolor_hsv_2_rgb(const rHSV *hsv, rRGB       *rgb)
{
  int i;
  double f, w, q, t;
  double hue;

  R_ASSERT_ERROR( rgb );
  R_ASSERT_ERROR( hsv );

  if (hsv->s == 0.0) {
    rgb->r = hsv->v;
    rgb->g = hsv->v;
    rgb->b = hsv->v;
  } else {
    hue = hsv->h;

    if (hue == 1.0)
      hue = 0.0;

    hue *= 6.0;

    i = (int)hue;
    f = hue - i;
    w = hsv->v * (1.0 - hsv->s);
    q = hsv->v * (1.0 - (hsv->s * f));
    t = hsv->v * (1.0 - (hsv->s * (1.0 - f)));

    switch (i) {
    case 0:
      rgb->r = hsv->v;
      rgb->g = t;
      rgb->b = w;
      break;
    case 1:
      rgb->r = q;
      rgb->g = hsv->v;
      rgb->b = w;
      break;
    case 2:
      rgb->r = w;
      rgb->g = hsv->v;
      rgb->b = t;
      break;
    case 3:
      rgb->r = w;
      rgb->g = q;
      rgb->b = hsv->v;
      break;
    case 4:
      rgb->r = t;
      rgb->g = w;
      rgb->b = hsv->v;
      break;
    case 5:
      rgb->r = hsv->v;
      rgb->g = w;
      rgb->b = q;
      break;
    default:
    {
      ;
    }
    }
  }
  rgb->a = hsv->a;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rcolor_rgb_2_hsl(const rRGB *rgb, rHSL  *hsl)
{
  double max, min, delta;

  R_ASSERT_ERROR( rgb );
  R_ASSERT_ERROR( hsl );

  max = rcolor_rgb_max(rgb);
  min = rcolor_rgb_min(rgb);

  hsl->l = (max + min) * 0.5;

  if (max == min) {
    hsl->s = 0.0;
    hsl->h = -1.0;
  } else {
    if (hsl->l <= 0.5)
      hsl->s = (max - min) / (max + min);
    else
      hsl->s = (max - min) / (2.0 - max - min);

    delta = max - min;

    if (delta == 0.0)
      delta = 1.0;

    if (rgb->r == max) {
      hsl->h = (rgb->g - rgb->b) / delta;
    } else if (rgb->g == max) {
      hsl->h = 2.0 + (rgb->b - rgb->r) / delta;
    } else if (rgb->b == max) {
      hsl->h = 4.0 + (rgb->r - rgb->g) / delta;
    }

    hsl->h /= 6.0;

    if (hsl->h < 0.0)
      hsl->h += 1.0;
  }

  hsl->a = rgb->a;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
double rcolor_hsl_value(double n1, double n2,  double hue)
{
  double val;

  if (hue > 6.0)
    hue -= 6.0;
  else if (hue < 0.0)
    hue += 6.0;

  if (hue < 1.0)
    val = n1 + (n2 - n1) * hue;
  else if (hue < 3.0)
    val = n2;
  else if (hue < 4.0)
    val = n1 + (n2 - n1) * (4.0 - hue);
  else
    val = n1;

  return val;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rcolor_hsl_2_rgb(const rHSL *hsl,  rRGB  *rgb)
{
  R_ASSERT_ERROR( rgb );
  R_ASSERT_ERROR( hsl );

  if (hsl->s == 0) {
    rgb->r = hsl->l;
    rgb->g = hsl->l;
    rgb->b = hsl->l;
  } else {
    double m1, m2;

    if (hsl->l <= 0.5)
      m2 = hsl->l * (1.0 + hsl->s);
    else
      m2 = hsl->l + hsl->s - hsl->l * hsl->s;

    m1 = 2.0 * hsl->l - m2;

    rgb->r = rcolor_hsl_value(m1, m2, hsl->h * 6.0 + 2.0);
    rgb->g = rcolor_hsl_value(m1, m2, hsl->h * 6.0);
    rgb->b = rcolor_hsl_value(m1, m2, hsl->h * 6.0 - 2.0);
  }

  rgb->a = hsl->a;
}


/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
ruint32 rcolor_rgb_2_hsl_int(const ruint32 color)
{
  double h, s, l;
  ruint32 min, max;
  int delta;

  ruint32 r = ( color & 0xFF000000 ) >> 24;
  ruint32 g = ( color & 0x00FF0000 ) >> 16;
  ruint32 b = ( color & 0x0000FF00 ) >> 8;

  /*const ruint32 ai = color & 0x000000FF;*/

  if (r > g) {
    max = R_MAX(r, b);
    min = R_MIN(g, b);
  } else {
    max = R_MAX(g, b);
    min = R_MIN(r, b);
  }

  l = (max + min) * 0.5;

  if (max == min) {
    s = 0.0;
    h = 0.0;
  } else {
    delta = (int)(max - min);

    if (l < 128)
      s = 255 * (double)delta / (double)(max + min);
    else
      s = 255 * (double)delta / (double)(511 - max - min);

    if (r == max)
      h = (g - b) / (double)delta;
    else if (g == max)
      h = 2 + (b - r) / (double)delta;
    else
      h = 4 + (r - g) / (double)delta;

    h = h * 42.5;

    if (h < 0)
      h += 255;
    else if (h > 255)
      h -= 255;
  }

  r = (ruint32)( R_ROUND( h ) );
  g = (ruint32)( R_ROUND( s ) );
  b = (ruint32)( R_ROUND( l ) );

  return
    ( ( ( r << 24 ) & 0xFF000000 )
      | ( ( g << 16 ) & 0x00FF0000 )
      | ( ( b << 8 ) & 0x0000FF00  ) );

}

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
ruint32 rcolor_rgb_2_l_int(const ruint32 color)
{
  ruint32 red = ( color & 0xFF000000 ) >> 24;
  ruint32 green = ( color & 0x00FF0000 ) >> 16;
  ruint32 blue = ( color & 0x0000FF00 ) >> 8;

  ruint32 min, max;

  if (red > green) {
    max = R_MAX(red,   blue);
    min = R_MIN(green, blue);
  } else {
    max = R_MAX(green, blue);
    min = R_MIN(red,   blue);
  }
  return (ruint32)(R_ROUND((max + min) * 0.5));
}

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
ruint32 rcolor_hsl_value_int(double n1, double n2, double hue)
{
  double value;

  if (hue > 255)
    hue -= 255;
  else if (hue < 0)
    hue += 255;

  if (hue < 42.5)
    value = n1 + (n2 - n1) * (hue * 0.023529412);  /* 1/42.5 */
  else if (hue < 127.5)
    value = n2;
  else if (hue < 170)
    value = n1 + (n2 - n1) * ((170 - hue) * 0.023529412);
  else
    value = n1;

  return (ruint32)(R_ROUND(value * 255.0));
}

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
ruint32 rcolor_hsl_2_rgb_int(const ruint32 color)
{
  ruint32 hue = ( color & 0xFF000000 ) >> 24;
  ruint32 saturation = ( color & 0x00FF0000 ) >> 16;
  ruint32 lightness = ( color & 0x0000FF00 ) >> 8;

  double h, s, l;

  h = hue;
  s = saturation;
  l = lightness;

  if (s == 0) {
    /*  achromatic case  */
    hue        = (ruint32)l;
    lightness  = (ruint32)l;
    saturation = (ruint32)l;
  } else {
    double m1, m2;

    if (l < 128)
      m2 = (l * (255 + s)) * 0.000015379;
    else
      m2 = l + s - (l * s) * 0.000015379;

    m1 = (l * 0.007843137) - m2;

    /*  chromatic case  */
    hue        = rcolor_hsl_value_int(m1, m2, h + 85);
    saturation = rcolor_hsl_value_int(m1, m2, h);
    lightness  = rcolor_hsl_value_int(m1, m2, h - 85);
  }


  return
    ( ( ( hue << 24 ) & 0xFF000000 )
      | ( ( saturation << 16 ) & 0x00FF0000 )
      | ( ( lightness << 8 ) & 0x0000FF00  ) );
}


#include "rstack_proxy.h"


#define COL_DARK 0xFF000000
#define COL_GREEN 0xFF00FF00
#define COL_BG_NORMAL_DARK0 0xFF111111
#define COL_BG_NORMAL_DARK1 0xFF222222

#define COL_BG_NORMAL 0xFF333333

#define COL_BG_NORMAL_LIGHT 0xFF444444

#define COL_BG_FOCUS 0xFF303020
#define COL_BG_NON_SELECTED 0xFF181818

#define COL_DOCK0 0xFFFFCC00
#define COL_DOCK0_DARK 0xFF886600

#define COL_DOCK1 0xFF66BBDD
#define COL_DOCK1_DARK 0xFF336677

#define COL_MIX 0xFF22FF77

/* -------------------------------------------------------------------------*/
/*     style                                                                */
/* -------------------------------------------------------------------------*/
void rstyle_config(void)
{

/* buttons */
  {
    rstyle* style = rstyle_new(  "button_style", NULL, 0);
    rstyle_set_all( style, design_corner_curvature_radius, 30 );
    rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_DARK, R_SSSNORMAL );
    rstyle_argb_set( style, ractivated, rcolor_out_stroke, COL_DARK, R_SSSNORMAL );
  }

/* label */
  {
    rstyle* style = rstyle_new(  "label_style", "NULL", 0);
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL);
    rstyle_argb_set( style, ractivated, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
    rstyle_argb_set( style, rdisabled, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
    rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_DARK, R_SSSNORMAL );
    rstyle_argb_set( style, ractivated, rcolor_out_stroke, COL_DARK, R_SSSNORMAL );
  }
/* label0 */
  {
    rstyle* style = rstyle_new(  "label_style0", "label_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_fg, COL_DOCK0, R_SSS_ALL );
    rstyle_set_all( style, render_flags, R_H_LEFT );

  }
/* label1 */
  {
    rstyle* style = rstyle_new(  "label_style1", "label_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_set_all( style, render_flags, R_H_LEFT );
  }

/* vslider */
  {
    rstyle* style = rstyle_new(  "vslider_style", "button_style", 0);
    rstyle_set_all( style, design_slider_w_size, 60 );
    rstyle_set_all( style, design_slider_h_size, 40 );
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_NORMAL, R_SSSNORMAL );
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_FOCUS, R_SSSFOCUS );
    rstyle_argb_set( style, rnormal, rcolor_fg, COL_DARK, R_SSS_ALL );
  }

/* vmeter */
  {
    rstyle* style = rstyle_new(  "vmeter_style", "vslider_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_DARK, R_SSS_ALL );
    rstyle_argb_set( style, rnormal, rcolor_fg, COL_GREEN, R_SSS_ALL );
  }

/* vslider 0 */
  {
    rstyle* style = rstyle_new(  "vslider_style0", "vslider_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_DOCK0, R_SSSFOCUS );
    rstyle_argb_set( style, rnormal, rcolor_in_stroke, COL_DOCK0, R_SSS_ALL );
  }


/* vslider 1 */
  {
    rstyle* style = rstyle_new(  "vslider_style1", "vslider_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_DOCK1, R_SSSFOCUS );
    rstyle_argb_set( style, rnormal, rcolor_in_stroke, COL_DOCK1, R_SSS_ALL );
  }

/* h gauge mix */
  {
    rstyle* style = rstyle_new(  "hgauge_stylem", "button_style", 0);
    rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_MIX, R_SSSFOCUS );
    rstyle_argb_set( style, rnormal, rcolor_in_stroke, COL_MIX, R_SSS_ALL );
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_NORMAL, R_SSSNORMAL );
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_FOCUS, R_SSSFOCUS );
    rstyle_argb_set( style, rnormal, rcolor_fg, COL_DARK, R_SSS_ALL );
  }


/* play-button */
  {
    rstyle* style = rstyle_new(  "play_button_style", "button_style", 0);
    rstyle_set_all( style, design_font_size, 50 );

    rstyle_argb_set( style, rmasked, rcolor_bg, COL_BG_NORMAL_DARK0, R_SSS_ALL );
    rstyle_argb_set( style, rmasked, rcolor_fg, COL_BG_NORMAL_DARK1, R_SSS_ALL );
    rstyle_argb_set( style, rmasked, rcolor_out_stroke, COL_BG_NORMAL_LIGHT, R_SSS_ALL );

    rstyle_argb_set( style, rdisabled, rcolor_bg, COL_BG_NORMAL_DARK0, R_SSS_ALL );
    rstyle_argb_set( style, rdisabled, rcolor_fg, COL_BG_NORMAL_DARK1, R_SSS_ALL );
    rstyle_argb_set( style, rdisabled, rcolor_out_stroke, COL_BG_NORMAL_DARK1, R_SSS_ALL );

    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_NORMAL, R_SSSNORMAL );
    rstyle_argb_set( style, rnormal, rcolor_bg, COL_BG_FOCUS, R_SSSFOCUS );
    rstyle_argb_set( style, ractivated, rcolor_bg, COL_BG_NORMAL, R_SSSNORMAL );
    rstyle_argb_set( style, ractivated, rcolor_bg, COL_BG_FOCUS, R_SSSFOCUS );
  }




/* txt-button */
  {
    rstyle* style = rstyle_new(  "txt_button_style", "button_style", 0);
    rstyle_set_all( style, design_corner_curvature_radius, 10 );
    rstyle_set_all( style, render_flags, R_CENTER | R_CIRCLE  );

    rstyle_argb_set( style, rmasked, rcolor_bg, COL_BG_NORMAL_DARK0, R_SSS_ALL );
    rstyle_argb_set( style, rmasked, rcolor_fg, COL_BG_NORMAL_DARK1, R_SSS_ALL );
    rstyle_argb_set( style, rmasked, rcolor_out_stroke, COL_BG_NORMAL_LIGHT, R_SSSFOCUS );

    rstyle_argb_set( style, rnormal, rcolor_bg, 0xFFFFFFFF, R_SSS_ALL );

    rstyle_argb_set( style, ractivated, rcolor_fg, 0xFFFFCC00, R_SSS_ALL );
    rstyle_argb_set( style, ractivated, rcolor_out_stroke, 0xFFFFCC00, R_SSS_ALL );
  }

/* txt-button-mini */
  {
    rstyle* style = rstyle_new(  "txt_button_style_mini", "txt_button_style", 0);
    rstyle_set_all( style, design_font_size, 40 );
  }


/* h gauge */
  {
    rstyle* style = rstyle_new(  "hgauge_style", "button_style", 2);
    rstyle_set_all( style, design_corner_curvature_radius, 4 );
    rstyle_set_all( style, design_font_size, 50 );
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_DISABLED, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
    rstyle_set_all( style, design_stroke_size, 6 );
    rstyle_set_all( style, render_flags, R_H_LEFT  );

  }

/* h gauge 0 */
  {
    rstyle* style = rstyle_new(  "hgauge_style0", "hgauge_style", 0);
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_fg, COL_DOCK0, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_out_stroke, COL_DOCK0, R_SSSFOCUS );
    rstyle_argb_set( style, R_CHAN_PLAY, rcolor_fg, COL_DOCK0, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_PLAY, rcolor_out_stroke, COL_DOCK0, R_SSSFOCUS );

    rstyle_argb_set( style, R_CHAN_LOADING_STOP, rcolor_fg, 0xFF886600, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_LOADING_PLAY, rcolor_fg, 0xFFFF6600, R_SSS_ALL );

  }


/* h gauge 1 */
  {
    rstyle* style = rstyle_new(  "hgauge_style1", "hgauge_style", 0);
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_out_stroke, COL_DOCK1, R_SSSFOCUS);

    rstyle_argb_set( style, R_CHAN_PLAY, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_PLAY, rcolor_out_stroke, COL_DOCK1, R_SSSFOCUS);

    rstyle_argb_set( style, R_CHAN_LOADING_STOP, rcolor_fg, 0xFF335577, R_SSS_ALL );
    rstyle_argb_set( style, R_CHAN_LOADING_PLAY, rcolor_fg, 0xFF88FFDD, R_SSS_ALL );
  }


  /* jog_style0 */
  {
    rstyle* style = rstyle_new(  "jog_style0", "hgauge_style0", 0);
    rstyle_set_all( style, design_font_size, 40 );
    rstyle_set_all( style, render_flags, R_CENTER  );
  }

  /* jog_style1 */
  {
    rstyle* style = rstyle_new(  "jog_style1", "hgauge_style1", 0);
    rstyle_set_all( style, design_font_size, 40 );
    rstyle_argb_set( style, ractivated, rcolor_out_stroke, COL_DOCK1, R_SSSFOCUS );
    rstyle_argb_set( style, ractivated, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_set_all( style, render_flags, R_CENTER   );
  }


  /* play_button_style0_mini */
  {
    rstyle* style = rstyle_new(  "play_button_style0_mini", "jog_style0", 0);
    rstyle_set_all( style, design_font_size, 36 );
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_fg, COL_DOCK0_DARK, R_SSS_ALL );
    /*rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_BG_NORMAL_DARK0, R_SSSNORMAL );*/
    rstyle_set_all( style, render_flags, R_CENTER | R_CIRCLE  );
  }

  /* play_button_style1_mini */
  {
    rstyle* style = rstyle_new(  "play_button_style1_mini", "jog_style1", 0);
    rstyle_set_all( style, design_font_size, 36 );
    rstyle_argb_set( style, R_CHAN_STOP, rcolor_fg, COL_DOCK1_DARK, R_SSS_ALL );
    /*rstyle_argb_set( style, rnormal, rcolor_out_stroke, COL_BG_NORMAL_DARK1, R_SSSNORMAL );*/
    rstyle_set_all( style, render_flags, R_CENTER | R_CIRCLE  );
  }



/* playlist-button */
  {
    /* 4 additional sstyles */
    rstyle* style = rstyle_new(  "playlist_button_style", "button_style", 4);

    rstyle_set_all( style, design_corner_curvature_radius, 20 );
    rstyle_set_all( style, render_flags, R_H_LEFT );
    rstyle_set_all( style, design_font_size, 56 );
    rstyle_set_all( style, design_stroke_size, 0 );

    /* customized sstyle */
    rstyle_argb_set( style, ractivated, rcolor_fg, 0xFFFFFFFF, R_SSS_ALL );
    rstyle_argb_set( style, ractivated, rcolor_bg, COL_BG_FOCUS, R_SSS_ALL );

    rstyle_argb_set( style, rpldock0_state, rcolor_fg, COL_DOCK0, R_SSS_ALL);
    rstyle_argb_set( style, rpldock0_state, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
    rstyle_argb_set( style, rpldock1_state, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_argb_set( style, rpldock1_state, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );

    rstyle_argb_set( style, rpldock0_selected_state, rcolor_fg, COL_DOCK0, R_SSS_ALL );
    rstyle_argb_set( style, rpldock0_selected_state, rcolor_bg, COL_BG_FOCUS, R_SSS_ALL );

    rstyle_argb_set( style, rpldock1_selected_state, rcolor_fg, COL_DOCK1, R_SSS_ALL );
    rstyle_argb_set( style, rpldock1_selected_state, rcolor_bg, COL_BG_FOCUS, R_SSS_ALL );

    /* maybe better to disable display */
    rstyle_argb_set( style, rdisabled, rcolor_bg, COL_BG_NON_SELECTED, R_SSS_ALL );
  }

/* playlist-button-duration */
  {
    rstyle* style = rstyle_new(  "playlist_button_duration_style", "playlist_button_style", 0);
    rstyle_set_all( style, render_flags, R_H_RIGHT );
  }





}


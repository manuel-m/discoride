#include "rstack_proxy.h"

RLIST_IMPL( rlssstyle, rsstyle )
RLIST_IMPL( rlsstyle, rstyle )


/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rstyle_argb_set(rstyle * style,
                     const int state,
                     const rcolor_type color_type,
                     const ruint32 color,
                     const int normal_focus_state   )
{
  R_ASSERT_ERROR( style )
  R_ASSERT_ERROR( (normal_focus_state >= 0 ) && (normal_focus_state <= R_SSS_ALL )  )

  if ( ( normal_focus_state == R_SSSNORMAL ) || ( normal_focus_state == R_SSSFOCUS )) {
    rcolor_from_argb(style->sstyles.data[state]->ssstyles[normal_focus_state].colors[color_type], color );
    return;
  }
  /* normal and focus state */
  rcolor_from_argb(style->sstyles.data[state]->ssstyles[R_SSSNORMAL].colors[color_type], color);
  rcolor_from_argb(style->sstyles.data[state]->ssstyles[R_SSSFOCUS].colors[color_type], color);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rstyle_refresh(rstyle* style,
                    const double ratio,
                    const double ratio_w,
                    const double ratio_h  )
{
  rlssstyle_iterator iter;
  rlssstyle* ls;
  rsstyle* ss;
  rssstyle* sss;
  int sss_i;

  R_ASSERT_ERROR( style)
  ls = &style->sstyles;

  ss = rlssstyle_first( &iter, ls );
  while (ss) {

    for (sss_i = 0; sss_i < R_SSSTYLES; sss_i++) {
      sss = &ss->ssstyles[sss_i];
      sss->active_font_size = sss->design_font_size * rval_get( global_font_coef ) * ratio;
      sss->active_stroke_size = sss->design_stroke_size * ratio;
      sss->active_corner_curvature_radius = sss->design_corner_curvature_radius * ratio;
      sss->active_slider_w_size = sss->design_slider_w_size * ratio_w;
      sss->active_slider_h_size = sss->design_slider_h_size * ratio_h;
    }

    ss = rlssstyle_next( &iter );
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rstyle* rstyle_get(const char* name)
{
  rlsstyle_iterator iter;
  rlsstyle* ls = &( rattr( styles ) );
  rstyle* s = rlsstyle_first( &iter, ls );

  while (s) {
    if ( !strcmp( name, s->name ) ) {
      return s;
    }
    s = rlsstyle_next( &iter );
  }
  return 0;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rstyle_preinit(void)
{
  rcolor_from_argb(rattr( window_bg_color ), 0xFF00000);

  /* default style */
  rstyle_new("default_style", NULL, 0);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rstyle_init( rstyle* style,
                  const char* name,
                  const char* parent_name,
                  const size_t custom_states)
{
  rstyle* style_parent = NULL;
  int sss_i;

  R_ASSERT_ERROR( style );
  R_ASSERT_ERROR( name );
  R_ASSERT_ERROR_INFO( strlen( name ) < ( sizeof( style->name ) / sizeof( char ) ), name );

  R_CLEAR( style, rstyle );
  rstrcpy(style->name, name );

  if ( parent_name ) {
    style_parent = rstyle_get( parent_name );
  }

  /* clone style parent */
  if ( style_parent ) {
    rlssstyle_clone(&style->sstyles, &style_parent->sstyles );

    /* if parent has missing custo_states */
    {
      size_t i;
      for (i = style_parent->sstyles.len; i < ( R_NB_RSTATE_STATES +  custom_states ); i++) {
        rlssstyle_add(&style->sstyles, rsstyle_new()  );
      }
    }


  }else {
    size_t i;
    for (i = 0; i < ( R_NB_RSTATE_STATES +  custom_states ); i++) {
      rlssstyle_add(&style->sstyles, rsstyle_new()  );
    }

    for (sss_i = 0; sss_i < R_SSSTYLES; sss_i++) {

      /* masked argb  */
      rcolor_from_argb(style->sstyles.data[rmasked]->ssstyles[sss_i].colors[rcolor_bg], 0xFF111111);
      rcolor_from_argb(style->sstyles.data[rmasked]->ssstyles[sss_i].colors[rcolor_fg], 0xFF222222);
      rcolor_from_argb(style->sstyles.data[rmasked]->ssstyles[sss_i].colors[rcolor_out_stroke], 0xFF444444);
      rcolor_from_argb(style->sstyles.data[rmasked]->ssstyles[sss_i].colors[rcolor_in_stroke], 0xFF444444);

      /* disabled argb */
      rcolor_from_argb(style->sstyles.data[rdisabled]->ssstyles[sss_i].colors[rcolor_bg], 0xFF000000);
      rcolor_from_argb(style->sstyles.data[rdisabled]->ssstyles[sss_i].colors[rcolor_fg], 0xFFFFFFFF);
      rcolor_from_argb(style->sstyles.data[rdisabled]->ssstyles[sss_i].colors[rcolor_out_stroke], 0xFF000000);
      rcolor_from_argb(style->sstyles.data[rdisabled]->ssstyles[sss_i].colors[rcolor_in_stroke], 0xFF000000);

      /* normal argb */
      rcolor_from_argb(style->sstyles.data[rnormal]->ssstyles[sss_i].colors[rcolor_bg], 0xFF181818);
      rcolor_from_argb(style->sstyles.data[rnormal]->ssstyles[sss_i].colors[rcolor_fg], 0xFFFFFFFF);
      rcolor_from_argb(style->sstyles.data[rnormal]->ssstyles[sss_i].colors[rcolor_out_stroke], 0xFF000000);
      rcolor_from_argb(style->sstyles.data[rnormal]->ssstyles[sss_i].colors[rcolor_in_stroke], 0xFF000000);

      /* activated argb */
      rcolor_from_argb(style->sstyles.data[ractivated]->ssstyles[sss_i].colors[rcolor_bg], 0xFF222222);
      rcolor_from_argb(style->sstyles.data[ractivated]->ssstyles[sss_i].colors[rcolor_fg], 0xFFFFCC00);
      rcolor_from_argb(style->sstyles.data[ractivated]->ssstyles[sss_i].colors[rcolor_out_stroke], 0xFFFFCC00);
      rcolor_from_argb(style->sstyles.data[ractivated]->ssstyles[sss_i].colors[rcolor_in_stroke], 0xFFFFCC00);

    }
  }

  rlsstyle_add( &( rattr( styles ) ), style );
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rstyle* rstyle_new(  const char* name,
                     const char* parent_name,
                     const size_t custom_states  )
{
  rstyle* style = R_CALLOC( 1, sizeof( rstyle ) );

  R_ASSERT_ERROR( style );
  rstyle_init( style, name, parent_name, custom_states);

  return style;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rsstyle_init( rsstyle* s )
{
  int sss_i;
  rssstyle* sss;

  R_ASSERT_ERROR( s );
  R_CLEAR( s, rsstyle );

  for (sss_i = 0; sss_i < R_SSSTYLES; sss_i++) {
    sss = &s->ssstyles[sss_i];
    sss->design_font_size = 60;
    sss->design_stroke_size = 8;
    sss->design_corner_curvature_radius = 60;
    sss->design_slider_w_size = 30;
    sss->design_slider_h_size = 140;
    rcolor_from_argb(sss->colors[rcolor_bg], 0xFF111111);
    rcolor_from_argb(sss->colors[rcolor_fg],  0xFFFFFFFF);
    rcolor_from_argb(sss->colors[rcolor_out_stroke], 0xFF000000);
    sss->render_flags = R_CENTER;
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rsstyle* rsstyle_new(void)
{
  rsstyle* style = R_CALLOC( 1, sizeof( rsstyle ) );

  rsstyle_init( style );
  return style;
}



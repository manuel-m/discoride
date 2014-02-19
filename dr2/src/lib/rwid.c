#include "rstack_proxy.h"

/*========================================================================
 * rwid_texalloc
 *========================================================================*/
void rwid_texalloc( rwid * wid )
{
  const int w = wid->htex_factor * wid->w;
  const int h = wid->vtex_factor * wid->h;

  rlsrcairogl_iterator iter;
  rcairogl* cairogl = rlsrcairogl_first( &iter,  &wid->textures );

  while (cairogl) {

    if ( cairogl->tex_id ) {
      glDeleteTextures(1, &cairogl->tex_id);
    }
    glGenTextures(1, &cairogl->tex_id );

    rcairogl_texalloc( cairogl, w, h);
    cairogl = rlsrcairogl_next( &iter );
  }
}
/*========================================================================
 * rwid_texreset
 * [!] to solve remaining alpha effects
 *========================================================================*/
void rwid_texreset(rwid* wid)
{
  rlsrcairogl_iterator iter;
  rcairogl* cairogl = rlsrcairogl_first( &iter,  &wid->textures );

  while (cairogl) {

    if ( cairogl->data ) {
      rcairogl_texreset(cairogl);
      cairogl = rlsrcairogl_next( &iter );
    }
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
RLIST_IMPL( rlswid, rwid )
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rwid_state_get( const rwid* wid )
{
  R_ASSERT_ERROR( wid )
  R_ASSERT_ERROR_INFO( wid->state_dh, wid->name )
  return wid->state_dh->value;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rwid_style_check(rwid* wid)
{
  R_ASSERT_ERROR_INFO( wid, wid->name )
  R_ASSERT_ERROR_INFO( wid->style, wid->name )
  R_ASSERT_ERROR_INFO( (int)(wid->style->sstyles.len) > wid->state_dh->value, wid->name )
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rssstyle* rwid_style_get( rwid* wid )
{
  rsstyle* style;

  R_ASSERT_ERROR( wid )

#ifdef DEBUG
  rwid_style_check( wid );
#endif

  style = wid->style->sstyles.data[rwid_state_get(wid)];
  return &style->ssstyles[ wid->focus_dh.value ];
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rwid_style_set( rwid* wid, rstyle* style )
{
  R_ASSERT_ERROR( wid )
  R_ASSERT_ERROR( style )
  wid->style = style;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rwid_init( rwid* wid,
                const char* name,
                const char* parent_name,
                const int type,
                const double x,
                const double y,
                const double w,
                const double h,
                void (*f_clic_handler)( rwid*, int button_id, int button_state ),
                void (*f_wheel_up)( rwid* ),
                void (*f_wheel_down)( rwid* ),
                const char* style_name,
                const ruint32 render_spec,
                const int wdata,
                void (*f_draw)(  rwid* ),
                void (*f_retrigger)(  rwid* ),
                void (*f_fire_left)( const int  ),
                void (*f_fire_right)( const int  ),
                void (*f_fire_over_in)( const int  ),
                void (*f_fire_over_out)( const int  ),
                void (*f_fire_wheel_up)( const int  ),
                void (*f_fire_wheel_down)( const int  ),
                void (*f_fire_wheel_center)( const int  ),
                rdh_int* state_dh,
                rdh_double* normx_dh,
                rdh_double* normy_dh,
                rdh_char255* label_dh,
                const double step,
                const size_t nb_tex,
                const int htex_factor,
                const int vtex_factor )
{

  R_ASSERT_ERROR( wid )
  R_CLEAR( wid, rwid );

  rstrcpy( wid->name, name );
  wid->type = type;

  if (parent_name) {
    wid->parent = rwid_get(parent_name);
  }
  wid->f_clic_handler = f_clic_handler;
  wid->f_wheel_up = f_wheel_up;
  wid->f_wheel_down = f_wheel_down;

  wid->wanted_x = x;
  wid->wanted_y = y;
  wid->wanted_w = w;
  wid->wanted_h = h;

  wid->wdata = wdata;

  if ( style_name ) {
    wid->style = rstyle_get( style_name );
    R_ASSERT_ERROR_INFO(  wid->style, style_name )
  }else {
    wid->style = rstyle_get("default_style");
  }

  R_ASSERT_ERROR_INFO( f_draw,  wid->name)
  wid->f_draw = f_draw;

  R_ASSERT_ERROR_INFO( f_retrigger,  wid->name)
  wid->f_retrigger = f_retrigger;

  wid->render_spec = render_spec;

  wid->f_fire_left = f_fire_left;
  wid->f_fire_right = f_fire_right;
  wid->f_fire_over_in =  f_fire_over_in;
  wid->f_fire_over_out = f_fire_over_out;
  wid->f_fire_wheel_up = f_fire_wheel_up;
  wid->f_fire_wheel_down = f_fire_wheel_down;
  wid->f_fire_wheel_center =  f_fire_wheel_center;
  wid->state_dh = state_dh;
  wid->normx_dh = normx_dh;
  wid->normy_dh = normy_dh;
  wid->label_dh = label_dh;
  wid->step = step;

  /* alloc cairogl if needed */
  if ( nb_tex ) {
    size_t i;
    for (i = 0; i < nb_tex; i++) {
      rlsrcairogl_add( &wid->textures, rcairogl_new() );
    }
  }

  wid->htex_factor = htex_factor;
  wid->vtex_factor = vtex_factor;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rwid* rwid_new(    const char* name,
                   const char* parent_name,
                   const int type,
                   const double x,
                   const double y,
                   const double w,
                   const double h,
                   void (*f_clic_handler)( rwid*, int button_id, int button_state ),
                   void (*f_wheel_up)( rwid* ),
                   void (*f_wheel_down)( rwid* ),
                   const char* style_name,
                   const ruint32 render_spec,
                   const int wdata,
                   void (*f_draw)(  rwid* ),
                   void (*f_retrigger)(  rwid* ),
                   void (*f_fire_left)( const int  ),
                   void (*f_fire_right)( const int  ),
                   void (*f_fire_over_in)( const int  ),
                   void (*f_fire_over_out)( const int  ),
                   void (*f_fire_wheel_up)( const int  ),
                   void (*f_fire_wheel_down)( const int  ),
                   void (*f_fire_wheel_center)( const int  ),
                   rdh_int* state_dh,
                   rdh_double* normx_dh,
                   rdh_double* normy_dh,
                   rdh_char255* label_dh,
                   const double step,
                   const size_t nb_tex,
                   const int htex_factor,
                   const int vtex_factor )
{
  rwid* wid = R_CALLOC( 1, sizeof(rwid)  );

  rwid_init( wid,
             name,
             parent_name,
             type,
             x, y, w, h,
             f_clic_handler,
             f_wheel_up,
             f_wheel_down,
             style_name,
             render_spec,
             wdata,
             f_draw,
             f_retrigger,
             f_fire_left,
             f_fire_right,
             f_fire_over_in,
             f_fire_over_out,
             f_fire_wheel_up,
             f_fire_wheel_down,
             f_fire_wheel_center,
             state_dh,
             normx_dh,
             normy_dh,
             label_dh,
             step,
             nb_tex,
             htex_factor,
             vtex_factor  );

  wid->windex = rattr( wids ).len;


  rlswid_add( &( rattr( wids ) ), wid );

  switch (type) {
  case R_W_BUTTON:
  case R_W_HSLIDER:
  case R_W_VSLIDER:
  case R_W_DECKGAUGE:
  case R_W_DECKWAVE:
  {
    rlswid_add( &( rattr( cwids ) ), wid );
    break;
  }
  default:
  {
    ;
  }
  }
  return wid;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rwid* rwid_get(const char* name)
{
  rlswid_iterator iter;
  rlswid* ls = &( rattr( wids ) );
  rwid* w = rlswid_first( &iter, ls );

  while (w) {
    if ( !strcmp( name, w->name ) ) {
      return w;
    }
    w = rlswid_next( &iter );
  }
  return 0;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rRGB* rwid_pseudo_alpha_color( rwid* w  )
{
  R_ASSERT_ERROR( w )

  if (w->parent) {
    rssstyle* s;
#ifdef DEBUG
    rwid_style_check( w->parent );
#endif
    s = rwid_style_get( w->parent );
    return &s->colors[rcolor_bg];
  }else {
    return &(rattr( window_bg_color ));
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rwid_bb_compute( rwid* wid )
{
  R_ASSERT_ERROR( wid )

#ifdef DEBUG
  rwid_style_check( wid );
#endif

  if ( wid->parent ) {
    rwid* parent_wid = wid->parent;
    const int base_x = parent_wid->x;
    const int base_y = parent_wid->y;
    const int base_width = parent_wid->w;
    const int base_height = parent_wid->h;

    wid->x = base_x + (int)( wid->wanted_x * (double)base_width );
    wid->y = base_y + (int)( wid->wanted_y * (double)base_height );
    wid->w = (int)((double)base_width * wid->wanted_w);
    wid->h = (int)((double)base_height * wid->wanted_h);

  }else {
    const int base_width = rval_get( window_width  );
    const int base_height = rval_get( window_height );
    wid->x = (int)((double)base_width * wid->wanted_x);
    wid->y = (int)((double)base_height * wid->wanted_y);
    wid->w = (int)((double)base_width * wid->wanted_w);
    wid->h = (int)((double)base_height * wid->wanted_h);
  }
}
/*========================================================================
 * rwid_retrigger
 *
 *
 *========================================================================*/
void rwid_retrigger( rwid* wid)
{
  R_ASSERT_ERROR( wid )

  if ( wid->normx_dh ) {
    if ( rdh_changed( wid->normx_dh )) {
      rdh_retrigger( wid->normx_dh );
    }
  }

  if ( wid->normy_dh ) {
    if ( rdh_changed( wid->normy_dh )) {
      rdh_retrigger( wid->normy_dh );
    }
  }

  if ( wid->state_dh ) {
    if ( rdh_changed( wid->state_dh )) {
      rdh_retrigger( wid->state_dh );
    }
  }

  if ( wid->label_dh ) {
    if ( rdh_changed( wid->label_dh )) {
      rdh_retrigger( wid->label_dh );
    }
  }

  if ( rdh_changed( &wid->focus_dh) ) {
    rdh_retrigger( &wid->focus_dh );
  }
}
/*========================================================================
 * rwid_blit_black
 *
 *
 *========================================================================*/
void rwid_blit_black( rwid * wid )
{
  R_ASSERT_ERROR( wid ){
    const double x = wid->x;
    const double y = wid->y;
    const double w = wid->w;
    const double h = wid->h;

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x, y );
    glVertex2d(x + w, y );
    glVertex2d(x + w, y + h );
    glVertex2d(x, y + h);

    glEnd();
  }
}
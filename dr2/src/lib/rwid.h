#ifndef __RWID_H__
#define __RWID_H__
/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rcairogl.h"
/*========================================================================
 * define
 *========================================================================*/
#define R_W_NONE           0
#define R_W_BUTTON         1
#define R_W_LABEL          2
#define R_W_HSLIDER        3
#define R_W_VSLIDER        4
#define R_W_FRAME          5
#define R_W_VMETER         6
#define R_W_DECKGAUGE      7
#define R_W_DECKWAVE       8

#define R_AUTO_FOCUS     0x00040  /* focus_flag is set auto on mouseover */

/*========================================================================
 * struct rwid
 *
 *
 *========================================================================*/
typedef struct _rwid {

  /*=[id]===============================================*/

  int type;
  int windex;   /* widget index for table */
  int wdata;    /* user data */
  struct _rwid* parent;
  rchar80 name;

  /*=[geometry]==========================================*/

  double wanted_x;
  double wanted_y;
  double wanted_w;
  double wanted_h;
  int x;
  int y;
  int w;
  int h;

  /*=[render]============================================*/

  rstyle* style;
  ruint32 render_spec;  /* R_AUTO_FOCUS ... */

  rlsrcairogl textures;

  void (*f_draw)(  struct _rwid* );

  int htex_factor;
  int vtex_factor;

  /*=[ctrl]===============================================*/

  void (*f_retrigger)(  struct _rwid* );
  double previousxy_val;
  void (*f_clic_handler)( struct _rwid*, int button_id, int button_state);
  void (*f_wheel_up)( struct _rwid*);
  void (*f_wheel_down)( struct _rwid*);
  void (*f_fire_left)( const int  );
  void (*f_fire_right)( const int  );
  void (*f_fire_over_in)( const int  );
  void (*f_fire_over_out)( const int  );
  void (*f_fire_wheel_up)( const int  );
  void (*f_fire_wheel_down)( const int  );
  void (*f_fire_wheel_center)( const int  );

  rdh_int* state_dh;
  rdh_double* normx_dh;
  rdh_double* normy_dh;
  rdh_char255* label_dh;

  rdh_int focus_dh;

  double step;


} rwid;
/*========================================================================
 * rwid_init
 *========================================================================*/
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
                size_t nb_tex,
                const int htex_factor,
                const int vtex_factor );

/*========================================================================
 * rwid_new
 *========================================================================*/
rwid* rwid_new(  const char* name,
                 const char* parent_name,
                 const int type,
                 const double x,
                 const double y,
                 const double w,
                 const double h,
                 void (*f_clic_handler)( rwid* wid, int button_id, int button_state ),
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
                 const int vtex_factor );

rssstyle* rwid_style_get( rwid* wid );

#define rwid_w( WID ) WID->w
#define rwid_h( WID ) WID->h
#define rwid_label_get( WID ) WID->label_dh->value
#define rwid_normx_get( WID ) WID->normx_dh->value
#define rwid_normy_get( WID ) WID->normy_dh->value


void rwid_style_set( rwid* wid, rstyle*  );


rwid* rwid_get(const char* name);
int rwid_state_get( const rwid* wid );

void rwid_bb_compute( rwid* wid );

rRGB* rwid_pseudo_alpha_color( rwid* wid  );

void rwid_style_check(rwid* wid);

unsigned int rwid_color(const rwid* wid, const int type );

void rwid_texalloc( rwid * wid );

void rwid_texreset(rwid* wid);


void rwid_blit_black( rwid * wid );
void rwid_retrigger(rwid* wid);

RLIST_DECL( rlswid, rwid )

#endif /*__RWID_H__*/



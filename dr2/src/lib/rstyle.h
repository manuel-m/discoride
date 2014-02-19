#ifndef __RSTRYLE_H__
#define __RSTRYLE_H__

/*********************************/
/*    defines                    */
/*********************************/
#define R_H_LEFT         0x0001
#define R_H_RIGHT        0x0002
#define R_H_CENTER       0x0004
#define R_V_DOWN         0x0008
#define R_V_UP           0x0010
#define R_V_CENTER       0x0020
#define R_TXT_STROKE     0x0040
#define R_CIRCLE         0x0080
#define R_NO_BG          0x0100 /*for label */


#define R_CENTER         ( R_H_CENTER | R_V_CENTER )
/*********************************/
/*    dependencies includes      */
/*********************************/


/*********************************/
/*    implementation includes    */
/*********************************/
#include "rcolor.h"
#include "rlist.h"

/*********************************/
/*    style                      */
/*********************************/
typedef struct _rssstyle {
  int design_font_size;
  int design_stroke_size;
  double design_corner_curvature_radius;
  double active_font_size;
  double active_stroke_size;
  double active_corner_curvature_radius;
  ruint32 render_flags;
  int design_slider_w_size;
  int design_slider_h_size;
  double active_slider_w_size;
  double active_slider_h_size;
  rcolors colors;
} rssstyle;


#define R_SSSTYLES     2
#define R_SSSNORMAL    0
#define R_SSSFOCUS     1
#define R_SSS_ALL      2

typedef struct _rsstyle {
  /* 0 : normal */
  /* 1 : focus */
  rssstyle ssstyles[R_SSSTYLES];
} rsstyle;


RLIST_DECL( rlssstyle, rsstyle )

typedef struct _rstyle {
  rchar255 name;
  rlssstyle sstyles;
} rstyle;

RLIST_DECL( rlsstyle, rstyle )

void rstyle_init(rstyle * style,
                 const char* name,
                 const char* parent_name,
                 const size_t custom_states  );

rstyle* rstyle_new(const char* name,
                   const char* parent_name,
                   const size_t custom_states  );

rstyle* rstyle_get(const char* name);

void rsstyle_init(rsstyle * style );
rsstyle* rsstyle_new(void);

void rstyle_refresh(rstyle * style,
                    const double ratio,
                    const double ratio_w,
                    const double ratio_h  );


void rstyle_argb_set(rstyle * style,
                     const int state,
                     const rcolor_type color_type,
                     const ruint32 color,
                     const int normal_focus_state  );


void rstyle_config(void);
void rstyle_preinit(void);


#define rstyle_set( STYLE, STATE, PARA, VALUE, NORMAL_FOCUS ) \
  { \
    R_ASSERT_ERROR( STYLE ) \
    R_ASSERT_ERROR( (NORMAL_FOCUS >= 0 ) && (NORMAL_FOCUS <= R_SSS_ALL )  ) \
    if ( ( NORMAL_FOCUS == R_SSSNORMAL ) || ( NORMAL_FOCUS == R_SSSFOCUS )) { \
      STYLE->sstyles.data[STATE]->ssstyles[NORMAL_FOCUS].PARA = VALUE; \
    } else { \
      STYLE->sstyles.data[R_SSSNORMAL]->ssstyles[NORMAL_FOCUS].PARA = VALUE; \
      STYLE->sstyles.data[R_SSSFOCUS]->ssstyles[NORMAL_FOCUS].PARA = VALUE; \
    } \
  }

#define rstyle_set_all( STYLE, PARA, VALUE ) \
  { \
    size_t i, j; \
    for ( i = 0; i < STYLE->sstyles.len; i++) { \
      for ( j = 0; j < R_SSSTYLES; j++)  \
        STYLE->sstyles.data[i]->ssstyles[j].PARA = VALUE; \
    } \
  }

#define rstyle_string_set( STYLE, STATE, PARA, STRING, NORMAL_FOCUS ) \
  { \
    R_ASSERT_ERROR( STYLE ) \
    R_ASSERT_ERROR( (NORMAL_FOCUS >= 0 ) && (NORMAL_FOCUS <= R_SSS_ALL )  ) \
    if ( ( NORMAL_FOCUS == R_SSSNORMAL ) || ( NORMAL_FOCUS == R_SSSFOCUS )) { \
      rstrcpy(STYLE->sstyles.data[STATE]->ssstyles[NORMAL_FOCUS].PARA, STRING); \
    } else \
    { \
      rstrcpy(STYLE->sstyles.data[STATE]->ssstyles[R_SSSNORMAL].PARA, STRING); \
      rstrcpy(STYLE->sstyles.data[STATE]->ssstyles[R_SSSFOCUS].PARA, STRING); \
    } \
  }

#define rstyle_string_set_all( STYLE, STATE, PARA, STRING ) \
  { \
    int i, j; \
    for ( i = 0; i < STYLE->sstyles.len; i++) { \
      for ( j = 0; j < R_SSSTYLES; j++)  \
        rstrcpy(STYLE->sstyles.data[i]->ssstyles[j].PARA, STRING); \
    } \
  }


#define rstyle_argb_set_all( STYLE, CTYPE, VALUE ) \
  { \
    int i; \
    for ( i = 0; i < STYLE->sstyles.len; i++) { \
      style->sstyles.data[i]->colors[CTYPE] = VALUE; \
    } \
  }


#endif /*__RSTRYLE_H__*/



#include "rstack_proxy.h"
#include "rdeckgauge.h"
#include "rglfw_cairo.h"

#define R_TEX_WAVEFORM 0
#define R_TEX_LABEL 1

/*========================================================================
 * rdeckgauge_draw
 *========================================================================*/
void rdeckgauge_draw(rwid* wid)
{
  rcairogl* cairogl_wf = rlsrcairogl_get(&wid->textures, R_TEX_WAVEFORM );
  rcairogl* cairogl_txt = rlsrcairogl_get(&wid->textures, R_TEX_LABEL );

  int draw = 0;

  /* texture waveform render */
  if ( rattr( resize_flag ) ||  rdh_changed( wid->state_dh ) ) {

    rcairogl_texreset( cairogl_wf );
    rdeckgauge_texrender_waveform(wid);
    draw = 1;

  }

  /* texture text render */
  if ( rattr( resize_flag ) ||  rdh_changed( wid->label_dh ) ) {

    rcairogl_texreset( cairogl_txt );
    rglfw_label(wid, cairogl_txt, R_TEX_LABEL);

    rcairogl_texbind( cairogl_txt, wid->w, wid->h );
    rcairogl_texblit(cairogl_txt,
                     wid->x,
                     wid->y,
                     wid->w,
                     wid->h);
    draw = 1;
  }


  /* vertex render */
  if ( draw ||  rattr( resize_flag ) || rdeckgauge_shall_compute_vertex(wid) ) {

    rcairogl_texbind( cairogl_wf, wid->w, wid->h );
    rcairogl_texblit( cairogl_wf,
                      wid->x,
                      wid->y,
                      wid->w,
                      wid->h);


    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);

    glBlendFunc( GL_ONE, GL_ONE_MINUS_SRC_ALPHA );

    rcairogl_texbind( cairogl_txt, wid->w, wid->h );
    rcairogl_texblit( cairogl_txt,
                      wid->x,
                      wid->y,
                      wid->w,
                      wid->h);

    glDisable(GL_BLEND);

    rdeckgauge_vertexrender(wid);

  }
}
/*========================================================================
 * rdeckgauge_texrender_waveform
 *========================================================================*/
void rdeckgauge_texrender_waveform(rwid* wid)
{
  const int state = rdh_get(wid->state_dh);
  rcairogl* cairogl = rlsrcairogl_get(&wid->textures, R_TEX_WAVEFORM );

  R_ASSERT_ERROR( cairogl )
  R_ASSERT_ERROR( wid )

  if ( (state == R_CHAN_STOP) || (state == R_CHAN_PLAY) ) {
    rchan * chan = &(rattr(chans)[wid->wdata]);
    const double w = wid->w;
    const double h_half = wid->h * 0.5;

    /* wave display buffer compute */
    if ( chan->buffer_len > 0 ) {
      cairo_t* cr = cairogl->cr;

      const double step = (double)chan->buffer_len / (double)w;
      int i;
      cairo_set_source_rgb(cr, 0.3, 0.3, 0.3);
      cairo_set_line_width(cr, 1);

      for (i = 0; i < w; i++) {
        const double b0 = ceil(i * step);
        const double b1 = ceil(b0 + step);
        int j;
        S_MIX_HW_SMP_t min = 1.0f;
        S_MIX_HW_SMP_t max = -1.0f;

        for (j = (int)b0; j < (int)b1; j += 64) {
          const S_MIX_HW_SMP_t val = chan->left[j];
          if (val > max ) {
            max = val;
          }else {
            if (val < min ) {
              min = val;
            }
          }
        }
        cairo_move_to( cr, i, (h_half * (double)min) + h_half );
        cairo_line_to( cr, i, (h_half * (double)max) + h_half );
      }
      cairo_stroke(cr);
    }
  }

}
/*========================================================================
 * rdeckgauge_vertexrender
 *========================================================================*/
void rdeckgauge_vertexrender(rwid* wid)
{
  const double X_VAL = rwid_normx_get( wid );
  const double x = wid->x;
  const double y = wid->y;
  const double w = wid->w;
  const double h = wid->h;
  const double XG =  w *  X_VAL;
  rssstyle* sss = rwid_style_get( wid );

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE);
  glBlendEquation(GL_FUNC_SUBTRACT);

  glBegin(GL_QUADS);
  rglColor3( sss->colors[rcolor_fg] );
  glVertex2d(x, y);
  glVertex2d(x + XG, y);
  glVertex2d(x + XG, y + h);
  glVertex2d(x, y + h);
  glEnd();

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR  );
  glBlendEquation(GL_FUNC_ADD);

  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex2d(x + XG, y );
  glVertex2d(x + XG, y + h );
  glVertex2d(x + w, y + h );
  glVertex2d(x + w, y );
  glEnd();

  glDisable(GL_BLEND);

}
/*========================================================================
 * rdeckgauge_wheel_up
 *========================================================================*/
void rdeckgauge_wheel_up(rwid* wid)
{
  const double val = rdh_get(wid->normx_dh);
  const int state = rdh_get(wid->state_dh);

  if ( state == R_CHAN_LOADING_STOP || state == R_CHAN_LOADING_PLAY) {
    return;
  }

  if ( val < (1 - wid->step) ) {
    rdh_double_set( wid->normx_dh, val + wid->step );
  }else {
    rdh_double_set( wid->normx_dh, 1.0 );
  }
  rdeckgauge_chan_pos_norm( wid );
}
/*========================================================================
 * rdeckgauge_wheel_down
 *========================================================================*/
void rdeckgauge_wheel_down(rwid* wid)
{
  const double val = rdh_get(wid->normx_dh);
  const int state = rdh_get(wid->state_dh);

  if ( state == R_CHAN_LOADING_STOP || state == R_CHAN_LOADING_PLAY) {
    return;
  }

  if ( val > wid->step ) {
    rdh_double_set( wid->normx_dh, val - wid->step );
  }else {
    rdh_double_set( wid->normx_dh, 0.0 );
  }
  rdeckgauge_chan_pos_norm( wid );
}
/*========================================================================
 * rdeckgauge_shall_compute_vertex
 *========================================================================*/
int rdeckgauge_shall_compute_vertex(rwid* wid)
{
  rchan * chan = &(rattr(chans)[wid->wdata]);
  rdh_double* chan_pos_norm = (wid->wdata == RDECK_A) ? rdh_addr( chan0_pos_norm ) : rdh_addr( chan1_pos_norm );

  R_ASSERT_ERROR( wid )
  R_ASSERT_ERROR( chan )

  if ( chan->buffer_len ) {
    rdh_double_set( chan_pos_norm, ( chan->audio_buffer_offset / chan->buffer_len ) );
    if ( rdh_changed( chan_pos_norm )) {
      return 1;
    }
  }
  return rdh_changed( wid->state_dh );
}
/*========================================================================
 * rdeckgauge_shall_compute_tex
 *
 *
 *========================================================================*/
int rdeckgauge_shall_compute_tex(rwid* wid)
{
  R_ASSERT_ERROR( wid )

  if ( rdh_changed( wid->label_dh )) {
    return 1;
  }

  if ( rdh_changed( wid->state_dh )) {
    return 1;
  }

  return 0;
}
/*========================================================================
 * rdeckgauge_mouse_handler
 *========================================================================*/
void rdeckgauge_mouse_handler(rwid* wid, int button_id, int button_state)
{
  if ( button_state == GLFW_PRESS ) {

    if ( ( button_id == GLFW_MOUSE_BUTTON_LEFT ) || ( button_id == GLFW_MOUSE_BUTTON_RIGHT )) {

      const double x_pushed = (double)rattr(mouse_x);
      const double x1 = wid->x;
      const double x2 = wid->x + wid->w;
      const int state = rdh_get(wid->state_dh);

      /* forbid nav during loading */
      if ( state == R_CHAN_LOADING_STOP || state == R_CHAN_LOADING_PLAY) {
        return;
      }

      if ( x_pushed < x1 ) {
        rdh_double_set( wid->normx_dh, 0.0 );
      } else {
        if ( x_pushed > x2 ) {
          rdh_double_set( wid->normx_dh, 1.0 );
        }else{
          if ( (x2 - x1) != 0 ) {
            rdh_double_set( wid->normx_dh, ( x_pushed - x1 ) / ( x2 - x1 ) );
          }
        }
      }
      R_ASSERT_ERROR_INFO( wid->normx_dh, wid->name );
      rdeckgauge_chan_pos_norm( wid );
      return;
    }

    /* wheel center */
    if ( button_id == GLFW_MOUSE_BUTTON_MIDDLE ) {
      if ( wid->f_fire_wheel_center ) {
        wid->f_fire_wheel_center( wid->wdata );
      }else {
        rdh_double_reinit( wid->normx_dh );
      }
    }
    rdeckgauge_chan_pos_norm( wid );
  }
}
/*========================================================================
 * rdeckgauge_chan_pos_norm
 *========================================================================*/
void rdeckgauge_chan_pos_norm(rwid* wid)
{
  rchan * chan = &(rattr(chans)[wid->wdata]);
  rdh_double* chan_pos_norm = (wid->wdata == RDECK_A) ? rdh_addr( chan0_pos_norm ) : rdh_addr( chan1_pos_norm );

  if ( chan->buffer_len ) {
    chan->audio_buffer_offset =  (double)chan->buffer_len * rdh_get( chan_pos_norm );
    chan->wavebuffer_offset = chan->audio_buffer_offset;
  }
}

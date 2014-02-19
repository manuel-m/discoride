#include "rstack_proxy.h"
#include "rdeckwave4.h"
#include "rjog.h"

/*========================================================================
 * rdeckwave4_draw
 *
 *
 *========================================================================*/
void rdeckwave4_draw(rwid* wid)
{
  rchan * chan = &(rattr(chans)[wid->wdata]);

  if ( rattr( resize_flag ) ||  rjog_shall_compute_tex(wid) ) {
    rwid_blit_black( wid );
    rdeckwave4_postfx(wid);
  }

  if ( rattr( resize_flag ) || chan->buffer_len ) {
    rwid_blit_black( wid );
    rdeckwave4_vertexrender(wid);
    rdeckwave4_postfx(wid);
  }
}
/*========================================================================
 * rdeckwave4_postfx
 *
 *
 *========================================================================*/
void rdeckwave4_postfx(rwid * wid)
{
  const int x = wid->x;
  const int y = wid->y;
  const int w = wid->w;
  const int w_half = wid->w >> 1;
  rssstyle* sss = rwid_style_get( wid );
  rRGB* prgb = &sss->colors[rcolor_fg];
  rHSL hsl;
  rRGB rgb_mod;

  rglColor3(sss->colors[rcolor_fg]);
  rcolor_rgb_2_hsl(prgb, &hsl);
  hsl.l *= 0.3;
  rcolor_hsl_2_rgb(&hsl,  &rgb_mod);

  glEnable(GL_BLEND);
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR  );
  glBlendEquation(GL_FUNC_ADD);

  glBegin(GL_QUADS);

  rgb_mod.a = 0;
  rglColor4(rgb_mod);
  glVertex2d(x, y);
  glVertex2d(x, y + wid->h);
  rgb_mod.a = 1;
  rglColor4(rgb_mod);
  glVertex2d(x + w_half, y + wid->h);
  glVertex2d(x + w_half, y );

  glVertex2d(x + w_half, y);
  glVertex2d(x + w_half, y + wid->h);

  rgb_mod.a = 0;
  rglColor4(rgb_mod);

  glVertex2d(x + w, y + wid->h);
  glVertex2d(x + w, y );

  rgb_mod.a = 0.5;
  rglColor4(rgb_mod);

  glEnd();

  glDisable(GL_BLEND);

  glColor3f(0.6f, 0.6f, 0.6f);

  glBegin(GL_LINES);
  glVertex2d(x + w_half, y );
  glVertex2d(x + w_half, y + wid->h);

  glEnd();

}
/*========================================================================
 * rdeckwave4_vertexrender
 *
 *
 *========================================================================*/
void rdeckwave4_vertexrender(rwid * wid)
{
  const int x = wid->x;
  const int y = wid->y;
  const int w = wid->w;
  const int h = wid->h;
  const int h_half = wid->h >> 1;
  const int w_half = wid->w >> 1;
  const int h_half_y = h_half + y;
  int i;
  int x2;
  rchan * chan = &(rattr(chans)[wid->wdata]);
  rssstyle* sss = rwid_style_get( wid );
  rRGB* prgb = &sss->colors[rcolor_fg];
  rHSL hsl;
  rRGB rgb_mod;
  rdh_int* chan_state = (!wid->wdata) ? rdh_addr( chan0_state ) : rdh_addr( chan1_state );
  rtrack* track = chan->track;

  const int state = rdh_get( chan_state );

  if ( ( state != R_CHAN_LOADING_STOP ) &&  ( state != R_CHAN_LOADING_PLAY )   ) {
    int offset_waveform = ((int)(chan->wavebuffer_offset) / R_WAVEFORM_SAMPLING);

    glBegin(GL_LINES);

    i = w;
    x2 = x;
    do {
      const float min = (offset_waveform > w_half) ? chan->waveform_min[offset_waveform - w_half ] : 0;
      const float max = (offset_waveform > w_half) ? chan->waveform_max[offset_waveform - w_half ] : 0;

      rcolor_rgb_2_hsl(prgb, &hsl);

      hsl.l = 0.1 + (0.5 * max);
      hsl.h *= (0.9 + (0.1 * max));
      rcolor_hsl_2_rgb(&hsl,  &rgb_mod);

      rglColor3(rgb_mod);

      glVertex2d(x2, h_half_y + ( min  * h_half));
      glVertex2d(x2, h_half_y + ( max * h_half));

      x2++;
      offset_waveform++;
    } while (--i);
    glEnd();
  }

  if ( track  ) {

    const double off_min = chan->wavebuffer_offset - (w_half * R_WAVEFORM_SAMPLING);
    const double off_max = off_min + w * R_WAVEFORM_SAMPLING;
    const double marker_size = (w * 0.01 );

    glColor3f(0.7f, 0.7f, 0.7f);

    /* marker out */
    {
      const double loop_out = track->loop_out;

      if ( (loop_out < off_max) && (loop_out >  off_min) ) {
        const double x_pos =
          x + ( w * (( loop_out - chan->wavebuffer_offset + (w_half * R_WAVEFORM_SAMPLING)  )
                     / ( off_max - off_min ) ) );
        glBegin(GL_TRIANGLES);
        glVertex2d(x_pos, y +  h  );
        glVertex2d(x_pos + marker_size, y +  h  );
        glVertex2d(x_pos, y +  h - marker_size );
        glEnd();
      }
    }

    /* marker in */
    if (track) {
      const double loop_in = track->loop_in;

      if ( (loop_in < off_max) && (loop_in >  off_min) ) {
        const double x_pos =
          x + ( w * (( loop_in - chan->wavebuffer_offset + (w_half * R_WAVEFORM_SAMPLING) )
                     / ( off_max - off_min ) ) );
        glBegin(GL_TRIANGLES);
        glVertex2d(x_pos, y +  h  );
        glVertex2d(x_pos - marker_size, y +  h  );
        glVertex2d(x_pos, y +  h - marker_size );
        glEnd();
      }
    }
  }
  chan->last_audio_buffer_offset = chan->audio_buffer_offset;
}
/*========================================================================
 * rdeckwave4_wheel_up
 *========================================================================*/
void rdeckwave4_wheel_up(rwid * wid)
{
  (void)wid;
}
/*========================================================================
 * rdeckwave4_wheel_down
 *========================================================================*/
void rdeckwave4_wheel_down(rwid * wid)
{
  (void)wid;
}
/*========================================================================
 * rdeckwave4_mouse_handler
 *========================================================================*/
void rdeckwave4_mouse_handler(rwid * wid, int button_id, int button_state)
{
  const int chan_state = (!wid->wdata) ? rval_get( chan0_state ) : rval_get( chan1_state );

  /* playing => punch */
  if ( chan_state == R_CHAN_LOADING_PLAY || chan_state == R_CHAN_PLAY ) {
    rdh_double* punch = (!wid->wdata) ? rdh_addr( chan0_punch ) : rdh_addr( chan1_punch );

    if ( button_state == GLFW_PRESS ) {

      switch ( button_id ) {
      case GLFW_MOUSE_BUTTON_LEFT:
      {
        rdh_double_set( punch, 1 - R_PUNCH);
      }
      break;
      case GLFW_MOUSE_BUTTON_RIGHT:
      {
        rdh_double_set( punch, 1 + R_PUNCH );
        break;
      }
      default:
      {
        ;
      }
      }
    }else {
      rdh_double_set( punch, 1);
    }
  }
  /* not playing => loop marker */
  else{

    rchan * chan = &(rattr(chans)[wid->wdata]);
    rtrack* track = chan->track;
    const double x_pushed = (double)rattr(mouse_x);

    const double pos = rchan_pos( chan,
                                  wid->x,
                                  wid->w,
                                  x_pushed );

    if ( button_id == GLFW_MOUSE_BUTTON_LEFT ) {

      track->loop_in = pos;
      if ( pos > track->loop_out ) {
        track->loop_out = pos;
      }

    }else {

      track->loop_out = pos;
      if ( pos < track->loop_in ) {
        track->loop_in = pos;
      }
    }
  }
}


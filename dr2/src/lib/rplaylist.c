#include "rstack_proxy.h"

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_init(void)
{
  /*
     rplaylist* pl = &(rattr( playlist ));
     R_ASSERT_ERROR( pl );
   */
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_register_widget(const char* label_name,
                               const char* duration_name )
{
  rplaylist* playlist = &(rattr( playlist ));

  /* label */
  {
    rwid* wid =  rwid_get(label_name);
    rlswid* wids = &(playlist->wids_label );

    R_ASSERT_ERROR_INFO( wid, label_name );

    rlswid_add( wids, wid);
  }
  /* duration */
  {
    rwid* wid =  rwid_get(duration_name);
    rlswid* wids = &(playlist->wids_duration );

    R_ASSERT_ERROR_INFO( wid, duration_name );

    rlswid_add( wids, wid);
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
/* retrieve track absolute pos with widget offset */
size_t rplaylist_pos_get( const size_t woffset )
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );

  return (rval_get( playlist_pos ) + woffset) % (tracks->len);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rtrack* rplaylist_track_get( const size_t woffset,
                             size_t* pos )
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );

  R_ASSERT_ERROR( pos )
  * pos =  rplaylist_pos_get( woffset );
  return tracks->data[*pos];
}

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_track_update(rwid* wid_label,
                            rwid* wid_duration,
                            rtrack* track,
                            const size_t pos,
                            const int state)
{
  rdh_char255* dh_label;
  rdh_char255* dh_duration;
  rdh_int* dh_state;
  size_t j;
  rchar255 duration_buffer;

  R_ASSERT_ERROR( wid_label )
  R_ASSERT_ERROR( wid_duration )
  R_ASSERT_ERROR( track )

  if (!(track->state & R_TRACK_TAG_CHECKED )) {
    rtrack_tag( track );
  }

  duration_buffer[0] = '\0';

  if ( rtrack_tag_artist( track ) && rtrack_tag_title( track ) ) {
    sprintf(track->label, "%02d %s - %s    ", (int)pos, track->title, track->artist);
  }else {
    char *base = strrchr(track->filename, RFOLDER_SEP);
    if ( base ) {
      sprintf(track->label, "%02d %s ", (int)pos, (base + sizeof(char)) );
    }else {
      sprintf(track->label, "%02d %s ", (int)pos, track->filename);
    }
  }

  /* duration */
  rtrack_duration( track, &duration_buffer);

  /* strip weird char */
  j = strlen(track->label);
  while (--j) {
    if ( track->label[j] == '_') {
      track->label[j] = ' ';
    }
  }

  /* label update */
  {
    dh_label = wid_label->label_dh;
    R_ASSERT_ERROR_INFO( dh_label, wid_label->name )
    rdh_char255_strcpy( dh_label,  &track->label[0] );
  }

  /* duration update */
  {
    dh_duration = wid_duration->label_dh;
    R_ASSERT_ERROR_INFO( dh_duration, wid_duration->name )
    rdh_char255_strcpy( dh_duration,  duration_buffer );
  }

  /* state update */
  dh_state = wid_label->state_dh;
  R_ASSERT_ERROR_INFO( dh_state, wid_label->name )

#ifdef DEBUG
  rtrack_log( track );
#endif

  rdh_int_set( dh_state, state);
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rplaylist_wid_state(const size_t i,
                        const size_t pos)
{
  const size_t activated_index = rval_get( activated_playlist_wid_i);

  if ( i == activated_index && (rattr( playlist_focus )) ) {

    if (  rattr(dock0_loaded)  && ( rattr(dock0_track_index) == pos )  ) {
      return rpldock0_selected_state;
    }else{
      if ( rattr(dock1_loaded) && ( rattr(dock1_track_index) == pos )  ) {
        return rpldock1_selected_state;
      }else{
        return ractivated;
      }
    }

  } else{
    if ( rattr(dock0_loaded) && ( rattr(dock0_track_index) == pos )  ) {
      return rpldock0_state;
    }else{
      if ( rattr(dock1_loaded) && ( rattr(dock1_track_index) == pos )  ) {
        return rpldock1_state;
      }
    }
  }
  return rnormal;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_tracks_update(void)
{
  rplaylist* pl = &(rattr( playlist ));
  rlswid* wids_label = &(pl->wids_label );
  rlswid* wids_duration = &(pl->wids_duration );
  rlstrack* tracks = &(pl->tracks );
  rwid* wid_label;
  rwid* wid_duration;
  rtrack* track;
  size_t pos;
  size_t i;
  int state;
  const size_t maxlen = R_MIN( wids_label->len, tracks->len);

  for (i = 0; i < maxlen; i++) {

    wid_label = wids_label->data[i];
    wid_duration = wids_duration->data[i];

    track = rplaylist_track_get( i, &pos );
    R_ASSERT_ERROR( track )

    state = rplaylist_wid_state(i, pos);

    rplaylist_track_update( wid_label,
                            wid_duration,
                            track,
                            pos,
                            state);

  }
}




/*========================================================================
 * rplaylist_tag_decode_init
 *
 *
 *========================================================================*/
void rplaylist_tag_decode_init(void)
{
  rlstrack_iterator iter;
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  rtrack* track = rlstrack_first( &iter, tracks );
  int i = 0;

  while ( track && i < R_PLAYLIST_DISPLAY_LEN  ) {
    rtrack_tag( track );
    track = rlstrack_next( &iter );
    i++;
  }

  /* only if tracks .. will unlock playlist */
  if ( tracks->len ) {
    rval_set( rdh_int, playlist_state, rnormal );
    rval_set( rdh_int, playlist0_state, ractivated );
    rval_set( rdh_int, chan0_can_load, ractivated );
    rval_set( rdh_int, chan1_can_load, ractivated );
  }
  rplaylist_tracks_update();
}
/*========================================================================
 * rplaylist_tag_decode_callback_TS
 *
 *
 *========================================================================*/
int rplaylist_tag_decode_callback_TS(void* param)
{
  rlstrack_iterator iter;
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  rtrack* track = rlstrack_first( &iter, tracks );

  (void)param;

  while ( track  ) {
    rtrack_tag( track );
    track = rlstrack_next( &iter );
  }

  /* only if tracks .. will unlock playlist */
  if ( tracks->len ) {
    rval_set( rdh_int, playlist_state, rnormal );
    rval_set( rdh_int, playlist0_state, ractivated );
    rval_set( rdh_int, chan0_can_load, ractivated );
    rval_set( rdh_int, chan1_can_load, ractivated );
  }
  rplaylist_tracks_update();
  return 0;
}
void rplaylist_key_pgdown(void)
{
  rplaylist_pgdown(0);
}
void rplaylist_key_pgup(void)
{
  rplaylist_pgup(0);
}
void rplaylist_key_up(void)
{
  rplaylist_up(0);
}
void rplaylist_key_down(void)
{
  rplaylist_down(0);
}

/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_pgdown(const int val)
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  rlswid* wids = &(playlist->wids_label );
  const size_t step = rval_get( playlist_pos_step );
  size_t npos = rval_get( playlist_pos ) + step;

  (void)val;

  if ( (!tracks->len) || (wids->len > tracks->len) ) {
    return;
  }
  rval_set( rdh_size, playlist_pos, npos % tracks->len);
  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_pgup(const int val)
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  rlswid* wids = &(playlist->wids_label );
  size_t npos = rval_get( playlist_pos );
  const size_t step = rval_get( playlist_pos_step );

  (void)val;

  if ( (!tracks->len) || (wids->len > tracks->len) ) {
    return;
  }

  if (npos >= step  ) {
    npos -= step;
  }else {
    npos = tracks->len  - step;
  }
  rval_set( rdh_size, playlist_pos, npos);

  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_up(const int val)
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  size_t npos = rval_get( playlist_pos ) + 1;

  (void)val;

  if ( !(tracks->len > rplaylist_widgets)  ) {
    return;
  }

  rval_set( rdh_size, playlist_pos, npos % tracks->len);

  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rplaylist_down(const int val)
{
  rplaylist* playlist = &(rattr( playlist ));
  rlstrack* tracks = &(playlist->tracks );
  size_t npos = rval_get( playlist_pos );

  (void)val;

  if ( !(tracks->len > rplaylist_widgets)  ) {
    return;
  }

  if (npos >= 1  ) {
    npos--;
  }else {
    npos = tracks->len  - 1;
  }
  rval_set( rdh_size, playlist_pos, npos);

  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void f_playlist_fire_over_in(const int val)
{
  rval_set( rdh_size, activated_playlist_wid_i, val );
  rattr( playlist_focus ) = 1;
  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void f_playlist_fire_over_out(const int val)
{
  (void)val;
  rattr( playlist_focus ) = 0;

  /* TODO => filter on previous focused widget */
  rplaylist_tracks_update();
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void f_playlist_fire_left(const int val)
{
  rtrack* track;
  size_t pos;

  rattr( dock0_loaded ) = 1;
  rattr( dock0_track_index) = rplaylist_pos_get( val );

  rval_set( rdh_size, activated_playlist_wid_i, val );

  /* track selected */
  track = rplaylist_track_get( val, &pos );
  rattr( playlist_selected_track ) = track;

  rplaylist_tracks_update();

  if ( rval_get( chan0_can_load )   ) {
    rval_set( rdh_double, chan0_depitch, 0.5 );
    raudio_chan_load(0);
  }
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void f_playlist_fire_right(const int val)
{
  rtrack* track;
  size_t pos;

  rattr( dock1_loaded ) = 1;
  rattr( dock1_track_index) = rplaylist_pos_get( val );

  rval_set( rdh_size, activated_playlist_wid_i, val );

  /* track selected */
  track = rplaylist_track_get( val, &pos );
  rattr( playlist_selected_track ) = track;

  rplaylist_tracks_update();

  if ( rval_get( chan1_can_load )   ) {
    rval_set( rdh_double, chan1_depitch, 0.5 );
    raudio_chan_load(1);
  }
}

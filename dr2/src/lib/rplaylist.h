#ifndef __R_PLAYLIST_H__
#define __R_PLAYLIST_H__

/*========================================================================
 * includes
 *
 *
 *========================================================================*/
#include "rwid.h"
#include "rtrack.h"

/*========================================================================
 * defines
 *
 *
 *========================================================================*/
#define R_PLAYLIST_DISPLAY_LEN 8

#define rpldock0_state R_NB_RSTATE_STATES
#define rpldock1_state    1 + rpldock0_state
#define rpldock0_selected_state   1 + rpldock1_state
#define rpldock1_selected_state   1 + rpldock0_selected_state

#define rplaylist_widgets 8

typedef struct _rplaylist {

  int cpos;
  rlswid wids_label;
  rlswid wids_duration;
  rlstrack tracks;

} rplaylist;


void rplaylist_init(void);
void rplaylist_register_widget(const char* name, const char* duration_name );


/* helper to retreive track related to widget */
size_t rplaylist_pos_get( const size_t woffset );
rtrack* rplaylist_track_get( const size_t woffset, size_t* pos );

int rplaylist_wid_state(const size_t i, const size_t pos);

void rplaylist_track_update(rwid* wid_label,
                            rwid* wid_duration,
                            rtrack* track,
                            const size_t pos,
                            const int state);

void rplaylist_tracks_update(void);
void rplaylist_tag_decode_init(void);

int rplaylist_tag_decode_callback_TS(void* param);

void rplaylist_config(void);

void rplaylist_pgdown(const int);
void rplaylist_pgup(const int);
void rplaylist_up(const int);
void rplaylist_down(const int);

void rplaylist_key_pgdown(void);
void rplaylist_key_pgup(void);
void rplaylist_key_up(void);
void rplaylist_key_down(void);


void f_playlist_fire_left(const int);
void f_playlist_fire_right(const int);
void f_playlist_fire_over_in(const int);
void f_playlist_fire_over_out(const int);


#endif /* __R_PLAYLIST_H__ */




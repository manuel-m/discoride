#ifndef __R_PLAYABLE_H__
#define __R_PLAYABLE_H__

/*********************************/
/*    depedencies includes       */
/*********************************/
#include <taglib/tag_c.h>

/*********************************/
/*    implementation includes    */
/*********************************/
#include "rdata.h"
/********************************/
/*    flags                     */
/********************************/
#define R_TRACK_TAG_CHECKED      0x01
#define R_TRACK_ERROR            0x02
#define R_TRACK_CHECKED          0x04
#define R_TRACK_TAG_ERROR        0x08
#define R_TRACK_TAG_ARTIST       0x10
#define R_TRACK_TAG_TITLE        0x20

typedef struct {
  rchar255 filename;
  rchar255 artist;
  rchar255 title;
  rchar255 label;
  int filesize;
  double bpm;
  int state;
  int index;

  double loop_in;
  double loop_out;


  off_t samples;
  long sample_rate;

  long pos;

  /* track duration */
  int sec;
  int min;

  int dock_index;




  rdh_char255 label_dh;

  /*
     float_scaled_t pos;
     float_scaled_t pitch;
     float_scaled_t volume;
     float_obs_t pos_o;
     float_obs_t cue_o;
     float_obs_t end_o;
     float_obs_t pitch_o;
     float_obs_t volume_o;
     float_obs_t pitch_o;
     float_obs_t volume_o;
   */

} rtrack;


RLIST_DECL( rlstrack, rtrack )


rtrack * rtrack_new(rchar255 * filename);
void rtrack_init(rtrack* item, rchar255* filename);

void rtrack_short_title(rtrack* track, rchar255 * out);
void rtrack_duration(rtrack* track, rchar255 * out);
void rtrack_pos(rtrack* track, rchar255 * out);


void rtrack_log( rtrack* track );



int rtrack_tag( rtrack* entry );

#define rtrack_url_error(ITEM) ( ITEM->state & R_TRACK_ERROR )
#define rtrack_url_checked(ITEM) ( ITEM->state & R_TRACK_CHECKED )
#define rtrack_tag_checked(ITEM) ( ITEM->state & R_TRACK_TAG_CHECKED )
#define rtrack_tag_error(ITEM) ( ITEM->state & R_TRACK_TAG_ERROR )
#define rtrack_tag_artist(ITEM) ( ITEM->state & R_TRACK_TAG_ARTIST )
#define rtrack_tag_title(ITEM) ( ITEM->state & R_TRACK_TAG_TITLE )





#endif /* __R_PLAYABLE_H__ */



#include "rstack_proxy.h"

RLIST_IMPL( rlstrack, rtrack )

/*========================================================================
 * rtrack_duration
 *========================================================================*/
void rtrack_duration(rtrack* track, rchar255 * out)
{
  R_ASSERT_ERROR( track )
  R_ASSERT_ERROR( out )

  /* duration */
  if ( track->sample_rate ) {
    long int all_sec = ( track->samples / track->sample_rate );
    track->sec = all_sec % 60;
    track->min = ( all_sec - track->sec )  / 60;
    if ( track->sec || track->min ) {
      sprintf(out[0], " %02d:%02d", track->min, track->sec);
    }else {
      (*out)[0] = '\0';
    }
  }
}
/*========================================================================
 * rtrack_pos
 *========================================================================*/
void rtrack_pos(rtrack* track, rchar255 * out)
{
  R_ASSERT_ERROR( track )
  R_ASSERT_ERROR( out )

  /* duration */
  if ( track->sample_rate ) {
    long int all_sec = ( track->pos / track->sample_rate );
    track->sec = all_sec % 60;
    track->min = ( all_sec - track->sec )  / 60;
    if ( track->sec || track->min ) {
      sprintf(out[0], " %02d:%02d", track->min, track->sec);
    }else {
      (*out)[0] = '\0';
    }
  }
}
/*========================================================================
 * rtrack_short_title
 *========================================================================*/
void rtrack_short_title(rtrack* track, rchar255 * out)
{
  size_t i;

  R_ASSERT_ERROR( track )
  R_ASSERT_ERROR( out )
  R_CLEAR( out, rchar255 )

  if (  rtrack_tag_title( track ) ) {
    sprintf(out[0], "%s", track->title);
  }else {
    char *base = strrchr(track->filename, RFOLDER_SEP);
    if ( base ) {
      sprintf(out[0], "%s ", (base + sizeof(char)) );
    }else {
      sprintf(out[0], "%s ", track->filename);
    }
  }

  for (i = 0;
       (i < strlen( out[0] ) )
       &&
       ( (*out)[i] != '(' );
       i++) {
    ;
  }
  (*out)[i] = '\0';

}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rtrack_init(rtrack* item, rchar255* filename)
{
  R_CLEAR( item, rtrack );
  rstrcpy(item->filename, filename[0]);

  /*
     SET_SCALED( out->pos,           0.0, 1.0, 0.0 );
     SET_SCALED( out->pitch,         0.85, 1.15,  1.0 );
     SET_SCALED( out->volume,        0.0,    1.0,    0.8  );
     out->end = 1.0;


     out->pos_o.current = &out->pos.current;
     out->pos_o.min = &out->pos.min;
     out->pos_o.max = &out->pos.max;

     out->cue_o.current = &out->cue;
     out->cue_o.min = &out->pos.min;
     out->cue_o.max = &out->pos.max;

     out->end_o.current = &out->end;
     out->end_o.min = &out->pos.min;
     out->end_o.max = &out->pos.max;

     out->pitch_o.current = &out->pitch.current;
     out->pitch_o.min = &out->pitch.min;
     out->pitch_o.max = &out->pitch.max;

     out->volume_o.current = &out->volume.current;
     out->volume_o.min = &out->volume.min;
     out->volume_o.max = &out->volume.max;
   */

}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
rtrack* rtrack_new(rchar255* filename)
{
  rtrack *out;
  struct stat filename_stat;

  R_ASSERT_ERROR( filename )

  if ( stat( filename[0], &filename_stat )) {
    return 0;
  }

  out = R_CALLOC(1, sizeof( rtrack ) );
  R_ASSERT_ERROR( out )


  rtrack_init(out, filename);

  return out;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
int rtrack_tag( rtrack* entry )
{
  TagLib_File *file;
  TagLib_Tag *tag;
  const TagLib_AudioProperties *properties;
  char* artist;
  char* title;

  R_ASSERT_ERROR( entry );

  if ( rtrack_tag_checked( entry ) ) {
    return 1;
  }
  entry->state |= R_TRACK_TAG_CHECKED;

  file = taglib_file_new(&entry->filename[0]);

  if (!file) {
    entry->state |= ( R_TRACK_TAG_CHECKED | R_TRACK_TAG_ERROR );
    return 0;
  }

  tag = taglib_file_tag(file);
  properties = taglib_file_audioproperties(file);
  (void)properties;

  artist = taglib_tag_artist(tag);
  title = taglib_tag_title(tag);

  if ( strlen(artist) ) {
    entry->state |= R_TRACK_TAG_ARTIST;
    rstrcpy_ASCII(entry->artist, artist);
  }else {
    rstrcpy(entry->artist, "?");
  }

  if ( strlen(title) ) {
    entry->state |= R_TRACK_TAG_TITLE;
    rstrcpy_ASCII(entry->title, title);
  }else {
    rstrcpy_ASCII(entry->title, entry->filename);
  }






#ifdef DEBUG
  printf("tag!! [%p] [%d] [%p] [%d] [%s] [%s] [%s]\n",
         artist,
         (int)strlen(artist),
         title,
         (int)strlen(title),
         &entry->filename[0],
         &entry->artist[0],
         &entry->title[0]);
#endif

  taglib_tag_free_strings();
  taglib_file_free(file);

  return 1;
}
/* -------------------------------------------------------------------------*/
/*                                                                          */
/*                                                                          */
/* -------------------------------------------------------------------------*/
void rtrack_log( rtrack* track )
{
  R_ASSERT_ERROR( track )
  printf("filename:[%s]\n", track->filename);

}


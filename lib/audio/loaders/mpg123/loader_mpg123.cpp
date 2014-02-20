/* 
 * File:   loader_mpg123.cpp
 * Author: jam
 * 
 * Created on 14 août 2013, 15:23
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "mpg123.h"
#include "drtrace.h"
#include "audio_defs.h"
#include "loader_mpg123.h"

namespace dr {

    loader_mpg123::loader_mpg123() {
    }

    loader_mpg123::~loader_mpg123() {
    }

    int loader_mpg123::loadv(const char* filename_, audio_buffer_t& audio_buffer_) {

        struct stat buf;
        size_t i;
        size_t current_buffer_size;
        int err = MPG123_OK;
        size_t len_copy;
        off_t samples = 0;
        size_t done = 0;
        int channels = 0, encoding = 0;
        size_t mp3_decode_buffer_size;
        unsigned char* mp3decode_buffer = NULL;
        mpg123_handle *mh = NULL;

        if (NULL == filename_) {
            R_ERR("missing filename");
            goto error;
        }

        if (0 > stat(filename_, &buf)) {
            R_ERR("can not read filename %s", filename_);
            goto error;
        }

        R_INFO("loading %s", filename_);

        audio_buffer_.len = 0;

        err = mpg123_init();
        mh = mpg123_new(NULL, &err);

        mp3decode_buffer = (unsigned char*) calloc(1, DR_MP3_DECODE_BUFFER);

        if (NULL == mp3decode_buffer) {
            R_ERR("mp3decode_buffer is NULL");
            goto error;
        }

        /* Let mpg123 work with the file, that excludes MPG123_NEED_MORE messages. */
        /* Peek into track and get first output format. */
        if (mpg123_open(mh, filename_) != MPG123_OK
                || mpg123_getformat(mh, 
                &audio_buffer_.sample_rate, 
                &channels, &encoding) != MPG123_OK) {
            R_ERR(mh == NULL ? mpg123_plain_strerror(err) : mpg123_strerror(mh));
            goto error;
        }

        mpg123_format_none(mh);
        mpg123_format(mh, audio_buffer_.sample_rate, channels, encoding);
        current_buffer_size = mpg123_outblock(mh);

        memset(mp3decode_buffer, 0, DR_MP3_DECODE_BUFFER);
        mp3_decode_buffer_size = current_buffer_size;

        do {

            err = mpg123_read(mh, mp3decode_buffer, mp3_decode_buffer_size, &done);
            len_copy = done / sizeof (short);

            /* feed big buffer */
            for (i = 0; i < len_copy; i++) {
                const S_MIX_HW_SMP_t val
                        = S_MEM_2_SMP((S_MEM_SMP_t) ((short*) (mp3decode_buffer))[i]);

                (i & 1) ? audio_buffer_.left[audio_buffer_.len] = val : audio_buffer_.right[audio_buffer_.len++] = val;
                
            }
            samples += (off_t) len_copy;

            if (audio_buffer_.len >= (DR_CHAN_BIG_BUFFER / DR_STEREO)) {
                /* quick break => buffer saturation ... at least got the begining */
                err = MPG123_DONE;
                R_WARN("%s too big to fit in memory", filename_);
            }

        } while (err == MPG123_OK);

        samples /= channels;
        

        /* cleaning */
        if (NULL != mp3decode_buffer) {
            free(mp3decode_buffer);
        }
        mpg123_delete(mh);
        mpg123_exit();

        return (0);

error:
        return (1);


    }

}


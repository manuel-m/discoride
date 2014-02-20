/* 
 * File:   audio_engine.h
 * Author: jam
 *
 * Created on 13 août 2013, 14:27
 */

#ifndef AUDIO_ENGINE_H
#define	AUDIO_ENGINE_H

#include "audio_defs.h"


namespace dr {

    class audio_backend;
    class audio_loader;
    class audio_process;

    class audio_engine {
    public:
        audio_engine(audio_backend&, audio_loader&, audio_process&);
        int open(size_t);
        int load(const char*, size_t);
        int close();
        ~audio_engine(); /* no subclass  */

    protected:
        audio_backend& m_backend;
        audio_loader& m_loader;
        audio_process& m_process;
        int init(size_t);
        void give_back();

    private:
        audio_engine();
        audio_engine(const audio_engine&);
        audio_engine &operator=(const audio_engine &);

    };

}

#endif	/* AUDIO_ENGINE_H */


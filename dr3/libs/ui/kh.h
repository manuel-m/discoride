/* 
 * File:   key.h
 * Author: jam
 *
 * Created on 3 août 2013, 16:41
 */

#ifndef KEY_H
#define	KEY_H

#include <map>
#include <stdint.h>
#include <string>

namespace dr {
    
    typedef void (key_callback_t)( int,int );
    
    typedef struct key_info_t_ {
        key_callback_t * cb;
        const char* help;
    } key_info_t;

    class key_handler {
    public:
        key_handler();
        ~key_handler();
        
        int addCallback(int,key_callback_t*,const char*);
        key_info_t* get_key_info(int);
        int init();
        int configure();
        
        void trigger_callback(int key_, int state);
        
    protected:

        uint32_t m_state;
        std::map<int,key_info_t*> m_callbacks;
        
    private:    
        
        key_handler(const key_handler&);
        key_handler &operator=(const key_handler &);
    };
    

}

#endif	/* KEY_H */


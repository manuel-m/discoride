#include "audio_proxy.h"
#include "ui.h"
#include "kh.h"

int dr::ui::configure() {
    return 0;
}

static void play0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_play_toggle(0);
}
static void reverse0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_reverse_toggle(0);
}
static void mute0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_mute_toggle(0);
}
static void pitchup0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_depitch(0,1);
}
static void pitchreset0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_pitch_reset(0);
}
static void pitchdown0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_depitch(0,0);
}
static void volumeup0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_volume(0,1);
}
static void volumedown0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_volume(0,0);
}
static void rewind0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_nav(0,1);
}
static void forward0_callback(int code_, int state_){
    (void)code_;(void)state_;
    audio_nav(0,0);
}

int dr::key_handler::configure(void) {
    
    addCallback((int)' ', play0_callback, "play");    
    addCallback((int)'s', pitchup0_callback, "pitch up"); 
    addCallback((int)'x', pitchdown0_callback, "pitch down");     
    addCallback((int)'z', pitchreset0_callback, "pitch reset");         
    addCallback((int)'d', volumeup0_callback, "volume up"); 
    addCallback((int)'c', volumedown0_callback, "volume down");     
    addCallback((int)'v', mute0_callback, "mute");     
    addCallback((int)'f', reverse0_callback, "reverse");     
    addCallback((int)'b', rewind0_callback, "rewind");     
    addCallback((int)'n', forward0_callback, "forward");         
    
    return 0;
}


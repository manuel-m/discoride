#!/usr/bin/python
# -*- coding: utf_8 -*-

import sqlite3 as lite
import sys, os, fnmatch

con = None
try:
	con = lite.connect('proxy.db')
	cur = con.cursor()    
	cur.execute('SELECT SQLITE_VERSION()')
	data = cur.fetchone()
	print "SQLite version: %s" % data 
	'''
	create table attribs
	'''
	cur.execute("DROP TABLE IF EXISTS attribs")
	cur.execute("""CREATE TABLE attribs (
	i INTEGER PRIMARY KEY  NOT NULL ,
	type TEXT NOT NULL ,
	name TEXT UNIQ NOT NULL , 
	def_value TEXT)""")
	'''
	create table datas
	'''
	cur.execute("DROP TABLE IF EXISTS datas")
	cur.execute("""CREATE TABLE datas (
	i INTEGER PRIMARY KEY  NOT NULL ,
	type TEXT NOT NULL ,
	name TEXT UNIQ NOT NULL,
	def_value TEXT)""") 
	'''
	create table mutex
	'''
	cur.execute("DROP TABLE IF EXISTS mutex")
	cur.execute("""CREATE TABLE mutex (
	i INTEGER PRIMARY KEY  NOT NULL ,
	name TEXT UNIQ NOT NULL)""") 	
	
	myattribs = (

	( 'rlswid', 'wids' ), 
	( 'rlswid', 'cwids' ),
	( 'rlsstyle', 'styles' ),
	( 'rkeys', 'keys' ),
	( 'rrsvg', 'rsvg_bg' ),
	( 'Uint32', 'tick_period' ),
	( 'Uint32', 'tick_resize_sampling' ),
	( 'Uint32', 'next_timer_tick' ),
	( 'Uint16', 'design_height' ),
	( 'Uint16', 'design_width' ),
	( 'Uint32', 'video_flags' ),
	( 'Uint16', 'saved_window_width' ),
	( 'Uint16', 'saved_window_height' ),
	( 'Uint32', 'tick' ),
	( 'rfunc', 'f_mouse_wheel_up' ),
	( 'rfunc', 'f_mouse_wheel_down' ),
	( 'rplaylist', 'playlist' ),
	( 'rtrack *', 'playlist_selected_track' ),
	( 'raudio', 'ad' ),
	( 'double', 'gain_factor' ),
	( 'double', 'depitch_factor' ),
	( 'rtrack *', 'chan0_track' ),
	( 'rtrack *', 'chan1_track' ),
	( 'int', 'alloc_disable' ),
	( 'rlschar255', 'args' ),
	( 'rlsfunc', 'ml_functions' ),
	)
	
	cur.executemany("INSERT INTO attribs VALUES(NULL, ?, ?, NULL)", myattribs)
	
	myattribsvalues = (

	( '50', 'tick_period'  ),
	( '200', 'tick_resize_sampling' ),
	( '50' , 'next_timer_tick'),
	( '2000', 'design_height',  ),
	( '2000', 'design_width',  ),
	( '( SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_DOUBLEBUF )', 'video_flags'  ),
	(  '3', 'gain_factor' ),
	( '0.15', 'depitch_factor'  ),
	( 'rplaylist_up', 'f_mouse_wheel_up'  ),
	( 'rplaylist_down', 'f_mouse_wheel_down'  ),
	)
	
	cur.executemany("UPDATE attribs SET def_value=? WHERE name=?", myattribsvalues)
	
	
	mydatas = (
        ( 'rdh_double' , 'ratio', None ),
        ( 'rdh_int' , 'quit', None ),
        ( 'rdh_Uint16' , 'desktop_height', None ),
        ( 'rdh_Uint16' , 'desktop_width', None ),
        ( 'rdh_double' , 'ratio_height', None ),
        ( 'rdh_double' , 'ratio_width', None ),
        ( 'rdh_Uint16' , 'window_height', None ),
        ( 'rdh_Uint16' , 'window_width', None ),
        ( 'rdh_int' , 'window_mode', 'RDISPLAY_WINDOW' ),
        ( 'rdh_char255' , 'window_caption','"discoride AA"' ),
        ( 'rdh_Uint32' , 'window_bg_color', '0xFF000000' ),
        ( 'rdh_double' , 'global_font_coef', '1.0' ),
        ( 'rdh_int' , 'button_activated_flag', None ),
        ( 'rdh_int' , 'button_enabled_flag', None ),
        ( 'rdh_char255' , 'button_label', None ),
        ( 'rdh_int' , 'display_state', 'rnormal' ),
        ( 'rdh_int' , 'playlist0_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist0_label', None ),
        ( 'rdh_int' , 'playlist1_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist1_label', None ),
        ( 'rdh_int' , 'playlist2_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist2_label', None ),
        ( 'rdh_int' , 'playlist3_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist3_label', None ),
        ( 'rdh_int' , 'playlist4_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist4_label', None ),
        ( 'rdh_int' , 'playlist5_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist5_label', None ),
        ( 'rdh_int' , 'playlist6_state','rdisabled' ), 
        ( 'rdh_char255' , 'playlist6_label', None ),
        ( 'rdh_int' , 'playlist7_state','rdisabled' ),
        ( 'rdh_char255' , 'playlist7_label', None ),
        ( 'rdh_int' , 'playlist_state','0' ),
        ( 'rdh_size' , 'playlist_pos','0' ),
        ( 'rdh_size' , 'playlist_pos_step','7' ),
        ( 'rdh_size' , 'activated_playlist_wid_i','0' ),
        ( 'rdh_char255' ,' playlist0_duration_label', None ),
        ( 'rdh_char255' , 'playlist1_duration_label', None ),
        ( 'rdh_char255' , 'playlist2_duration_label', None ),
        ( 'rdh_char255' , 'playlist3_duration_label', None ),
        ( 'rdh_char255' , 'playlist4_duration_label', None ),
        ( 'rdh_char255' , 'playlist5_duration_label', None ),
        ( 'rdh_char255' , 'playlist6_duration_label', None ),
        ( 'rdh_char255' , 'playlist7_duration_label', None ),
        ( 'rdh_int' , 'audio_state', 'rnormal' ),
        ( 'rdh_double' , 'xfader', '1.0' ),
        ( 'rdh_double' , 'xfader_step', '0.03' ),
        ( 'rdh_double' , 'chan0_vol', '1.0' ),
        ( 'rdh_double' , 'chan1_vol', '1.0' ),
        ( 'rdh_double' , 'chan0_gain', '0.0' ),
        ( 'rdh_double' , 'chan1_gain', '0.0' ),
        ( 'rdh_double' , 'chan0_depitch','0.5' ),
        ( 'rdh_double' , 'chan1_depitch','0.5' ),
        ( 'rdh_int' , 'chan0_state', 'rdisabled' ),
        ( 'rdh_int' , 'chan1_state', 'rdisabled' ),
        ( 'rdh_int' , 'chan0_play', 'rdisabled' ),
        ( 'rdh_int' , 'chan1_play', 'rdisabled' ),
        ( 'rdh_char255' , 'chan0_cue_label', '"cue"' ),
        ( 'rdh_char255' , 'chan1_cue_label', '"cue"' ),
        ( 'rdh_char255' , 'chan0_track_label','"track0"' ),
        ( 'rdh_char255' , 'chan1_track_label','"track1"' ),
        ( 'rdh_int' , 'chan0_cue_state','0' ),
        ( 'rdh_int' , 'chan1_cue_state','0' ),
        ( 'rdh_double' , 'chan0_pos_norm','0' ),
        ( 'rdh_double' , 'chan1_pos_norm','0' ),
        ( 'rdh_int' , 'chan0_can_load', 'rdisabled' ),
        ( 'rdh_int' , 'chan1_can_load', 'rdisabled' )
        )
    	
	
	cur.executemany("INSERT INTO datas VALUES(NULL, ?, ?, ?)", mydatas)
	
        #mutex	
	cur.execute("INSERT INTO mutex VALUES(NULL,'mp3_decode_mutex')")
	
	
	con.commit()


               
    
except lite.Error, e:
    
    print "Error %s:" % e.args[0]
    sys.exit(1)
    
finally:
    
    if con:
        con.close()

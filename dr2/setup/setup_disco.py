#!/usr/bin/python
# -*- coding: utf_8 -*-

import sqlite3 as lite
import sys, os, fnmatch, tagpy


# locate
def locate(pattern, root=os.curdir):
    '''Locate all files matching supplied filename pattern in and below
    supplied root directory.'''
    for path, dirs, files in os.walk(os.path.abspath(root)):
        for filename in fnmatch.filter(files, pattern):
            yield os.path.join(path, filename)
            
reload(sys)           
sys.setdefaultencoding( "utf8" )            

con = None
try:
	con = lite.connect('tracks.db')
	cur = con.cursor()    
	cur.execute('SELECT SQLITE_VERSION()')
	data = cur.fetchone()
	print "SQLite version: %s" % data 
	
	cur.execute("DROP TABLE IF EXISTS tracks")
	
	cur.execute("""CREATE TABLE tracks(
	md5 TEXT, 
	nbplays NUMERIC, 
	rank TEXT, 
	lastplay NUMERIC, 
	album TEXT, 
	year NUMERIC, 
	filename TEXT, 
	artist TEXT, 
	title TEXT, 
	cue NUMERIC, 
	duration TEXT, 
	bpm NUMERIC, 
	checksum TEXT, 
	loopstart0 NUMERIC, 
	loopend0 NUMERIC, 
	start NUMERIC, 
	end NUMERIC
	) """)    
	# locate test
	for fmp3 in locate("*.mp3", "/data/Music/"):
		f = tagpy.FileRef(fmp3)
		t = f.tag()
		#p = '{} -- {} -- {} -- {}'.format(t.title, t.artist, t.album, t.year )
		#print p
		cur.execute("""INSERT INTO tracks
		(filename, title, artist) 
		VALUES(:Filename, :Title, :Artist) """,
		{"Filename": unicode(fmp3), "Title": unicode(t.title), "Artist": unicode(t.artist.decode)})
	con.commit()
               
    
except lite.Error, e:
    
    print "Error %s:" % e.args[0]
    sys.exit(1)
    
finally:
    
    if con:
        con.close()

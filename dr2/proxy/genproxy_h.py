#!/usr/bin/python
# -*- coding: utf-8 -*-

import sqlite3 as lite
import sys


def header():
    print """
#ifndef __RPROXY_H__
#define __RPROXY_H__
    
/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rstack_proxy_include.h"


typedef struct _rbtin {
"""

def footer():
    print """


} rbtin;

rbtin btin;

void rproxy_init(void);
void rproxy_destroy(void);

#endif /* __RPROXY_H__ */

"""

con = None
con = lite.connect('proxy.db')


with con:
  
    con.row_factory = lite.Row
    cur = con.cursor()    

    header()
    
    #attribs
    cur.execute("SELECT * FROM attribs")
    rows = cur.fetchall()
    for row in rows:
        print "  rattrib_declare(  %s , %s )" % (row["type"], row["name"] )
        
    #datas
    cur.execute("SELECT * FROM datas")
    rows = cur.fetchall()
    for row in rows:
        print "  rdh_declare(  %s , %s )" % (row["type"], row["name"] )
        
    #mutex
    cur.execute("SELECT * FROM mutex")
    rows = cur.fetchall()
    for row in rows:
        print "  rmutex_stack_decl( %s )" % ( row["name"] )    
        
    #threads
    cur.execute("SELECT * FROM threads")
    rows = cur.fetchall()
    for row in rows:
        print "  rthread_stack_declare( %s )" % ( row["name"] )
        
    #timers
    cur.execute("SELECT * FROM timers")
    rows = cur.fetchall()
    for row in rows:
        print "  rtimer_stack_declare(  %s )" % ( row["name"] )        
        
        
    footer()
        
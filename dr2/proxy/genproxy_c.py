#!/usr/bin/python
# -*- coding: utf-8 -*-

import sqlite3 as lite
import sys,re


def header():
    print """
    
/*========================================================================
 * include
 *
 *
 *========================================================================*/
#include "rstack_proxy.h"

"""


con = None
con = lite.connect('proxy.db')


with con:
  
    con.row_factory = lite.Row
    cur = con.cursor()    

    header()
    print """
void rproxy_init(void) 
{
    """
    '''
    attribs
    '''
    cur.execute("SELECT * FROM attribs where def_value is NOT NULL")
    rows = cur.fetchall()
    for row in rows:
        print "  rattr( %s ) = %s;" % (row["name"], row["def_value"] )
    '''
    datas
    '''
    cur.execute("SELECT * FROM datas where def_value is NOT NULL")
    rows = cur.fetchall()
    expr = re.compile('"*"')
    for row in rows:
        print "  rinit( %s, %s, %s );" % ( row["type"], row["name"], row["def_value"] )
        
    '''
    mutex
    '''
    cur.execute("SELECT * FROM mutex")
    rows = cur.fetchall()
    expr = re.compile('"*"')
    for row in rows:
        print "  rmutex_stack_init( %s );" % ( row["name"] )        
        
            
    print """
}
void rproxy_destroy(void) 
{
    """

    '''
    mutex
    '''
    cur.execute("SELECT * FROM mutex")
    rows = cur.fetchall()
    expr = re.compile('"*"')
    for row in rows:
        print "  rmutex_stack_destroy( %s );" % (row["name"] ) 

    print """
}
    """           
        
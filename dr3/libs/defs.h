/* 
 * File:   drDefs.h
 * Author: jam
 *
 * Created on 20 mars 2013, 23:15
 */

#ifndef DRDEFS_H
#define	DRDEFS_H

#include <stdio.h>
#include <stdlib.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define DR_FREE(P) if( (P)) { free((P)); P = 0 ; } 
#define ASSERT_ZERO_GOTO_ERR(ZERO_EXPECTED) if((ZERO_EXPECTED) != 0) { fprintf(stderr, "[ ERR] %s:%d\n",__FILE__, __LINE__);goto err; }
#define ASSERT_ZERO_RETURN_ERR(ZERO_EXPECTED) if((ZERO_EXPECTED) != 0) return 1
    
#ifndef R_MIN
#define R_MIN(x, y) ((x) < (y) ? (x) : (y))
#endif
 
#define DR_INIT           (1u << 0) 
#define DR_CONFIGURE      (1u << 1) 
#define DR_OPEN           (1u << 2) 
#define DR_LOAD           (1u << 3) 
#define DR_ENABLE         (1u << 4) 
#define DR_CLOSE          (1u << 5) 
#define DR_BYPASS         (1u << 6) 
#define DR_REVERSE        (1u << 7) 
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* DRDEFS_H */


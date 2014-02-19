

#ifndef DRKEY_H
#define	DRKEY_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct _rKey_t {

  uint32_t state;
  int user_data;

  void (*f_run_key_down)(int);

} rKey_t;

#define DR_KEY_BIND(KCODE,STATE,USER_DATA,CB)\
   [KCODE] =      { \
    .state                            = STATE, \
    .user_data                        = USER_DATA, \
    .f_run_key_down                   = CB \
  }


#ifdef	__cplusplus
}
#endif

#endif	/* DRKEY_H */


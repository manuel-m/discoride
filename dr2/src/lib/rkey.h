#ifndef __RKEY_H__
#define __RKEY_H__

typedef struct _rkey {

  rdh_int* state_dh;
  void (*f_run)(void);

} rkey;

typedef struct _rkeys {
  rkey keys_down[RK_LAST];
  rkey keys_up[RK_LAST];
} rkeys;

void rkey_init_up( const int code, void (*f_run)(void), rdh_int* state_dh );
void rkey_init_down( const int code, void (*f_run)(void), rdh_int* state_dh );

void rkey_down_evt(int kindex);
void rkey_up_evt(int kindex);


#endif /* __RKEY_H__ */

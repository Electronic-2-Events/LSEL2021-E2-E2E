#ifndef FSM_CONTROL_ENTRADA_H
#define FSM_CONTROL_ENTRADA_H

#include <stdint.h>

#include "fsm.h"

typedef int (*fsm_control_entrada_NFC_func_t) (void);
typedef int (*fsm_control_entrada_s_bar_top_func_t) (void);
typedef int (*fsm_control_entrada_s_prox_func_t) (void);
typedef int (*fsm_control_entrada_s_bar_bottom_func_t) (void);


int identificadores[4] = {4545, 1111, 2442, 8943}; 


struct _fsm_control_entrada_t
{
    fsm_t fsm;
    fsm_control_entrada_NFC_func_t NFC;
    fsm_control_entrada_s_bar_top_func_t s_bar_top;
    fsm_control_entrada_s_prox_func_t s_prox;
    fsm_control_entrada_s_bar_bottom_func_t s_bar_bottom;
    int subir;
    int bajar;
    uint32_t next_timeout;
    int id;

};

typedef struct _fsm_control_entrada_t fsm_control_entrada_t;

void fsm_control_entrada_init(fsm_control_entrada_t *f,fsm_control_entrada_NFC_func_t NFC, fsm_control_entrada_s_bar_top_func_t s_bar_top,
fsm_control_entrada_s_prox_func_t s_prox, fsm_control_entrada_s_bar_bottom_func_t s_bar_bottom);

#endif // FSM_CONTROL_ENTRADA_H

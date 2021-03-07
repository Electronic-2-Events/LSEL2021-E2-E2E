#ifndef FSM_CONTROL_ENTRADA_H
#define FSM_CONTROL_ENTRADA_H

#include <stdint.h>

#include "fsm.h"

struct _fsm_control_entrada_t {
    fsm_t fsm;
};

typedef struct _fsm_control_entrada_t fsm_control_entrada_t;

void fsm_control_entrada_init(fsm_control_entrada_t* f);


#endif // FSM_CONTROL_ENTRADA_H

#ifndef FSM_CONTROL_H
#define FSM_CONTROL_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_control_check_func_t) (void);

struct _fsm_control_t {
    fsm_t fsm;
    fsm_control_check_func_t check;
    uint32_t timeout;
};
typedef struct _fsm_control_t fsm_control_t;

void fsm_control_init(fsm_control_t* f, fsm_control_check_func_t check);



#endif // FSM_CONTROL_H

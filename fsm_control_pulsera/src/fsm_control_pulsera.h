#ifndef FSM_CONTROL_PULSERA_H
#define FSM_CONTROL_PULSERA_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_control_pulsera_check_func_t) (void);

struct _fsm_control_pulsera_t {
    fsm_t fsm;
    fsm_control_pulsera_check_func_t check;
};
typedef struct _fsm_control_pulsera_t fsm_control_pulsera_t;

void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_check_func_t check);



#endif // FSM_CONTROL_H

#ifndef FSM_CONTROL_PULSERA_H
#define FSM_CONTROL_PULSERA_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_control_pulsera_check_func_t) (void);

enum menu_pulsera{
    SHOW_TIME,
    SHOW_WARNING
};


struct _fsm_control_pulsera_t {
    fsm_t fsm;
    uint8_t NFC_active;
    fsm_control_pulsera_check_func_t check;
    enum menu_pulsera menu;
};

typedef struct _fsm_control_pulsera_t fsm_control_pulsera_t;

void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_check_func_t check);



#endif // FSM_CONTROL_H

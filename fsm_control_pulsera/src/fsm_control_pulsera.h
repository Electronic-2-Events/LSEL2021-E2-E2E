#ifndef FSM_CONTROL_PULSERA_H
#define FSM_CONTROL_PULSERA_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_control_pulsera_get_time_func_t) (void);
typedef int (*fsm_control_pulsera_activation_func_t) (void);
typedef int (*fsm_control_pulsera_detects_no_contact_func_t) (void);

enum menu_pulsera{
    SHOW_TIME,
    SHOW_WARNING
};


struct _fsm_control_pulsera_t {
    fsm_t fsm;
    fsm_control_pulsera_get_time_func_t get_time;
    fsm_control_pulsera_activation_func_t activation;
    fsm_control_pulsera_detects_no_contact_func_t no_contact;
    uint8_t NFC_on;
    enum menu_pulsera menu;
};

typedef struct _fsm_control_pulsera_t fsm_control_pulsera_t;

void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_get_time_func_t get_time,
    fsm_control_pulsera_activation_func_t activation, fsm_control_pulsera_detects_no_contact_func_t no_contact);



#endif // FSM_CONTROL_H

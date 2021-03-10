#ifndef FSM_GESTIONCOLAS_INTERNAL_H
#define FSM_GESTIONCOLAS_INTERNAL_H

#include "fsm.h"

enum{
    READY,
    WAITING
};

int fsm_gestioncolas_check(fsm_t* f);

#endif
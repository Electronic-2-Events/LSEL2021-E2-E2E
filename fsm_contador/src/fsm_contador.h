#ifndef FSM_CONTADOR_H
#define FSM_CONTADOR_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_contador_solicitud_func_t)(void);
typedef int (*fsm_contador_listo_func_t)(void);

struct _fsm_contador_t {

    fsm_t fsm;
    fsm_contador_solicitud_func_t solicitud;
    fsm_contador_listo_func_t listo;
    uint32_t Personas; //Para contar lo maximo posible
};


typedef struct _fsm_contador_t fsm_contador_t;

void fsm_contador_init(fsm_contador_t* f, fsm_contador_solicitud_func_t solicitud, fsm_contador_listo_func_t listo);


#endif // FSM_CONTADOR_H

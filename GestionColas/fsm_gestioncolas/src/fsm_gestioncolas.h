#ifndef FSM_GESTIONCOLAS_H
#define FSM_GESTIONCOLAS_H

#include <stdint.h>
#include "fsm.h"

typedef int (*fsm_gestioncolas_solicitud_cola_func_t)(void);
typedef int (*fsm_gestioncolas_terminado_func_t)(void);

struct _fsm_gestioncolas_t{
    fsm_t fsm;
    fsm_gestioncolas_solicitud_cola_func_t solicitud_cola;
    fsm_gestioncolas_terminado_func_t terminado;
    uint8_t Solicitud;
    uint8_t Listo;
    uint8_t Orden;
    uint8_t Personas;
};

typedef struct _fsm_gestioncolas_t fsm_gestioncolas_t;

void fsm_gestioncolas_init(fsm_gestioncolas_t* f, fsm_gestioncolas_solicitud_cola_func_t solicitud_cola, fsm_gestioncolas_terminado_func_t terminado);


#endif // FSM_GESTIONCOLAS_H

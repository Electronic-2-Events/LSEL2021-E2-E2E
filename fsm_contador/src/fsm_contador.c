#include "fsm_contador.h"
#include "fsm_contador_internal.h"
#include <stddef.h>
#include "client.h"

//Entradas

static int fsm_solicitud (fsm_t*f)
{
    fsm_contador_t* fp = (fsm_contador_t*)f;

    if ( fp -> solicitud){

        return custom_solicitud ();

    }

    return 0;
}

static int fsm_listo (fsm_t*f)
{
    fsm_contador_t* fp = (fsm_contador_t*)f;
    
    if ( fp -> listo){

        return custom_listo ();

    }

    return 0;
}

//Salidas

static void fsm_sumar_persona(fsm_t*f)
{
    fsm_contador_t * fp = (fsm_contador_t*)f;
    fp -> Personas++;
}

static void fsm_restar_persona(fsm_t*f)
{
    fsm_contador_t * fp = (fsm_contador_t*)f;
    fp -> Personas--;
}

//Tabla de transiciones

static fsm_trans_t contador_tt [] = {
    
    {CONTADOR, fsm_solicitud, CONTADOR, fsm_sumar_persona},
    {CONTADOR, fsm_listo, CONTADOR, fsm_restar_persona},
    {-1, NULL, -1, NULL}

};

//Inicializacion

void fsm_contador_init(fsm_contador_t* f, fsm_contador_solicitud_func_t solicitud, fsm_contador_listo_func_t listo)

{
    fsm_init((fsm_t*)f,contador_tt);
    f-> solicitud = solicitud;
    f-> listo = listo;
    f-> Personas = 0;
}

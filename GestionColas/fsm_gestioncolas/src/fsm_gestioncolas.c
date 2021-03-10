#include <stddef.h>

#include "fsm_gestioncolas.h"
#include "fsm_gestioncolas_internal.h"

/* Funcion de guarda
Boton que solicita ponerse en la cola
*/

static int fsm_solicitud_cola(fsm_t* f)
{
    fsm_gestioncolas_t* fp = (fsm_gestioncolas_t*)f;

    if (fp -> solicitud_cola){
        return fp-> solicitud_cola();
    }
    return 0;
}

/* Funcion de guarda
Boton que solicita ponerse en la cola
*/

static int fsm_terminado(fsm_t* f)
{
    fsm_gestioncolas_t* fp = (fsm_gestioncolas_t*)f;

    if (fp -> terminado){
        return fp-> terminado();
    }
    return 0;
}

/* Funcion de activacion
Manda la señal de solicitud y asigna el orden en la cola
*/

static void fsm_cogerorden(fsm_t* f)
{
    fsm_gestioncolas_t* fp = (fsm_gestioncolas_t*)f;
    fp->Solicitud = 1;
}

/* Funcion de activacion
Manda la señal de listo y actualiza la cola
*/

static void fsm_listo(fsm_t* f)
{
    fsm_gestioncolas_t* fp = (fsm_gestioncolas_t*)f;
    fp->Listo = 1;
}

/* Tabla de transiciones */

static fsm_trans_t gestioncolas_tt[] = {
    {READY, fsm_solicitud_cola, WAITING, fsm_cogerorden},
    {WAITING, fsm_terminado, WAITING, fsm_listo},
    {-1, NULL, -1, NULL}
};

/* Inicializacion*/

void fsm_gestioncolas_init(fsm_gestioncolas_t* f,  fsm_gestioncolas_solicitud_cola_func_t solicitud_cola, fsm_gestioncolas_terminado_func_t terminado)
{
    fsm_init((fsm_t*)f, gestioncolas_tt);
    f->solicitud_cola = solicitud_cola;
    f-> terminado = terminado;
    f-> Solicitud = 0;
    f-> Listo = 0;
    f-> Orden = 0;
    f-> Personas = 0;
}
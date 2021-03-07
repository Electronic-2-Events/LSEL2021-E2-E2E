#include <stddef.h>
#include "fsm_control_pulsera.h"
#include "fsm_control_pulsera_internal.h"

/* Funcion de guarda 
 * Sensor que comprueba si la pulsera esta puesta o no. En caso negativo, se actia
 */
static int 
fsm_detects_no_contact(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;

    if (fp->check){
        return fp->check();
    }
    return 0;
}


/* Funcion de guarda 
 * Comprueba la señal de activacion de la pulsera por NFC
 */
static int
fsm_activation(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;

    if (fp->check){
        return fp->check();
    }
    return 0;
}

/* Funcion de guarda 
 * Timeout para actualizar la hora
 */
static int
fsm_get_time(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;
    fp->menu = SHOW_TIME;
    if (fp->check){
        return fp->check();
    }
    return 0;
}

/* Funcion de activacion 
 * Activa el NFC y muestra la hora por pantalla
 */
static void
fsm_activate_NFC_tag(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;
    fp->NFC_active = 1;
    //printf("NFC Activado");
    fp->menu = SHOW_TIME;
    //printf("Mostrar hora en pantalla");
}

/* Funcion de activacion 
 * Desactiva el NFC y muesta mensaje por pantalla
 */
static void
fsm_deactivate_NFC_tag(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;
    fp->NFC_active = 0;
    //printf("NFC Desactivado");
    fp->menu = SHOW_WARNING;
    //printf("Tienes que ir a un punto de activación para volver a usar la pulsera");
}


/* Funcion de activacion 
 * Muestra la hora por pantalla
 */
static void
fsm_show_on_screen_hour(fsm_t* f)
{
    
    //printf("Mostrar hora en pantalla");
}

//tabla de transiciones de la FSM
static fsm_trans_t
control_pulsera_tt[] = {
    {SUSPENDED, fsm_activation, IDLE, fsm_activate_NFC_tag},
    {IDLE, fsm_get_time, IDLE, fsm_show_on_screen_hour},
    {IDLE, fsm_detects_no_contact, SUSPENDED, fsm_deactivate_NFC_tag },
    {-1, NULL, -1, NULL}
};


/* Inicializacion */
void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_check_func_t check)
{
    fsm_init((fsm_t*)f, control_pulsera_tt);
    f->check = check;
    f->NFC_active = 0;
    f->menu = SHOW_WARNING;
}
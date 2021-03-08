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

    if (fp->no_contact){
        return fp->no_contact();
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

    if (fp->activation){
        return fp->activation();
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
    
    if (fp->get_time){
        return fp->get_time();
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
    //printf("NFC Activado");
    fp->NFC_on = 1;
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
    //printf("NFC Desactivado")
    fp->NFC_on = 0;
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

void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_get_time_func_t get_time,
    fsm_control_pulsera_activation_func_t activation, fsm_control_pulsera_detects_no_contact_func_t no_contact)
{
    fsm_init((fsm_t*)f, control_pulsera_tt);
    f->get_time = get_time;
    f->activation = activation;
    f->no_contact = no_contact;
    f->menu = SHOW_WARNING;
    f->NFC_on = 0;
}
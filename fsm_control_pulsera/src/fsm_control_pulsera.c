#include <stddef.h>
#include "fsm_control_pulsera.h"
#include "fsm_control_pulsera_internal.h"

static int 
fsm_detects_no_contact(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;

    if (fp->check){
        return fp->check();
    }
    return 0;
}

static int
fsm_activation(fsm_t* f)
{
    fsm_control_pulsera_t* fp = (fsm_control_pulsera_t*)f;

    if (fp->check){
        return fp->check();
    }
    return 0;
}

static void
fsm_activate_NFC_tag(fsm_t* f)
{
    //printf("NFC Activado");
}

static void
fsm_deactivate_NFC_tag(fsm_t* f)
{
    //printf("NFC Desactivado");
}

static void
fsm_show_on_screen_activation_point_message(fsm_t* f)
{
    //printf("Tienes que ir a un punto de activación para volver a usar la pulsera");
}

static void
fsm_show_on_screen_hour(fsm_t* f)
{
    //printf("Mostrar hora en pantalla");
}

static fsm_trans_t
control_pulsera_tt[] = {
    {SUSPENDED, fsm_detects_no_contact, IDLE, fsm_deactivate_NFC_tag && fsm_show_on_screen_activation_point_message},
    {IDLE, fsm_activation, SUSPENDED, fsm_activate_NFC_tag && fsm_show_on_screen_hour},
    {-1, NULL, -1, NULL}
};
void fsm_control_pulsera_init(fsm_control_pulsera_t* f, fsm_control_pulsera_check_func_t check)
{
    fsm_init((fsm_t*)f, control_pulsera_tt);
    f->check = check;
}
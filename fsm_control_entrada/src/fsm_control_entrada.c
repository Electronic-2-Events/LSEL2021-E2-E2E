#include <stddef.h>

#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#include "acciones.h"
#include "timer.h"

#define DEADLINE10 (10)
#define DEADLINE3 (3)

//ENTRADAS
static int fsm_NFC(fsm_t *f)
{
    if (NFC() == 1)
        return 1;
    else
        return 0;
}

static int fsm_s_bar_top(fsm_t *f)
{
    if (s_bar_top() == 1)
        return 1;
    else
        return 0;
}

static int fsm_timer_timeout(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    return (timer() >= fp->next_timeout);
}

static int fsm_s_prox(fsm_t *f)
{
    return (s_prox());
}

static int fsm_s_bar_bottom(fsm_t* f){
    if (s_bar_bottom()==1)
        return 1;
    else
        return 0;

}

//SALIDAS
static void fsm_subir(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    fp->subir = 1;
}

static void fsm_parar(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    fp->subir = 0;
    fp->next_timeout = timer() + DEADLINE10;
}

static void fsm_waiting(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    fp->next_timeout = timer() + DEADLINE3;
}

static int fsm_bajar(fsm_t *f){};
static int fsm_s_bar_bottom(fsm_t *f){};

static fsm_trans_t entrada_tt[] = {
    {DOWN, fsm_NFC, SUBIENDO, fsm_subir},
    {SUBIENDO, fsm_s_bar_top, UP, fsm_parar},
    {UP, fsm_timer_timeout, BAJANDO, fsm_bajar},
    {UP, fsm_s_prox, WAITING, fsm_waiting},
    {WAITING, fsm_timer_timeout, BAJANDO, fsm_parar},
    {BAJANDO, fsm_s_bar_bottom, DOWN, fsm_parar},
    {-1, NULL, -1, NULL}};

void fsm_control_entrada_init(fsm_control_entrada_t *f)
{
    fsm_init((fsm_t *)f, entrada_tt);
    f->subir = 0;
    f->bajar = 0;
    f->next_timeout = 0;
}

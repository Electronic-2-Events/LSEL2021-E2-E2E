#include <stddef.h>

#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#include "mock_acciones.h"

#define DEADLINE10 (10)
#define DEADLINE3 (3)

static int fsm_NFC(fsm_t* f){
    if (NFC()==1)
        return 1;
    else
        return 0;
}
static void fsm_subir(fsm_t* f){
    fsm_control_entrada_t* fp = (fsm_control_entrada_t *)f;
    fp->subir = 1;
}

static int fsm_s_bar_top(fsm_t* f){
    
}

static fsm_trans_t entrada_tt[] = {
    {DOWN, fsm_NFC ,SUBIENDO, fsm_subir },
    {SUBIENDO, , UP, },
    /*{UP, , BAJANDO, },
    {UP, , BAJANDO, },
    {UP, , WAITING, },
    {WAITING, , BAJANDO, },
    {BAJANDO, ,DOWN, },
    */
    {-1, NULL, -1, NULL}
};

void fsm_control_entrada_init(fsm_control_entrada_t* f)
{
    fsm_init((fsm_t*)f, entrada_tt);
    f->subir = 0;
}

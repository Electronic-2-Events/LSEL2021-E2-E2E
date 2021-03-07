#include <stddef.h>

#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#define DEADLINE10 (10)
#define DEADLINE3 (3)


static fsm_trans_t entrada_tt[] = {
   /* {DOWN, ,SUBIENDO, },
    {SUBIENDO, , UP, },
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
}

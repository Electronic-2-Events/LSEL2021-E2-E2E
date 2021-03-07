#include <stddef.h>
#include "fsm_control.h"
#include "fsm_control_internal.h"
#include "timer.h"

#define TIMEOUT (1)

static int 
fsm_control_check(fsm_t* f)
{
    fsm_control_t* fp = (fsm_control_t*)f;

    if (fp->check){
        return fp->check();
    }
    return 0;
}

static int
fsm_control_is_timeout(fsm_t* f)
{
    fsm_control_t* fp = (fsm_control_t*)f;
    return timer_get_tick() - fp->timeout ;
}

static void
fsm_control_set_timeout(fsm_t*f)
{
    fsm_control_t* fp = (fsm_control_t*)f;
    fp->timeout = timer_get_tick() + TIMEOUT;
}
static fsm_trans_t
control_tt[] = {
    {SUSPENDED, fsm_control_check, IDLE, fsm_control_set_timeout},
    {IDLE, fsm_control_is_timeout, SUSPENDED, NULL},
    {-1, NULL, -1, NULL}
};

void fsm_control_init(fsm_control_t* f, fsm_control_check_func_t check)
{
    fsm_init((fsm_t*)f, control_tt);
    f->check = check;
}
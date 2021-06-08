#include "fsm_users.h"
#include <stddef.h>

#include "fsm_users.h"
#include "users.h"

#include "acciones.h"

//ENTRADAS
static int fsm_NFC(fsm_t *f)
{
    fsm_users_t *fp = (fsm_users_t *)f;

    if (fp->NFC)
    {
        fp->ID = NFC();

        return fp->ID;
    }
    return 0;
}

//SALIDAS

static void regNewUser(fsm_t *f)
{
    fsm_users_t *fp = (fsm_users_t *)f;

    regNewPerson(fp->ID);
}

static fsm_trans_t users_tt[] = {
    {WAITING, fsm_NFC, WAITING, regNewUser},
    {-1, NULL, -1, NULL}};

void fsm_users_init(fsm_users_t *f, fsm_users_NFC_func_t NFC)
{
    fsm_init((fsm_t *)f, users_tt);
    f->NFC = NFC;
    f->ID = 0;
}

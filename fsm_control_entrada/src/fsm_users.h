#ifndef FSM_USERS_H
#define FSM_USERS_H

#include "fsm.h"
#include "users.h"

enum
{
    WAITING
};

typedef int (*fsm_users_NFC_func_t)(void);

struct _fsm_users_t
{
    fsm_t fsm;
    fsm_users_NFC_func_t NFC;
    int ID;
};

typedef struct _fsm_users_t fsm_users_t;

void fsm_users_init(fsm_users_t *f, fsm_users_NFC_func_t NFC);

#endif // FSM_USERS_H

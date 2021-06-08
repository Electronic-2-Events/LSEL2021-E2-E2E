#include <stddef.h>
#ifndef _USERS_H
#define _USERS_H

typedef struct users
{
    int ID;
    int estado;
    users *nextUser;
} users;

void regNewPerson(int ID);
void cleanList(users *list);

#endif
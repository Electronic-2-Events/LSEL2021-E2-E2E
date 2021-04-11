#include <stddef.h>
#include <stdbool.h>

#ifndef _USERS_H
#define _USERS_H

typedef struct users
{
    int ID;
    bool estado;
    users *nextUser;
} users;

users * fillNewPerson(int ID);
void regNewPerson(int ID);
void cleanList(users *list);

#endif
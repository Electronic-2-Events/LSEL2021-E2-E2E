#include <stddef.h>
#include <stdbool.h>

#include "users.h"

users *firstElement = NULL;
users *lastAdded = NULL;

users *fillNewPerson(int ID)
{
    users *newPerson = NULL;
    newPerson = malloc(sizeof(users));

    newPerson->ID = ID;
    newPerson->estado = false;
    newPerson->nextUser = NULL;

    return newPerson;
}

void regNewPerson(int ID)
{
    if (firstElement == NULL)
    {
        firstElement = fillNewPerson(ID);
        lastAdded = firstElement;
    }
    else
    {
        lastAdded->nextUser = fillNewPerson(ID);
        lastAdded = lastAdded->nextUser;
    }
};

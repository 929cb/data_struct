#include "main.h"

Status DestroyList_L(LinkList L)
{
    Lnode *p;

    while(L)
    {
        p = L;
        L = L->next;
        free(p);
    }

    return OK;
}
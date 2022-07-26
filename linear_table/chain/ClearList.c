#include "main.h"

Status ClearList(LinkList L)
{
    Lnode *p, *q;

    p = L->next;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;

    return OK;
}
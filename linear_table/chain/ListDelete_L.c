#include "main.h"

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
    Lnode *p = L, *q;
    int j = 0;

    while(p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if(!(p->next) || j > i - 1) return ERROR;

    q = p->next;
    *e = q->data;
    p->next = p->next->next;
    free(q);

    return OK;
}
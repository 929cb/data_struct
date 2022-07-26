#include "main.h"

Lnode *LocateElem_L(LinkList L, ElemType e)
{
    Lnode *p = L->next;

    while(p && p->data != e)
    {
        p = p->next;
    }

    return p;
}

int LocateElem_L2(LinkList L, ElemType e)
{
    Lnode *p = L->next;
    int i = 1;

    while(p && p->data != e)
    {
        i++;
        p = p->next;
    }

    if(p) return i;
    else return ERROR;
}
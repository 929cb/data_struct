#include "main.h"

Status CreateList_H(LinkList L, int n)
{
    Lnode *p;

    //L = (LinkList)malloc(sizeof(Lnode));
    if(!L) exit(0);
    L->next = NULL;

    for(int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if(!p) exit(0);
        p->data = 'a' + i;

        p->next = L->next;
        L->next = p;
    }

    return OK;
}
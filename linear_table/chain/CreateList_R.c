#include "main.h"

Status CreateList_R(LinkList L, int n)
{
    Lnode *p, *r;

    //L = (LinkList)malloc(sizeof(Lnode));
    if(!L) exit(0);
    
    L->next = NULL;
    r = L;

    for(int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if(!p) exit(0);
        p->data = 'a' + i;

        r->next = p;
        r = p;
    }
    r->next = NULL;

    return OK;
}
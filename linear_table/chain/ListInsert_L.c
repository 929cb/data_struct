#include "main.h"

Status ListInsert_L(LinkList L, int i, ElemType e)
{
    Lnode *p = L;
    int j = 0;


    while(p && j < i - 1)
    {
        j++;
        p = p->next;
    }

    if(!p || j > i - 1) return ERROR;

    Lnode *newnode = (LinkList)malloc(sizeof(Lnode));
    if(!newnode) exit(0);

    newnode->data = e;

    newnode->next = p->next;
    p->next = newnode;

    return OK;
}
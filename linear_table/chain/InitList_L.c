#include "main.h"

Status InitList_L(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Lnode));

    if(!L) exit(0);
    (*L)->next = NULL;
    
    return OK;
}

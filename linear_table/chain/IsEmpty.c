#include "main.h"

Status IsEmpty(LinkList L)
{
    if(L->next) return ERROR;
    else return OK;
}
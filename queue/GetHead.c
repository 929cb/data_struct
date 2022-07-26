#include "main.h"

ElemType GetHead(SqQueue Q)
{
    if(Q.front == Q.rear) return ERROR;

    return Q.base[Q.front];
}
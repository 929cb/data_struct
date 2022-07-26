#include "main.h"

Status DeQueue(SqQueue *Q, ElemType *e)
{
    if(!Q->base) return ERROR;
    if(Q->front == Q->rear) return ERROR;

    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return OK;
}
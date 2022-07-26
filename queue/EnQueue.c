#include "main.h"

Status EnQueue(SqQueue *Q, ElemType e)
{
    if(!Q->base) return ERROR;
    if((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;

    return OK;
}
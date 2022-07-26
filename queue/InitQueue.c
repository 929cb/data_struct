#include "main.h"

Status InitQueue(SqQueue *Q)
{
    Q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    if(!Q->base) exit(0);

    Q->front = Q->rear = 0;

    return OK;
}
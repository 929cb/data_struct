#include "main.h"

Status ClearQueue(SqQueue *Q)
{
    if(!Q->base) return ERROR;

    Q->rear = Q->front;

    return OK;
}
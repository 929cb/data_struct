#include "main.h"

Status DestroyQueue(SqQueue *Q)
{
    if(Q->base)
    {
        free(Q->base);

        Q->front = Q->rear = 0;

        return OK;
    }
    else return ERROR;
}
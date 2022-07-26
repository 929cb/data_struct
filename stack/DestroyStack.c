#include "main.h"

Status DestroyStack(SqStack *S)
{
    if(S->base)
    {
        S->stacksize = 0;
        free(S->base);
        S->base = S->top = NULL;

        return OK;
    }
    else return ERROR;
}
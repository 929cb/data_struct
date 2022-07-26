#include "main.h"

Status ClearStack(SqStack *S)
{
    if(S->base)
    {
        S->top = S->base;
        return OK;
    }
    else return ERROR;
}
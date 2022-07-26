#include "main.h"

Status Pop(SqStack *S, ElemType *e)
{
    if(!S->base) return ERROR;
    if(S->base == S->top) return ERROR;

    *e = *(--(S->top));

    return OK;
}
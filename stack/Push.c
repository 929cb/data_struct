#include "main.h"

Status Push(SqStack *S, ElemType e)
{
    if(!S->base) return ERROR;
    if(S->top - S->base == S->stacksize) return ERROR;

    *(S->top) = e;
    (S->top)++;

    return OK; 
}
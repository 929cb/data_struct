#include "main.h"

Status InitStack(SqStack *S)
{
    S->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    if(!S->base) exit(0);

    S->top = S->base;
    S->stacksize = MAXSIZE;

    return OK;
}
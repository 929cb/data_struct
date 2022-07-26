#include "main.h"

Status InitList(SqList *L)
{
    L->elem = (ElemType*)malloc(sizeof(L->elem) * MAX_SIZE);
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    return OK;
}

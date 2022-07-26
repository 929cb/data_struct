#include "main.h"

Status ListInsert(SqList *L, int i, ElemType e)
{
    if(!L->elem) exit(OVERFLOW);
    if(i < 1 || i > L->length + 1 || L->length == MAX_SIZE) return ERROR;

    int right = L->length - 1;

    for(; right >= i - 1; right--) L->elem[right + 1] = L->elem[right];
    L->elem[i - 1] = e;
    L->length++;

    return OK;
}
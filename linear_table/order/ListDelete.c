#include "main.h"

Status ListDelete(SqList *L, int i, ElemType *e)
{
    if(!L->elem) exit(OVERFLOW);
    if(i < 1 || i > L->length || L->length == 0) return ERROR;

    *e = L->elem[i - 1];

    int j;
    for(j = L->length - 1, i -= 1; i < j; i++) L->elem[i] = L->elem[i + 1];
    L->length--;

    return OK; 
}
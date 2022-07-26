#include "main.h"

int GetElem(SqList L, int i, ElemType *e)
{
    if(i < 1 || i > L.length) return ERROR;

    *e = L.elem[i - 1];
    return OK;
}
#include "main.h"

void DestroyList(SqList *L)
{
    if(L->elem) free(L->elem);
}
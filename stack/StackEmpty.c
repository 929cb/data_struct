#include "main.h"

Status StackEmpty(SqStack S)
{
    if(S.base == S.top) return TRUE;
    else return FALSE;
}
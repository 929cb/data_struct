#include "main.h"

ElemType GetTop(SqStack S)
{
    return *(S.top - 1);
}
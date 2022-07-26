#include "main.h"

// 返回L中第一个与e满足compare数据元素的位序，不存在则返回0
int LocateElem(SqList L, ElemType e)
{
    int i = 0;

    for(; i < L.length; i++)
    {
        if(L.elem[i] == e) return (i + 1);
    }
    return ERROR;
}
#include "main.h"

int ListLength_L(LinkList L)
{
    LinkList p = L->next;
    int count = 0;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}
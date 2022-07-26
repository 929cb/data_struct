#include "main.h"

int main()
{
    SqQueue Q;

    InitQueue(&Q);

    for(int i = 0; i < 5; i++)
    {
        EnQueue(&Q, 'a' + i);
    }

    printf("队头：%c\n", GetHead(Q));

    ElemType e;

    while(QueueLength(Q))
    {
        DeQueue(&Q, &e);
        printf("%c\n", e);
    }

    return 0;
}
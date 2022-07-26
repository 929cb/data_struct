#include "main.h"

int main()
{
    SqStack S;

    InitStack(&S);

    for(int i = 0; i < 5; i++)
    {
        Push(&S, i);
    }

    printf("栈顶：%d\n", GetTop(S));

    ElemType e;
    while(!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("%d\n", e);
    }

    return 0;
}
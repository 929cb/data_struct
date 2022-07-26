#include "main.h"

int main()
{
    LinkList L;
//L = (LinkList)malloc(sizeof(Lnode));
    InitList_L(&L); //  (二级指针可解决了将一级野指针传到其他函数去分配空间会段错误的问题)

    CreateList_R(L, 5); //  不能传野指针
    //if((L->next)) printf("L->next\n");
//printf("%d", L->next->data);

    ListInsert_L(L, 1, 'a');
    ElemType e;
    ListDelete_L(L, 5, &e);

    while(L->next)
    {
        printf("%c\n", L->next->data);
        L = L->next;
    }

//     if(InitList_L(L)) printf("ok\n");
//     else printf("no\n");
//     if(ListInsert_L(L, 1, 21))
//         printf("%d ", L->next->data);
//         else
// printf("NO\n");
    return 0;
}

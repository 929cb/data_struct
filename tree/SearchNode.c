#include "main.h"

BiTree SearchNode(BiTree T, ElemType data)
{
    if(T == NULL) return NULL;

    if(T->data == data) return T;
    else
    {
        BiTree p;

        p = SearchNode(T->left ,data);

        if(!p) p = SearchNode(T->right, data);

        return p;
    }
}
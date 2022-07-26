#include "main.h"

int LeafNodeNum(BiTree T)
{
    if(T == NULL) return 0;

    if(T->left == NULL && T->right == NULL) return 1;
    else
    {
        return LeafNodeNum(T->left) + LeafNodeNum(T->right);
    }
}
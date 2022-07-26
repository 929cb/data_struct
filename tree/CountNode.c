#include "main.h"

int CountNode(BiTree T)
{
    if(T)
    {
        if(T->left == NULL && T->right == NULL) return 1;
        else return CountNode(T->left) + CountNode(T->right) + 1;
    }

    return 0;
}
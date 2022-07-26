#include "main.h"

void DestroyBiTree(BiTree T)
{
    if(T)
    {
        DestroyBiTree(T->left);
        DestroyBiTree(T->right);

        free(T);
    }
}
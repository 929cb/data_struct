#include "main.h"

int GetMaxDepth(BiTree T)
{
    if(T)
    {
        int maxLeft = GetMaxDepth(T->left);
        int maxRight = GetMaxDepth(T->right);

        return (maxLeft > maxRight ? maxLeft + 1 : maxRight + 1);
    }

    return 0;
}
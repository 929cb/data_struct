#include "main.h"

int LevelNodeNum(BiTree T, int k)
{
    if(T == NULL || k < 1) return 0;
    if(k == 1) return 1;

    return LevelNodeNum(T->left, k - 1) + LevelNodeNum(T->right, k - 1);
}
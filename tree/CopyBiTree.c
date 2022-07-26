#include "main.h"

void CopyBiTree(BiTree T, BiTree *newT)
{
    if(T == NULL) *newT = NULL;
    else
    {
        *newT = (BiTree)malloc(sizeof(BiNode));
        if(!(*newT)) exit(0);

        (*newT)->data = T->data;
        
        CopyBiTree(T->left, &((*newT)->left));
        CopyBiTree(T->right, &((*newT)->right));
    }
}
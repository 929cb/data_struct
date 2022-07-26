#include "main.h"

Status CreateBiTree(BiTree *T)
{
    ElemType data;

    scanf("%c", &data);
    getchar();

    if(data == 35) *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiNode));
        if(!(*T)) exit(0);

        (*T)->data = data;
        CreateBiTree(&((*T)->left));
        CreateBiTree(&((*T)->right));
    }

    return OK;
}

BiTree CreateTree()
{
    ElemType data;
    scanf("%c", &data);
    getchar();
    BiTree root;

    if(data == '#') root = NULL;
    else
    {
        root = (BiTree)malloc(sizeof(BiNode));
        if(!root) exit(0);

        root->data = data;
        root->left = CreateTree();
        root->right = CreateTree();
    }

    return root;
}
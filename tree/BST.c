#include "main.h"

BiTree FindNode(BiTree T, ElemType e)
{
    BiTree p = T;

    while(p != NULL && p->data != e)
    {
        if(p->data > e) p = p->left;
        else p = p->right;
    }

    return p;
}

BiTree FindNode2(BiTree T, ElemType e)
{
    if(T == NULL) return NULL;

    if(T->data == e) return T;

    if(T->data > e) return FindNode2(T->left, e);
    else return FindNode2(T->right, e);
}


Status BST_Insert(BiTree *T, ElemType e)    //  不同元素才能插入成功
{
    if((*T) == NULL)
    {
        (*T) = (BiTree)malloc(sizeof(BiNode));
        if(!(*T)) exit(0);

        (*T)->data = e;
        (*T)->left = (*T)->right = NULL;

        return OK;
    }

    if((*T)->data == e) return ERROR;
    else if((*T)->data > e)
    {
        if((*T)->left == NULL)
        {
            (*T)->left = (BiTree)malloc(sizeof(BiNode));
            if(!((*T)->left)) exit(0);

            (*T)->left->data = e;
            (*T)->left->left = (*T)->left->right = NULL;

            return OK;
        }
        else return BST_Insert(&((*T)->left), e);
    }
    else if((*T)->data < e)
    {
        if((*T)->right == NULL)
        {
            (*T)->right = (BiTree)malloc(sizeof(BiNode));
            if(!((*T)->right)) exit(0);

            (*T)->right->data = e;
            (*T)->right->left = (*T)->right->right = NULL;

            return OK;
        }
        else return BST_Insert(&((*T)->right), e);
    }
}


BiTree Create_BST(ElemType arr[], int len)
{
    BiTree p = NULL;

    for(int i = 0; i < len; i++)
    {
        BST_Insert(&p, arr[i]);
    }

    return p;
}


Status BST_Delete(BiTree T, ElemType e)
{
    BiTree p = T;
    BiTree parent = NULL;
    int child = 0;

    while(p != NULL && p->data != e)    //  找到待删除的节点及其父节点
    {
        parent = p;
        if(p->data > e)
        {
            child = -1;
            p = p->left;
        }
        else 
        {
            child = 1;
            p = p->right;
        }
    }

    if(p == NULL) return ERROR;    //  空树或者没有找到

    if(parent == NULL && p->left == NULL && p->right == NULL)  //  待删除节点是根节点，并且该树只有一个根结点
    {
        T = NULL;
        free(p);

        return OK;
    }
    else if(parent == NULL && p->left != NULL && p->right == NULL) //  待删除节点是根节点，并且该树只有左子树
    {
        T = p->left;
        free(p);

        return OK;
    }
    else if(parent == NULL && p->left == NULL && p->right != NULL) //  待删除节点是根节点，并且该树只有右子树
    {
        T = p->right;
        free(p);

        return OK;
    }

    if(parent != NULL && p->left == NULL && p->right == NULL)   //  待删除节点是叶子节点
    {
        free(p);

        if(child == -1) parent->left = NULL;
        else if(child == 1) parent->right = NULL;

        return OK;
    }

    if(parent != NULL && p->left != NULL && p->right == NULL)   //  待删除节点是中间节点，并且该子树只有左子树
    {
        if(child == -1) parent->left = p->left;
        else if(child == 1) parent->right = p->left;

        free(p);

        return OK;
    }
    else if(parent != NULL && p->left == NULL && p->right != NULL)  //  待删除节点是中间节点，并且该子树只有右子树
    {
        if(child == -1) parent->left = p->right;
        else if(child == 1) parent->right = p->right;

        free(p);

        return OK;
    }
    else if(p->left != NULL && p->right != NULL)  //  待删除节点是根节点或者中间节点，并且该节点左右子树都有
    {
        BiTree t = p->left;
        BiTree f = NULL, top = NULL;

        if(t->right != NULL) f = t;
		else f = t->left;

        while(t->right)
        {
            top = t;
            t = t->right;
        }

        p->data = t->data;
        p->left = f;
        if(top) top->right = NULL;
        
        free(t);

        return OK;
    }
}

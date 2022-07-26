#include "main.h"

Status PreOrderTraverse(BiTree T)
{
	if(T == NULL) return ERROR;

	printf("%c\n", T->data);
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);

	return OK;
}

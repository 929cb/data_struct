#include "main.h"

void PostOrderTraverse(BiTree T)
{
	if(T == NULL) return;

	PostOrderTraverse(T->left);
	PostOrderTraverse(T->right);
	printf("%c\n", T->data);
}

#include "main.h"

void InOrderTraverse(BiTree T)
{
	if(T == NULL) return;

	InOrderTraverse(T->left);
	printf("%c\n", T->data);
	InOrderTraverse(T->right);
}

/*
Status InOrderTraverse(BiTree T)
{
	BiTree p;
	InitStack(S);
	p = T;

	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S, p);
			p = p->left;
		}
		else
		{
			Pop(S, q);
			printf("%c\n", q->data);

			p = q->right;
		}
	}

	return OK;
}
*/
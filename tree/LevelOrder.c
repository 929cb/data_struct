#include "main.h"

void LevelOrder(BiTree T)
{
	BiTree p;
	SqQueue *qu;

	InitQueue(qu);
	EnQueue(qu, T);

	while(!QueueEmpty(qu))
	{
		DeQueue(qu, p);

		printf("%c", p->data);

		if(p->left) EnQueue(qu, p->left);
		if(p->right) EnQueue(qu, p->right);
	}
}

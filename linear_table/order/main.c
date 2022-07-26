#include "main.h"


int main()
{
	SqList L;

	InitList(&L);

	for(int i = 0; i < 10; i++)
	{
		ListInsert(&L, i + 1, 'a' + i);
	}
	ElemType e;
	ListDelete(&L, 2, &e);

	for(int i = 0; i < L.length; i++)
	{
		printf("%c ", L.elem[i]);
	}
	printf("\n");

	return 0;
}


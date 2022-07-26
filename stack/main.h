#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct	//	还可以用链表采用头插法
{
	ElemType *base;
	ElemType *top;
	int stacksize;	//	栈可用最大容量
}SqStack;


Status InitStack(SqStack *S);
Status ClearStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status Push(SqStack *S, ElemType e);
Status Pop(SqStack *S, ElemType *e);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
ElemType GetTop(SqStack S);


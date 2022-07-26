#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct
{
	ElemType *base;
	int front;
	int rear;
}SqQueue;


Status InitQueue(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
ElemType GetHead(SqQueue Q);
Status EnQueue(SqQueue *Q, ElemType e);
Status DeQueue(SqQueue *Q, ElemType *e);


#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

#define MAX_SIZE 100

typedef struct List
{
	ElemType *elem;
	int length;
}SqList;


Status InitList(SqList *L);
void DestroyList(SqList *L);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
int GetElem(SqList L, int i, ElemType *e);
int GetLength(SqList L);
void ClearList(SqList *L);
int ListEmpty(SqList L);
int LocateElem(SqList L, ElemType e);


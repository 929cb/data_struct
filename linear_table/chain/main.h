#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
}Lnode, *LinkList;


Status InitList_L(LinkList *L);
Status IsEmpty(LinkList L);
Status ListInsert_L(LinkList L, int i, ElemType e);
Status DestroyList_L(LinkList L);
Status ClearList(LinkList L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L, int i, ElemType *e);
Lnode *LocateElem_L(LinkList L, ElemType e);
int LocateElem_L2(LinkList L, ElemType e);
Status ListDelete_L(LinkList L, int i, ElemType *e);
Status CreateList_H(LinkList L, int n);
Status CreateList_R(LinkList L, int n);


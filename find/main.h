#include <stdio.h>
#include <stdlib.h>

typedef char KeyType;

#define OK 1
#define ERROR 0

typedef struct
{
	KeyType key;	
}ElemType;

typedef struct
{
	ElemType *R;	//	表基址
	int len;	//	表长
}SSTable;


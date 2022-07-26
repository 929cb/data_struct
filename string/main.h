#include <stdio.h>
#include <stdlib.h>

/* 串的顺序存储结构 */
#define MAXLEN 255

typedef struct
{
	char ch[MAXLEN + 1];
	int length;
}SString;


int index_BF(SString S, SString T);



/* 串的链式存储结构--块链 */
#define CHUNKSIZE 80

typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

typedef struct
{
	Chunk *head, *tail;
	int curlen;
}LString;


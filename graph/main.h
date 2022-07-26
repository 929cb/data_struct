#include <stdio.h>
#include <stdlib.h>

/* 邻接矩阵法 */
#define MaxInt 32767	//	表示极大值
#define MaxVerNum 100	//	最大顶点数

typedef int Status;
#define OK 1
#define ERROR 0

typedef char VerTexType;	//	顶点的数据类型
typedef int ArcType;	//	边的权值类型

typedef struct
{
	VerTexType vexs[MaxVerNum];	//	顶点表
	ArcType arcs[MaxVerNum][MaxVerNum];	//	邻接矩阵
	int vexNum, arcNum;	//	图的当前的顶点数和边数
}*AMGraph;	//	Adjacency Matrix Graph


Status CreateUDN(AMGraph *G);
int LocateVex(AMGraph G, VerTexType u);



/* 邻接表（链式） */
//	若无向图有n个顶点，e条边；则其邻接表需n个头节点和2e个表节点（适宜存储稀疏图）
typedef int OtherInfo;

typedef struct ArcNode
{
	int adjVex;	//	该边指向的顶点的位置
	struct ArcNode *nextArc;	//	指向下一条边
	OtherInfo info;	//	和边相关的信息
}ArcNode;

typedef struct VNode
{
	VerTexType data;	//	顶点信息
	ArcNode *firstArc;	//	指向第一条依附该顶点的边
}VNode, AdjList[MaxVerNum];	//	AdjList表示邻接表类型

typedef struct
{
	AdjList vertices;
	int vexNum, arcNum;	//	图的当前顶点数和弧数
}*ALGraph;

Status CreateUDG(ALGraph *G);



/*
	十字链表（有向图）：
		顶点节点：data, firstin, firstout
		弧节点：tailvex, headvex, hlink, tlink

	邻接多重表（无向图）（解决同一条边两个顶点都分别存储）
*/

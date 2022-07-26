#include "main.h"

//	邻接矩阵（深度优先）
void DFS(AMGraph G, int v)
{
	cout<<v;
	visited[v] = true;

	for(int w = 0; w < G->vexNum; w++)
	{
		if(G->arcs[v][w] != 0 && (!visited[w])) DFS(G, w);
	}
}

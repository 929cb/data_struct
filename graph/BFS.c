#include "main.h"

void BFS(Graph G, int v)
{
	cout<<v;
	visited[v] = true;

	InitQueue(Q);
	EnQueue(Q, v);

	while(!QueueEmpty(Q))
	{
		DeQueue(Q, u);

		//	w为u的尚未访问的邻接节点
		for(w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if(!visited[w])
			{
				cout<<w;
				visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}
}

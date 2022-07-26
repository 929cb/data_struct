#include "main.h"


int main()
{
    AMGraph G;

    CreateUDN(&G);

    for(int i = 0; i < G->vexNum; i++)
    {
        printf("%c  ", G->vexs[i]);
        for(int j = 0; j < G->vexNum; j++)
        {
            printf("%d ", G->arcs[i][j]);
        }
        printf("\n");
    }

    return 0;
}
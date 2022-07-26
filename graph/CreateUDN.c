#include "main.h"

int LocateVex(AMGraph G, VerTexType u)
{
    for(int i = 0; i < (*G).vexNum; i++)
    {
        if(u == (*G).vexs[i]) return i;
    }
    return -1;
}

//采用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph *G)
{
    *G = (AMGraph)malloc(sizeof(AMGraph[0]));
    if(!(*G))
    {
        printf("G内存分配失败！\n");
        exit(0);
    }

    printf("输入总顶点数：");
    scanf("%d", &((*G)->vexNum));
    getchar();
    printf("输入总边数：");
    scanf("%d", &((*G)->arcNum));
    getchar();

    printf("依次输入各顶点信息：\n");
    for(int i = 0; i < (*G)->vexNum; i++)
    {
        scanf("%c", (*G)->vexs + i);
        getchar();
    }

    //  初始化邻接矩阵
    for(int i = 0; i < (*G)->vexNum; i++)
    {
        for(int j = 0; j < (*G)->vexNum; j++)
        {
            //*(*(G->arcs + i) + j) = MaxInt;
            (*G)->arcs[i][j] = MaxInt; //  无向图初始化为0
        }
    }

    char v1, v2;
    int j, k, w;
    //  构造邻接矩阵
    for(int i = 0; i < (*G)->arcNum; i++)
    {
        look1: printf("构造边--输入该边所依附的两个顶点：");
        scanf("%c %c", &v1, &v2);
        getchar();fflush(stdin);

        j = LocateVex(*G, v1);
        k = LocateVex(*G, v2);

        if(j != -1 && k != -1)
        {
            printf("输入该边的权值：");
            scanf("%d", &w);
            getchar();

            (*G)->arcs[j][k] = w;  //  无向网/图邻接矩阵是对称矩阵(无向图权值为1)
            (*G)->arcs[k][j] = w;  //  有向网只需为 G->arcs[j][k] 赋值（代表j行表示的顶点指向k列的顶点）
        }
        else
        {
            printf("该边所依附的两个顶点有误！");
            goto look1;
        }

    }

    return OK;
}
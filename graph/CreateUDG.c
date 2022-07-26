#include "main.h"

static int LocateVex(ALGraph G, VerTexType u)
{
    for(int i = 0; i < G->vexNum; i++)
    {
        if(u == G->vertices[i].data) return i;
    }

    return -1;
}

Status CreateUDG(ALGraph *G)
{
    *G = (ALGraph)malloc(sizeof(ALGraph[0]));
    if(!(*G))
    {
        printf("ALG内存分配失败！\n");
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
        printf("第%d个：", i + 1);
        scanf("%c", &((*G)->vertices[i].data));
        getchar();

        //  初始化邻接表
        (*G)->vertices[i].firstArc = NULL;
    }

    char v1, v2;
    int j, k;
    ArcNode *p1, *p2;
    for(int i = 0; i < (*G)->arcNum; i++)
    {
        look1:fflush(stdin);
        printf("构造边--输入该边所依附的两个顶点：");
        scanf("%c %c", &v1, &v2);
        getchar();

        j = LocateVex(*G, v1);
        k = LocateVex(*G, v2);

        if(j != -1 && k != -1)
        {
            p1 = (ArcNode*)malloc(sizeof(ArcNode));
            if(!p1)
            {
                printf("p1内存分配失败！\n");
                exit(0);
            }
            p1->adjVex = k;
            p1->nextArc = (*G)->vertices[j].firstArc;
            (*G)->vertices[j].firstArc = p1;

            p2 = (ArcNode*)malloc(sizeof(ArcNode));
            if(!p2)
            {
                printf("p2内存分配失败！\n");
                exit(0);
            }
            p2->adjVex = j;
            p2->nextArc = (*G)->vertices[k].firstArc;
            (*G)->vertices[k].firstArc = p2;
        }
        else
        {
            printf("该边所依附的两个顶点有误！");
            goto look1;
        }
    }
}
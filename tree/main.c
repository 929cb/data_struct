#include "main.h"
#include <string.h>

int main()
{
    BiTree T;

    //CreateBiTree(&T);
#if 0
    T = CreateTree();

    printf("先序遍历：\n");
    PreOrderTraverse(T);

    printf("最大深度：%d\n", GetMaxDepth(T));

    printf("叶子节点数：%d\n", LeafNodeNum(T));

    int k;
    printf("get哪层节点数-> ");
    scanf("%d", &k);
    getchar();
    printf("第%d层节点数：%d\n", k, LevelNodeNum(T, k));

    printf("节点总数：%d\n", CountNode(T));

    ElemType c;
    printf("搜索哪个元素的节点-> ");
    scanf("%c", &c);
    getchar();
    BiTree T1 = SearchNode(T, c);
    if(T1)
        printf("搜索到的节点：%c\n", T1->data);
    else printf("没有搜索到！\n");

    BiTree newT;
    CopyBiTree(T, &newT);
    printf("复制后的二叉树：\n");
    PreOrderTraverse(newT);


    //  BST
    printf("BST:\n");
    BiTree BT;
    ElemType arr[] = "dbbcfae";

    BT = Create_BST(arr, strlen(arr));

    BST_Delete(BT, 'd');

    InOrderTraverse(BT);

#endif

    //  哈夫曼树
    printf("哈夫曼树：\n");
    HuffmanTree HT;
    int n;

    // printf("构造哈夫曼树的原始权值个数：\n");
    // scanf("%d", &n);
    // getchar();

    CreateHuffmanTree(&HT);

    printf("中序遍历：\n");
    InOrder(*HT, HT->root);



    printf("编码表:\n");
    
    HuffmanCode HC;

    CreateHuffmanCode(HT, &HC);

    for(int i = 0; i < HC->len; i++)
    {
        printf("%c  权值：%d    路径：%s\n", HT->HTN[i + 1].data, HT->HTN[i + 1].weight, HC->code[i]);
    }


    char in[1024];
    char *enOut, *deOut;

    printf("输入需要编码的数据：");
    fgets(in, 1024, stdin);

    printf("原始数据：%s\n", in);

    enOut = Encoding(HT, HC, in);
    printf("哈夫曼编码：%s\n", enOut);

    deOut = Decoding(HT, HC, enOut);
    printf("哈夫曼解码：%s\n", deOut);

    free(enOut);
    enOut = NULL;
    free(deOut);
    deOut = NULL;

    return 0;
}

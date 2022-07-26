#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

static void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
    int num1, num2;
    int flag;

    num1 = num2 = 2147483647;

    for(int i = 1; i <= n; i++) //  找最小
    {
        if(HT->HTN[i].weight < num1 && HT->HTN[i].parent == 0)
        {
            num1 = HT->HTN[i].weight;
            *s1 = i;
            flag = i;
        }   
    }

    for(int i = 1; i <= n; i++) //  找第二小
    {
        if(i == flag) continue;

        if(HT->HTN[i].weight < num2 && HT->HTN[i].parent == 0)
        {
            num2 = HT->HTN[i].weight;
            *s2 = i;
        }    
    }
}

void CreateHuffmanTree(HuffmanTree *HT)
{
    int count = 0;

    FILE* fp = NULL;

    if(access("code.txt", F_OK) == -1)
    {
        printf("创建编码表文件\n");

        fp = fopen("code.txt", "w");

        if(!fp)
        {
            printf("%s\n", strerror(errno));
            exit(1);
        }

        printf("构造哈夫曼树的原始值：\n");
        char c;
        int w;
        while(1)
        {
            scanf("%c", &c); getchar();
            //c = fgetc(fp);
            if(c == '#') break;
            
            scanf(" %d", &w); getchar();
            fprintf(fp, "%c %d\n", c, w);

            count++;
        }
        fprintf(fp, "%d\n", count);

        fclose(fp);
        fp = NULL;
    }
    
    fp = fopen("code.txt", "r");
    

    char c_arr[100] = "";
    int w_arr[100] = {0};

    int i = 0;
    while(1)
    {
        //fscanf(fp, "%c", c_arr + i);
        c_arr[i] = fgetc(fp);
        if(c_arr[i] == '#') break;
        if(isalpha(c_arr[i]) == 0 && c_arr[i] != ',' && c_arr[i] != '.' && c_arr[i] != '!' && c_arr[i] != '?')
        {
            w_arr[i] = c_arr[i] - '0';
            c_arr[i] = ' ';
        }

        fscanf(fp, " %d\n", w_arr + i);

        i++;

        //printf("%c %d\n", c, w);
    }
    
    fscanf(fp, "%d\n", &count);
    //printf("行数：%d\n", count);


    fclose(fp);
    fp = NULL;


    *HT = (HuffmanTree)malloc(sizeof(HuffmanTree[0]));

    int m = 2 * count - 1;  //  数组共需2n-1个元素

    (*HT)->HTN = (HuffmanNode)malloc(sizeof(HTNode) * (m + 1));    //  0号单元不使用，HT[m]表示根节点
    if(!((*HT)->HTN))
    {
        printf("分配内存失败！\n");
        exit(0);
    }

    (*HT)->root = m;
    (*HT)->leafNum = count;

    (*HT)->HTN[0].left = (*HT)->HTN[0].right = -1;

    for(int i = 1; i <= m; i++) //  全部初始化为0
    {
        (*HT)->HTN[i].parent = (*HT)->HTN[i].left = ((((*HT)->HTN) + i))->right = 0;
    }


    // printf("构造哈夫曼树的原始值：\n");
    for(int i = 1; i <= count; i++) //  输入需要构建哈夫曼树的原始权值
    {
        // printf("数据：");
        // fscanf(fp, "%c", &((*HT)->HTN[i].data));
        // getchar();

        // printf("权值：");
        // scanf("%d", &((*HT)->HTN[i].weight));
        // getchar();

        (*HT)->HTN[i].data = c_arr[i - 1];
        (*HT)->HTN[i].weight = w_arr[i - 1];
    }


    int s1, s2;

    for(int i = count + 1; i <= m; i++) //  开始构造，产生n-1个新节点
    {
        Select(*HT, i - 1, &s1, &s2);   //  选择两个双亲域为0，且权值最小的两个节点，返回其下标

        (*HT)->HTN[s1].parent = (*HT)->HTN[s2].parent = i;
        (*HT)->HTN[i].left = s1;
        (*HT)->HTN[i].right = s2;

        (*HT)->HTN[i].data = ' ';
        (*HT)->HTN[i].weight = (*HT)->HTN[s1].weight + (*HT)->HTN[s2].weight;
    }

}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode *HC)
{
    *HC =  (HuffmanCode)malloc(sizeof(HuffmanCode[0]));
    (*HC)->code = (char**)malloc(sizeof(char*) * HT->leafNum);

    (*HC)->len = HT->leafNum;

    char cd[HT->leafNum];   //  临时存放编码
    memset(cd, 0, sizeof(cd));
    cd[HT->leafNum - 1] = '\0';

    for(int i = 1; i <= HT->leafNum; i++)   //  逐个求哈夫曼编码
    {
        int start = HT->leafNum - 1, child = i, fu = HT->HTN[i].parent;

        while(fu != 0)  //  只有根节点的双亲域为0
        {
            start--;
            if(HT->HTN[fu].left == child) cd[start] = '0';
            else if(HT->HTN[fu].right == child) cd[start] = '1';

            child = fu;
            fu = HT->HTN[fu].parent;
        }

        //  分配求得的编码长度对应的空间
        (*HC)->code[i - 1] = (char*)malloc(sizeof(char) * (HT->leafNum - start));
        strcpy((*HC)->code[i - 1], &cd[start]);
    }
}

void InOrder(HTTree HT, int index)
{
    //  下标0未使用
    if(HT.HTN[index].left == -1 && HT.HTN[index].right == -1) return;    

    InOrder(HT, HT.HTN[index].left);
    printf("%c  %d\n", HT.HTN[index].data, HT.HTN[index].weight);
    InOrder(HT, HT.HTN[index].right);
}


char* Encoding(HuffmanTree HT, HuffmanCode HC, char in[])
{
    int i = 0, j = 0, m = 0;
    char *out = (char*)malloc(sizeof(char) * HT->leafNum * 10);
    int strLen = strlen(in);

    for(i = 0; i < strLen; i++) //  逐个字符进行编码
    {
        for(j = 1; j <= HT->leafNum; j++)   //  逐个字符路径进行配对
        {
            if(in[i] == HT->HTN[j].data)
            {
                for(int k = 0; HC->code[j - 1][k] != '\0'; k++)
                {
                    out[m++] = HC->code[j - 1][k];
                }
            }
        }
    }

    out[m] = '\0';

    return out;
}

char* Decoding(HuffmanTree HT, HuffmanCode HC, char *in)
{
    int i = 0, j = 0, k = 0, m = 0, re = 0;
    int codeLen;
    char ch;
    char *out = (char*)malloc(sizeof(char) * strlen(in));


    while(in[i] != '\0')    //  逐个二进制位匹配
    {
        re = i;
        for(j = 0; j < HC->len; j++)    //  逐个字符编码表匹配
        {
            
            codeLen = strlen(HC->code[j]);
            for(k = 0; k < codeLen; k++)
            {
                ch = HC->code[j][k];
                if(in[i] != ch) break;
                i++;    //  当前节点路径匹配成功，则继续往后匹配
            }

            if(k >= codeLen)
            {
                out[m++] = HT->HTN[j + 1].data;
                break;
            }
            else
            {
                i = re; //  匹配失败，则二进制位指针回到失败之前的位置
            }
        }
    }

    out[m] = '\0';

    return out;
}

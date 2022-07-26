#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;

typedef char ElemType;

typedef struct Tree
{
	ElemType data;
	struct Tree *left, *right;
}BiNode, *BiTree;



Status CreateBiTree(BiTree *T);
BiTree CreateTree();
Status PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
int GetMaxDepth(BiTree T);
int LeafNodeNum(BiTree T);
int LevelNodeNum(BiTree T, int k);
int CountNode(BiTree T);
BiTree SearchNode(BiTree T, ElemType data);
void CopyBiTree(BiTree T, BiTree *newT);
void DestroyBiTree(BiTree T);


//	BST
BiTree FindNode(BiTree T, ElemType e);
BiTree FindNode2(BiTree T, ElemType e);
Status BST_Insert(BiTree *T, ElemType e);    //  不同元素才能插入成功
BiTree Create_BST(ElemType arr[], int len);
Status BST_Delete(BiTree T, ElemType e);



//	哈夫曼树
typedef struct
{
	char data;
	int weight;
	int parent, left, right;
}HTNode, *HuffmanNode;

typedef struct
{
	int root;
	HuffmanNode HTN;
	int leafNum;
}*HuffmanTree, HTTree;

//	编码表
typedef struct
{
	char** code;
	int len;
}*HuffmanCode;



void CreateHuffmanTree(HuffmanTree *HT);
void InOrder(HTTree HT, int index);
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode *HC);
char* Encoding(HuffmanTree HT, HuffmanCode HC, char in[]);
char* Decoding(HuffmanTree HT, HuffmanCode HC, char *in);


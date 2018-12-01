//二叉树递归创建 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char TElemType;
typedef struct BiTNode 
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='#')   *T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->lchild=(*T)->rchild=NULL;
		if(!*T)   exit;
		(*T)->data=ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//前序遍历 根->左->右
void FOrder(BiTNode *root)
{
	if(root)
	{
		printf("%c",root->data);
		FOrder(root->lchild);
		FOrder(root->rchild);
	}
} 
//中序遍历 左->根->右
void InOrder(BiTNode *root)
{
	if(root)
	{
		InOrder(root->lchild);
		printf("%c",root->data);
		InOrder(root->rchild);
	}
} 
//后序遍历 左->右->根 
void POrder(BiTNode *root)
{
	if(root)
	{
		POrder(root->lchild);
		POrder(root->rchild);
		printf("%c",root->data);
	} 
} 
int main(void)
{
	BiTree root;
	CreateBiTree(&root);
	FOrder(root);//前序遍历(根->左->右)
	printf("\n"); 
	InOrder(root);//中序遍历(左->根->右)
	printf("\n"); 
	POrder(root);//后序遍历(左->右->根)
	printf("\n");
	return 0;
} 

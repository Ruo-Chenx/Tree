//�������ݹ鴴�� 
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
//ǰ����� ��->��->��
void FOrder(BiTNode *root)
{
	if(root)
	{
		printf("%c",root->data);
		FOrder(root->lchild);
		FOrder(root->rchild);
	}
} 
//������� ��->��->��
void InOrder(BiTNode *root)
{
	if(root)
	{
		InOrder(root->lchild);
		printf("%c",root->data);
		InOrder(root->rchild);
	}
} 
//������� ��->��->�� 
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
	FOrder(root);//ǰ�����(��->��->��)
	printf("\n"); 
	InOrder(root);//�������(��->��->��)
	printf("\n"); 
	POrder(root);//�������(��->��->��)
	printf("\n");
	return 0;
} 

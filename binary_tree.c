#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <malloc.h>

typedef struct BiNode {
	char data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

BiTree create_btree(BiTree root)
{
	char data;
	scanf ("%c", &data); 
	if (data == '#')
		return root;
	else
	{
		root = (BiNode *)malloc(sizeof(BiNode));
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		root->lchild = create_btree(root->lchild);
		root->rchild = create_btree(root->rchild);
	}
	return root;
}

int pre_order_traverse(BiTree root)
{
	if (root == NULL)
		return 0;
	printf("%c", root->data);
	pre_order_traverse(root->lchild);
	pre_order_traverse(root->rchild);
	return 0;
}

int max_depth(BiTree root)
{
	int left, right, MDepth;
	if (root == NULL)
		return 0;
	left = max_depth(root->lchild);
	right = max_depth(root->rchild);
	if (left > right)
		MDepth = left + 1;
	else
		MDepth = right + 1;
	return MDepth;
}


int main(void)
{
	int depth;
	BiTree root = NULL;
	root = create_btree(root);
	pre_order_traverse(root);
	depth = max_depth(root);

	printf("\ndepth: %d\n", depth);


	system("pause");
	return 0;
}
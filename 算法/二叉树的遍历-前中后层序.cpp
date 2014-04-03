#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct BinaryTree{
	char value;
	BinaryTree *left;
	BinaryTree *right;
};

void InitBiTree(BinaryTree **root)
{
	*root = NULL;
}

int DestroyBiTree(BinaryTree **root)
{
	if (*root == NULL)
		return 0;
	
	BinaryTree *index;
	index = *root;

	if (index->left)
		DestroyBiTree(&index->left);
	if (index->right)
		DestroyBiTree(&index->right);
	delete(*root);
	return 0;
}


int CreateBiTree(BinaryTree **root)
{
	char value;
	cin >> value;
	if (value == '#')
		return 0;
	*root = new(BinaryTree);
	(*root)->value = value;
	(*root)->left = NULL;
	(*root)->right = NULL;
	CreateBiTree(&(*root)->left);
	CreateBiTree(&(*root)->right);
	return 0;
}

int PreOrderTraverse(BinaryTree *root)
{
	stack<BinaryTree *> stacks;
	BinaryTree *index = root;
	while(index || !stacks.empty())
	{
		if (index)
		{
			cout << index->value;
			stacks.push(index);
			index = index->left;
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			index = index->right;
		}
	}

	return 0;
}

int PreOrderRecursion(BinaryTree *root)
{
	if (root == NULL)
		return 0;
	cout << root->value;
	PreOrderRecursion(root->left);
	PreOrderRecursion(root->right);
	return 0;
}

int InOrderTraverse(BinaryTree *root)
{
	stack<BinaryTree *> stacks;
	BinaryTree *index = root;

	while (index || !stacks.empty())
	{
		if (index)
		{
			stacks.push(index);
			index = index->left;
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			if (index == NULL)
				return -1;
			cout << index->value;
			index = index->right;
		}
	}
	return 0;
}

int InOrderRecursion(BinaryTree *root)
{
	if (root == NULL)
		return 0;
	InOrderRecursion(root->left);
	cout << root->value;
	InOrderRecursion(root->right);
	return 0;
}

int PostOrderTraverse(BinaryTree *root)
{
	stack<BinaryTree *> stacks;
	BinaryTree *index = root, *tmp = NULL;
	if (root == NULL)
		return 0;
	stacks.push(index);
	while (!stacks.empty())
	{
		index = stacks.top();
		if ((index->left == NULL && index->right == NULL) ||
			((tmp != NULL) && (tmp == index->left || tmp == index->right) ))
		{
			cout << index->value;
			tmp = index;
			stacks.pop();
		}
		else
		{
			if (index->right)
				stacks.push(index->right);
			if (index->left)
				stacks.push(index->left);
		}
	}
	return 0;
}

int PostOrderRecursion(BinaryTree *root)
{
	if (root == NULL)
		return 0;
	PostOrderRecursion(root->left);
	PostOrderRecursion(root->right);
	cout << root->value;
	return 0;

}

int HierarchyBiTree(BinaryTree *root)
{
	queue<BinaryTree *> queues;
	BinaryTree *index = root;
	if (root == NULL)
		return 0;
	queues.push(index);
	while (!queues.empty())
	{
		index = queues.front();
		cout << index->value;
		queues.pop();
		if (index->left)
			queues.push(index->left);
		if (index->right)
			queues.push(index->right);

	}
	return 0;
}


int main(void)
{
	BinaryTree *root;
	InitBiTree(&root);
	CreateBiTree(&root);
	cout << "PreOrderTraverse: ";
	PreOrderTraverse(root);
	cout << endl << "PreOrderRecursion: ";
	PreOrderRecursion(root);
	cout << endl << "InOrderTraverse: ";
	InOrderTraverse(root);
	cout << endl << "InOrderRecursion: ";
	InOrderRecursion(root);
	cout << endl << "PostOrderRecursion: ";
	PostOrderRecursion(root);
	cout << endl << "PostOrderTraverse: ";
	PostOrderTraverse(root);
	cout << endl << "HierarchyBiTree: ";
	HierarchyBiTree(root);
	cout << endl;
	DestroyBiTree(&root);

	system("pause");
	return 0;
}
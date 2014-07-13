#include <iostream>


using namespace std;

#define MAX 26

typedef struct TrieTree {
	int count;
	struct TrieTree *next[MAX];
}TrieTree;

TrieTree *insert(TrieTree **root, const char *s)
{
	if (*root == NULL && s == NULL)
		return NULL;
	TrieTree *index = *root;
	while (*s != '\0')
	{
		int tmp = (*s) - 'a';
		if (index->next[tmp] != NULL)
		{
			
			index = index->next[tmp];
			index->count++;
		}
		else
		{
			TrieTree *newnode = new TrieTree;
			for (int i = 0; i < MAX; i++)
				newnode->next[i] = NULL;
			newnode->count = 1;
			index->next[tmp] = newnode;
			index = index->next[tmp];
		}
		s++;
	}
	return *root;
}

int find(TrieTree *root, const char *s)
{
	if (root == NULL && s == NULL)
		return NULL;
	TrieTree *index = root, *pre = NULL;
	while (*s != '\0')
	{
		int tmp = (*s) - 'a';
		if (index->next[tmp] != NULL)
		{
			pre = index;
			index = index->next[tmp];
		}
		else
		{
			return 0;
		}
		s++;
	}
	return index->count;

}

int main(void)
{
	TrieTree *root = NULL;
	char s[10];
	root = new TrieTree;
	for (int i = 0; i < MAX; i++)
		root->next[i] = NULL;
	int n, m;
	cin >> n;
	
	while (n--)
	{
		cin >> s;
		root = insert(&root, s);
	}

	cin >> m;
	while (m--)
	{
		cin >> s;
		cout << find(root, s) << endl;
	}
	system("pause");
	return 0;
}


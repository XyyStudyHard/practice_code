#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 35
#define MAXNUM 65535
#define NUM 35


void createGraph(int &v, int node[MAX], int graph[MAX][MAX]);
void printGraph(int v, int graph[MAX][MAX]);
int Floyd(int v, int graph[MAX][MAX], int least[MAX][MAX], int path[MAX][MAX]); //Floyd�㷨  -- ���ڶ�̬�滮��˼��
void printPath(int v, int path[MAX][MAX], int s, int d);

string rail[NUM] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11",
						"A12", "A13", "A14", "A15", "A16", "A17", "A18","B1", "B2", "B3",
						"B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", 
						"B14", "B15", "T1", "T2"};

int char2int(string s)
{
	
	for (int i = 0; i < NUM; i++)
		if (s == rail[i])
			return i;
	return -1;
}

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int v = NUM;  //v��ʾ����ĸ���
	int node[MAX], graph[MAX][MAX];
	int least[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = MAXNUM;

	//a����
	int a[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 33, 9, 10, 11, 12, 34, 13, 14, 15, 16, 17, 0};
	for (int i = 0; i < 20; i++)
	{
		graph[a[i]][a[i + 1]] = 1;
		graph[a[i + 1]][a[i]] = 1;
	}

	int b[17] = {18, 19, 20, 21, 22, 33, 23, 24, 25, 26, 27, 34, 28, 29, 30, 31, 32};
	for (int i = 0; i < 16; i++)
	{
		graph[b[i]][b[i + 1]] = 1;
		graph[b[i + 1]][b[i]] = 1;
	}

//	createGraph(v, node, graph);
//	printGraph(v, graph);
	int path[NUM][NUM]; //�洢·��
	Floyd(v, graph, least, path);
	cout << "the least path:" << endl;
	//printGraph(v, least);

	string soce, dest;
	cin >> soce >> dest;
	int s = char2int(soce);
	int d = char2int(dest);

	
	printPath(v, path, s, d);
	cout << "steps: " << least[s][d] + 1<< endl;

	return 0;
}

void createGraph(int &v, int node[MAX], int graph[MAX][MAX])
{
	cin >> v;
	int i , j;
	//�ڵ��ֵ
	for (i = 0; i < v; i++)
	{
		cin >> node[i];
	}
	//�ڵ�����ߵ�Ȩֵ������һ�����׾�������ʾ���������һ�Խڵ�ı��
	//���������ڵ�֮���Ȩֵ��
	while (cin >> i >> j)
	{
		int tmp;
		cin >> tmp;
		graph[i - 1][j - 1] = tmp;
	}
}

void printGraph(int v, int graph[MAX][MAX])
{
	if (graph == NULL || v == 0)
		return ;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (graph[i][j] == MAXNUM)
				cout << "^" << "\t";
			else
				cout << graph[i][j] << "\t";
		}
		cout << endl;
	}
}

//ʱ�临�Ӷȣ�O��n^3��,�ռ临�Ӷȣ�O��n^2��
int Floyd(int v, int graph[MAX][MAX], int least[MAX][MAX], int path[MAX][MAX])
{
	if (v == 0 || graph == NULL)
		return NULL; 

	//��ʼ����С·���ľ���ΪȨֵ�ľ���
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			least[i][j] = graph[i][j];

	//��ʼ��·��,ÿ��·����ֵָ��������ڵ�ǰ����Ǹ��ڵ㣬
	//��·����ָ�����Ľڵ㡣�����ʼ��Ϊi����i��j�ڵ��·����ʼ
	//Ϊi->j��
	for (int i = 0; i < v; i ++)
		for (int j = 0; j < v; j++)
			path[i][j] = i;  

	//��ÿһ��k�ڵ㣬���Ƿ���Գ�Ϊ�����ڵ���м�ڵ㣬ʹ���ǵ�·���ܹ���С
	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i ++)
			for (int j = 0; j < v; j++)
				if (least[i][k] + least[k][j] < least[i][j])
				{
					least[i][j] = least[i][k] + least[k][j];
					path[i][j] = path[k][j];  
				}

	return 0;
}

void printPath(int v, int path[MAX][MAX], int s, int d)
{
	stack<int> stkpath;

	int k = path[s][d];
	while (s != k)
	{
		stkpath.push(k);
		k = path[s][k];
	}
	//stkpath.push(k);
	
	cout << rail[s] ;
	while (!stkpath.empty())
	{
		cout << "->" << rail[stkpath.top()];
		stkpath.pop();
	}
	cout << "->" << rail[d] << endl;
}
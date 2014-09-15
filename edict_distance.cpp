#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;



int Min(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return c;
		else
			return b;
	}
	else
	{
		if (a < c)
			return a;
		else
			return c;
	}
}

int edit(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int **distance = new int *[len1 + 1];
	for (int i = 0 ;i < len1 + 1; i ++)
		distance[i] = new int[len2 + 1];

	distance[0][0] = 0;
	for (int i = 0; i < len2 + 1; i ++)
		distance[0][i] = i;
	for (int i = 0; i < len1 + 1; i ++)
		distance[i][0] = i;

	for (int i = 1; i < len1 + 1; i++)
		for(int j = 1; j < len2 + 1; j++)
		{
			int flag = 1;
			if (s1[i - 1] == s2[j -1])
				flag = 0;
			distance[i][j] =  Min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i -1][j - 1] + flag);
		}

	int dis = distance[len1][len2];
	
	//free the memory!
	for (int i = 0; i < len1 + 1; i++)
		delete[] distance[i];
	delete[] distance;
	distance = NULL;
	return dis;
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int dis = edit(s1, s2);
	cout << dis << endl;
	return 0;
}

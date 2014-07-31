#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100

char* LCS(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return NULL;
	int len1 = strlen(s1), len2 = strlen(s2);
	int c[MAX][MAX];
	int i, j, len = 0, end;
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					c[i][j] = 1;
				else
					c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
				c[i][j] = 0;
			if (c[i][j] > len)
			{
				len = c[i][j];
				end = j;
			}
		}
		
	}
	int start = end - len + 1;
//	char *p = (char *)malloc(sizeof(len + 1));
	char *p = new char(sizeof(len + 1));
	for (i = 0; i < len; i++)
		p[i] = s2[i + start];
	cout << "len: " << len << endl;
	p[len] = '\0';
	return p;

}


int main(void)
{
	char s1[MAX], s2[MAX];
	char *longest = NULL;
	cin >> s1 >> s2;
	longest = LCS(s1, s2);
	cout << longest << endl;
	//delete[] longest;
	system("pause");
	return 0;
}

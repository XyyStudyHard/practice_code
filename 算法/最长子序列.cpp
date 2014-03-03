#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int LCS(string str1, string str2)
{
	string::size_type len1, len2;
	unsigned int i, j;
	len1 = str1.length();
	len2 = str2.length();
	vector< vector<short> > matrix(len1 + 1);
	
	for (i = 0; i <= len1; i++)
		matrix[i].resize(len2 + 1);
	for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else 
				if(matrix[i - 1][j] >= matrix[i][j - 1])
					matrix[i][j] = matrix[i - 1][j];
				else
					matrix[i][j] = matrix[i][j - 1];
		}
	return matrix[len1][len2];
}


int main(void)
{
	string str1, str2, tmp;
	int len, count;
	ifstream fin("input20.txt");
	ofstream fout("output20.txt");
	while (1)
	{
		fin >> str1;
		fin >> str2;
		
		len = LCS(str1, str2);
		count = str1.length() - len + str2.length() - len;
		fout << count << endl;
		if (!(fin >> tmp))
			break;
		
	}
	fin.close();
	fout.close();
	return 0;
}


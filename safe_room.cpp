#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

bool checkAround(vector<string> &nums, int i, int j, int n, int m)
{
	if(i < 0 || i >= n || j < 0 || j >= m)
		return false;
	bool flag = false, flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	if (nums[i][j] == '2')
		flag = true;
	nums[i][j] = '1';
	if (i > 0 && (nums[i - 1][j] == '0' || nums[i - 1][j] == '2'))
		flag4 = checkAround(nums, i - 1, j, n, m);
	if (j > 0 && (nums[i][j - 1] == '0' || nums[i][j - 1] == '2'))
		flag1 = checkAround(nums, i, j - 1, n, m);
	if (j < m - 1 && (nums[i][j + 1] == '0' || nums[i][j + 1] == '2'))
		flag2 = checkAround(nums, i, j + 1, n, m);
	if (i < n - 1 && (nums[i + 1][j] == '0' || nums[i + 1][j] == '2'))
		flag3 = checkAround(nums, i + 1, j, n, m);
	return (flag || flag1 || flag2 || flag3 || flag4);
}

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (1){
	vector<string> nums;
	cin >> n >> m;
	bool tmp;
	for (int i = 0; i < n; i++)
	{
		string tmps;
		cin >> tmps;
		nums.push_back(tmps);
	}
	
	bool flag = false;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((nums[i][j] == '0' || nums[i][j] == '2'))
			{
				flag = checkAround(nums, i, j, n, m);
				if (flag == false)
					count ++;
			}
		}
	}
	cout << count;
	}
	return 0;
}

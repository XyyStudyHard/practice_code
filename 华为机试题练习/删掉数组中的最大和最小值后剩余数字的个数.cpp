#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 20

int main(void)
{
	freopen("in.txt", "r", stdin);
	int num[MAX], tmp, i = 0;
	while (cin >> tmp)
	{
		num[i] = tmp;
		getchar();
		i ++;
	}
	int n = i, minum = num[0], maxnum = num[0];
	int mincount = 1, maxcount = 1;

	for (i = 1; i < n; i++)
	{
		if (num[i] < minum)
		{
			mincount = 1;
			minum = num[i];
		}
		else if (num[i] == minum)
			mincount ++;
		if (num[i] > maxnum)
		{
			maxcount = 1;
			maxnum = num[i];
		}
		else if (num[i] == maxnum)
			maxcount ++;
	}
	cout << n << " " << maxcount << " " << mincount << endl;
	if (mincount == n || maxcount == n)
		cout << 0 << endl;
	else
		cout << n - mincount - maxcount << endl;
	return 0;

}

/*
输入一串数，以','分隔，输出所有数中去掉最大值、最小值之后剩下的个数。（其中最大值与最小值可能有多个）?
Smple?input：3,3,5,3,6,9,7,9???Sample?outPut:?3
*/
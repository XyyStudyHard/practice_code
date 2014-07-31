#include <iostream>
#include <vector>

using namespace std;

//lpos = start of left half; rpos = start of right half;
void Merge(vector<int> &arr, int *tmparr, int lpos, int rpos, int rightend)
{
	int leftend = rpos - 1;
	int element_num = rightend - lpos + 1;
	int tmpos = lpos;

	while (lpos <= leftend && rpos <= rightend)
	{
		if (arr[lpos] <= arr[rpos])
			tmparr[tmpos++] = arr[lpos++];  //注意简洁写法
		else
			tmparr[tmpos++] = arr[rpos++];
	}
	while (lpos <= leftend)
		tmparr[tmpos++] = arr[lpos++];
	while (rpos <= rightend)
		tmparr[tmpos++] = arr[rpos++];
	for (int i = 0; i < element_num; i++, rightend--)
		arr[rightend] = tmparr[rightend];
}

//利用分治法。
//对两个已经排好序的数组进行整合（其实是存放在一个数组里面）,最后就变成有序的了。
//从底层一个已经排好序的一层一层的向外。
//最坏情形时间复杂度、平均时间复杂度O(NlogN)
void MSort(vector<int> &arr, int *tmparr, int left, int right)
{
	int middle = 0;
	if (left < right)
	{
		middle = (left + right) / 2;
		MSort(arr, tmparr, left, middle);
		MSort(arr, tmparr, middle + 1, right);
		Merge(arr, tmparr, left, middle + 1, right);
	}
}

void MergeSort(vector<int> &arr, int N)
{
	if (arr.size() == 0 || N <= 0)
		return ;
	int *tmparr = new int[N];
	
	if (tmparr != NULL)
	{
		MSort(arr, tmparr, 0, N - 1);
		delete[] tmparr;
	}
	else
		cout << "not enough memory for tmparr!" << endl;
}

int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);
	
	MergeSort(arr, arr.size());

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}
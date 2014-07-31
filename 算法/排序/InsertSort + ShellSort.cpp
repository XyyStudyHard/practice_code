#include <iostream>
#include <vector>

using namespace std;

//所有时间复杂度为O(N^2)的简单排序法都是稳定的
//快速排序、堆排序和希尔排序等时间性能较好的排序方法都是不稳定的

//从第二个数字开始比较起，如果比前面的数字要小，那么就将前面的数字
//覆盖当前位置，直到该数字比前面的数字相等或者要打大，则将这个数字
//填到当前位置。
//O(N^2) 稳定排序
void InsertSort(vector<int> &arr)
{
	if (arr.size() == 0)
		return ;
	int i, j, tmp;
	for (i = 1; i < arr.size(); i++)
	{
		tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
			arr[j] = arr[j - 1];
		arr[j] = tmp;
	}
	return;
}


//每一趟的内部是跟插入排序一样的，每一趟的数字是相隔increment的，但是
//不是对每一趟单独的来进行排序，而是对每个increment增量，从各趟低位的
//开始比较，即从increment位开始，然后逐渐增加开始的值，就比较后面的数字
//在这一趟的数字列中由插入排序找到合适的位置，然后再处理下一列数字组。
//总的说，就是间隔increment的那些数字是同时来进行的，即和初始的数字间隔
//相同的数字一块处理。说起来挺麻烦……
//最坏情形O（N^2），不通的增量，对应的复杂度是不同的，目前最好的增量序列
//{1， 5， 19， 41， 109...}。它的复杂度是O（N^(7/6)）。
void ShellSort(vector<int> &arr, int N)
{
	int increment, i, j;
	int tmp;
	if (arr.size() == 0)
		return;
	for (increment = N / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < N; i ++)
		{
			tmp = arr[i];
			for (j = i; j >= increment; j -= increment)
				if (tmp < arr[j - increment])
					arr[j] = arr[j - increment];
				else
					break;
			arr[j] = tmp;
		}
	}
	return ;
}


int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);
	//InsertSort(arr);
	ShellSort(arr, arr.size());

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}
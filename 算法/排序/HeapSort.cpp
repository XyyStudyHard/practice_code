#include <iostream>
#include <vector>

using namespace std;

//将顶上的小的值下滤。i表示当前需要下滤的目标值的位置
//N表示堆中元素的个数。
void PerDown(vector<int> &arr, int i, int N)
{
	int child, tmp;
	//2 * i + 1是arr[i]的左孩子.如果节点时从1开始算起的话
	//左孩子就刚好是2 * i。
	for (tmp = arr[i]; (2 * i + 1) < N; i = child)
	{
		child = 2 * i + 1;
		//右孩子大于左孩子
		if (child != N - 1 && arr[child + 1] > arr[child])
			child ++;
		if (tmp < arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = tmp;
}

//先建立一个大顶堆；然后删除顶上的最大值，那么堆
//中元素的个数减少一个，将删除的最大值来填补数组中空缺的一个值，
//所以将最大值和数组中最后一个元素交换，表示从堆中删除了一个元素，
//然后对当前堆顶的元素进行下滤，调整堆。这样继续下去，直到删除完
//堆中所有的元素，此时数组中就排好序了。
//时间复杂度O（NlogN）
void HeapSort(vector<int> &arr, int N)
{
	int i;
	if (arr.size() == 0)
		return;
	
	//build heap
	for (i = N / 2; i >= 0; i--)
		PerDown(arr, i, N);
	for (i = N - 1; i >= 0; i--)
	{
		//swap a[0]和a[i]，a[i]就表示当前堆的最后一个元素
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		//堆的大小是i，当前需要下滤的节点是arr[0]
		PerDown(arr, 0, i);
	}
}

int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);
	
	HeapSort(arr, arr.size());

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define CUTOFF 10

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void InsertSort(vector<int> &arr, int left, int right)
{
	if (right < left)
		return ;
	int i, j, tmp;
	for (i = left + 1; i < right + 1; i++)
	{
		tmp = arr[i];
		for (j = i; j > left && arr[j - 1] > tmp; j--)
			arr[j] = arr[j - 1];
		arr[j] = tmp;
	}
	return;
}

int median3(vector<int> &arr, int left, int right)
{
	int middle = (left + right) / 2;
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[left] > arr[middle])
		swap(arr[left], arr[right]);
	if (arr[middle] > arr[right])
		swap(arr[middle], arr[right]);

	swap(arr[middle], arr[right - 1]);
	return arr[right - 1];   //将中值放在right-1的位置，right处的值肯定大于中值，作为向右移指针的哨兵
}

//枢纽元的选取是根据“三数中值分割法”来进行的，选取左端、右端和中心位置上的三个元素的中值作为枢纽元
//对于和枢纽元相等的元素，就让前后的两个指针i，j都停止。
//对于很小的数组（N <= 10),快速排序不如插入排序好。
void QSort(vector<int> &arr, int left, int right)
{
	int i, j;
	int pivot;
	
	if (left + CUTOFF <= right)
	{
		pivot = median3(arr, left, right);
		i = left;
		j = right - 1;
		while (i < j)
		{
			while (arr[++i] < pivot) {}
			while (arr[--j] > pivot) {}
			if (i < j)
				swap(arr[i], arr[j]);
			else
				break;
		}
		swap(arr[i], arr[right - 1]);
		QSort(arr, left, i - 1);
		QSort(arr, i + 1, right);
	}
	else
		InsertSort(arr, left, right);  //当元素个数小于CUTOFF的时候，就是用插入排序,且CUTOFF的值必须>=3, 因为我们要取三数中值。
	
}
	



void QuickSort(vector<int> &arr, int N)
{
	if (arr.size() == 0 || N <= 0)
		return;
	QSort(arr, 0, N - 1);
}

int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);
	
	QuickSort(arr, arr.size());

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";

	return 0;
}
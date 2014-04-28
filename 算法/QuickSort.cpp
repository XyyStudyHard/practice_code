#include <iostream>
#include <vector>

using namespace std;


//更多解法，参考剑指offer的jzo28.cpp

int partition(int arr[], int low, int high)
{
	//arr[0] = arr[low];
	int pivotkey = arr[low];
	while (low < high)
	{
		while (arr[high] >= pivotkey && low < high)
			high --;
		arr[low] = arr[high];
		while (arr[low] <= pivotkey && low < high)
			low ++;
		arr[high] = arr[low];
	}
	arr[low] = pivotkey;
	return low;
}


int qsort(int arr[], int low, int high)
{
	int pivotkey;
	if (arr == NULL || low < 0 || high < 0 || low > high)
		return  -1;
	if (low == high)
		 return 0;
	pivotkey = partition(arr, low, high);
	if (low < pivotkey)
		qsort(arr, low, pivotkey - 1);
	if (high > pivotkey)
		qsort(arr, pivotkey + 1, high);
	return 0;
}



int main(void)
{
	int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
	int len = 8, i = 0;
	
	qsort(arr, 0, len - 1);
	while (i < 8)
	{
		cout << arr[i] << " ";
		i ++;
	}

	cout << endl;

	system("pause");
	return 0;
}
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

void QSelect(vector<int> &arr, int k, int left, int right)
{
	int i, j;
	int pivot;
	
	if (k > right + 1)
		return ;

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
		if (k <= i)
		{
			//第k小的元素在前半部分
			QSelect(arr, k, left, i - 1);
		}
		else if (k > i + 1)
		{
			//第k小的元素在后半部分
			QSelect(arr, k, i + 1, right);
		}
		//k == i + 1时，就是当前枢纽元本身，函数结束，直接返回即可。不需要再递归
	}
	else
		InsertSort(arr, left, right);  //当元素个数小于CUTOFF的时候，就是用插入排序,且CUTOFF的值必须>=3, 因为我们要取三数中值。
}
	
int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);

	cin.clear();

	int k;
	cout << "取第k小的元素的k值：";
	cin >> k;
	QSelect(arr, k, 0, arr.size() - 1);

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	if (k < arr.size())
		cout << "第k小的元素是：" << arr[k - 1] << endl;
	else
		cout << "please input proper k (k <= " << arr.size() << ")" << endl;

	return 0;
}
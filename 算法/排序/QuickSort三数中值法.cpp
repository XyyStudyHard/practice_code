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
	return arr[right - 1];   //����ֵ����right-1��λ�ã�right����ֵ�϶�������ֵ����Ϊ������ָ����ڱ�
}

//��ŦԪ��ѡȡ�Ǹ��ݡ�������ֵ�ָ�������еģ�ѡȡ��ˡ��Ҷ˺�����λ���ϵ�����Ԫ�ص���ֵ��Ϊ��ŦԪ
//���ں���ŦԪ��ȵ�Ԫ�أ�����ǰ�������ָ��i��j��ֹͣ��
//���ں�С�����飨N <= 10),�����������������á�
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
		InsertSort(arr, left, right);  //��Ԫ�ظ���С��CUTOFF��ʱ�򣬾����ò�������,��CUTOFF��ֵ����>=3, ��Ϊ����Ҫȡ������ֵ��
	
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
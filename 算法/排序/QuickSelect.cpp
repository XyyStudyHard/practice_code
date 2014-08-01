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
			//��kС��Ԫ����ǰ�벿��
			QSelect(arr, k, left, i - 1);
		}
		else if (k > i + 1)
		{
			//��kС��Ԫ���ں�벿��
			QSelect(arr, k, i + 1, right);
		}
		//k == i + 1ʱ�����ǵ�ǰ��ŦԪ��������������ֱ�ӷ��ؼ��ɡ�����Ҫ�ٵݹ�
	}
	else
		InsertSort(arr, left, right);  //��Ԫ�ظ���С��CUTOFF��ʱ�򣬾����ò�������,��CUTOFF��ֵ����>=3, ��Ϊ����Ҫȡ������ֵ��
}
	
int main(void)
{
	vector<int> arr;
	int tmp;
	while (cin >> tmp)
		arr.push_back(tmp);

	cin.clear();

	int k;
	cout << "ȡ��kС��Ԫ�ص�kֵ��";
	cin >> k;
	QSelect(arr, k, 0, arr.size() - 1);

	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	if (k < arr.size())
		cout << "��kС��Ԫ���ǣ�" << arr[k - 1] << endl;
	else
		cout << "please input proper k (k <= " << arr.size() << ")" << endl;

	return 0;
}
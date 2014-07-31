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
			tmparr[tmpos++] = arr[lpos++];  //ע����д��
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

//���÷��η���
//�������Ѿ��ź��������������ϣ���ʵ�Ǵ����һ���������棩,���ͱ��������ˡ�
//�ӵײ�һ���Ѿ��ź����һ��һ������⡣
//�����ʱ�临�Ӷȡ�ƽ��ʱ�临�Ӷ�O(NlogN)
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
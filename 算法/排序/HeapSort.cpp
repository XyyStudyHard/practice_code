#include <iostream>
#include <vector>

using namespace std;

//�����ϵ�С��ֵ���ˡ�i��ʾ��ǰ��Ҫ���˵�Ŀ��ֵ��λ��
//N��ʾ����Ԫ�صĸ�����
void PerDown(vector<int> &arr, int i, int N)
{
	int child, tmp;
	//2 * i + 1��arr[i]������.����ڵ�ʱ��1��ʼ����Ļ�
	//���Ӿ͸պ���2 * i��
	for (tmp = arr[i]; (2 * i + 1) < N; i = child)
	{
		child = 2 * i + 1;
		//�Һ��Ӵ�������
		if (child != N - 1 && arr[child + 1] > arr[child])
			child ++;
		if (tmp < arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = tmp;
}

//�Ƚ���һ���󶥶ѣ�Ȼ��ɾ�����ϵ����ֵ����ô��
//��Ԫ�صĸ�������һ������ɾ�������ֵ��������п�ȱ��һ��ֵ��
//���Խ����ֵ�����������һ��Ԫ�ؽ�������ʾ�Ӷ���ɾ����һ��Ԫ�أ�
//Ȼ��Ե�ǰ�Ѷ���Ԫ�ؽ������ˣ������ѡ�����������ȥ��ֱ��ɾ����
//�������е�Ԫ�أ���ʱ�����о��ź����ˡ�
//ʱ�临�Ӷ�O��NlogN��
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
		//swap a[0]��a[i]��a[i]�ͱ�ʾ��ǰ�ѵ����һ��Ԫ��
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		//�ѵĴ�С��i����ǰ��Ҫ���˵Ľڵ���arr[0]
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
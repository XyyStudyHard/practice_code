#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 10

void Swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



//����������ŵĻ�׼���λ��
int Rand(int a, int b)
{
	return (int)(a + rand() % (b - a + 1));
}

//�����ڿӡ����ַ������ߡ�ͬʱ����ʼ�Ƚϵķ����������ķ���
//��Ҫһ������Ŀռ�O(1)�����׼ֵ
int QuickSortPartition1(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left > right)
		return 0;
	int rand_num = Rand(left, right); //���������׼��
	//cout << rand_num << endl;
	//int rand_num = left;
	//����׼ֵ���ַ����ĵ�һ���ַ�������������һ��λ�õ��ַ���ɻ�׼ֵ��
	//��׼ֵ������ref�У����ڵ�һ��λ�ò����˿�ȱλ
	Swap(&arr[rand_num], &arr[left]);
	char ref = arr[left]; 
	int i, j;
	i = left;
	j = right;
	while (i < j)
	{
		//�ȴӺ�����ǰ��Ƚ� ����Ϊ��׼ֵ�����ַ����ĵ�һ������С�����׼ֵ�ģ�
		while (i < j && arr[j] >= ref)
			j--;
		//���ȱ
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//��ǰ����Ƚ�
		while (i < j && arr[i] <= ref)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	//���Ŀ�ȱ��i=j������ref��ֵ�ŵ����м䡱��ǰ��С�ڸ�ֵ������Ĵ��ڸ�ֵ
	arr[i] = ref;
	//iֵ������ַ�����Ϊ�������֣��������iֵ������֮����εĽ���
	return i;
}


void QuickSort(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return;
	int i = QuickSortPartition1(arr, left, right);
	if (i > left)
		QuickSort(arr, left, i - 1);
	if (i < right)
		QuickSort(arr, i + 1, right);
}

//��n���ַ���ȡ��m���ַ������
void CombinationPartition(char *arr, int m, vector<char> &path)
{
	//�ݹ���ֹ������mΪ0����ʾ����Ҫ��ȡ��
	if (m == 0)
	{
		int len = path.size();
		for (int i = 0; i < len; i++)
			printf("%c", path[i]);
		printf("\n");
		return ;
	}
	if (*arr != '\0')
	{
		//���m���ַ��а�����ǰ���ַ�����ʣ�µ��ַ���ѡ��m-1���ַ������
		path.push_back(*arr);
		CombinationPartition(arr + 1, m - 1, path);
		path.pop_back();
		//���m���ַ��в�������ǰ���ַ�,��ʣ�µ��ַ���ѡ��m���ַ������
		CombinationPartition(arr + 1, m, path);
	}
}


void Combination(char *arr)
{
	int m = 0;
	vector<char> path;
	if (arr == NULL)
		return ;
	for (m = 1; m <= strlen(arr); m ++)
	{
		//��arr������ȡ��m���ַ�����ϣ�����Ϸ���path��
		CombinationPartition(arr, m, path);
	}
}

int main(void)
{
	char arr[MAX];

	while (cin >> arr)
	{
		if (arr == NULL)
			continue;
		QuickSort(arr, 0, strlen(arr) - 1);
		Combination(arr);
	}

//	system("pause");
	return 0;
}
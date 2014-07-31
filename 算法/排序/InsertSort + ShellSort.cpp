#include <iostream>
#include <vector>

using namespace std;

//����ʱ�临�Ӷ�ΪO(N^2)�ļ����򷨶����ȶ���
//�������򡢶������ϣ�������ʱ�����ܽϺõ����򷽷����ǲ��ȶ���

//�ӵڶ������ֿ�ʼ�Ƚ��������ǰ�������ҪС����ô�ͽ�ǰ�������
//���ǵ�ǰλ�ã�ֱ�������ֱ�ǰ���������Ȼ���Ҫ������������
//���ǰλ�á�
//O(N^2) �ȶ�����
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


//ÿһ�˵��ڲ��Ǹ���������һ���ģ�ÿһ�˵����������increment�ģ�����
//���Ƕ�ÿһ�˵��������������򣬶��Ƕ�ÿ��increment�������Ӹ��˵�λ��
//��ʼ�Ƚϣ�����incrementλ��ʼ��Ȼ�������ӿ�ʼ��ֵ���ͱȽϺ��������
//����һ�˵����������ɲ��������ҵ����ʵ�λ�ã�Ȼ���ٴ�����һ�������顣
//�ܵ�˵�����Ǽ��increment����Щ������ͬʱ�����еģ����ͳ�ʼ�����ּ��
//��ͬ������һ�鴦��˵����ͦ�鷳����
//�����O��N^2������ͨ����������Ӧ�ĸ��Ӷ��ǲ�ͬ�ģ�Ŀǰ��õ���������
//{1�� 5�� 19�� 41�� 109...}�����ĸ��Ӷ���O��N^(7/6)����
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
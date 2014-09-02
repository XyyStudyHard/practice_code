#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 65535

int main(void)
{
	int count, light;
	int n;
	cin >> n;
	int j = 0;
	light = 0;

	for (j = 1; j <= n; j++) 
	{
		count = 0;
		for (int i = 1; i <= j; i++)
		{
			if (j % i == 0) count ++;
		}
		if (count % 2 == 1)
			light ++;
	}
	cout << light << endl;
	cout << (int)sqrt(n) << endl;
	return 0;
}


/*

����-�м��⣺���ŵ�Ƶ�յ��   
һ������������װ��n(1 �� n �� 65535)յ��ƣ���ͷ��β���1��2��3����n-1��n��
ÿյ�����һ�����߿��ؿ��ơ���ʼ�����ȫ�����š�  ��n��ѧ���ӳ��ȴ�����
��һ��ѧ���Ѻ��뷲��1�ı����ĵ�ƵĿ�����һ�£����ŵڶ���ѧ���Ѻ��뷲��
2�ı����ĵ�ƵĿ�����һ�£����ŵ�����ѧ���Ѻ��뷲��3�ı����ĵ�ƵĿ�����
һ�£���˼�����ȥ������n��ѧ���Ѻ��뷲��n�ı����ĵ�ƵĿ�����һ�¡�n��
ѧ�����˹涨����󣬳��������м�յ���š� ע���������ѧ����һ�¡� 
*/
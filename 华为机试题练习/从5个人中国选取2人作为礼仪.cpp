#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 20

int main(void)
{
	freopen("in.txt", "r", stdin);
	int num[5];
	for (int i = 0; i < 5; i ++)
		cin >> num[i];
	int minus = 190, first, second;
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
		{
			int tmp = num[i] - num[j];
			if (abs(tmp) < minus)
			{
				minus = abs(tmp);
				if (tmp < 0)
				{
					first = i;
					second = j;
				}
				else
				{
					first = j;
					second = i;
				}
			}
			else if (abs(tmp) == minus)
			{
				int less;
				if (tmp < 0)
				{
					if (num[i] > num[first])
					{
						first = i;
						second = j;
					}
				}
				else
				{
					if (num[j] > num[first])
					{
						first = j;
						second = i;
					}
				}

			}
		}

	cout << num[first] << " " << num[second] << endl;
	return 0;

}

/*
Ҫ��5������ѡȡ2������Ϊ���ǣ�����ÿ���˵���߷�ΧΪ160-190��Ҫ��2���˵���߲�ֵ��С�������ֵ��ͬ�Ļ���ѡȡ������ߵ����ˣ�����������������˵���ߡ�
?
Smple?input��161?189?167?172?188?Sample?outPut:?188?189?
*/
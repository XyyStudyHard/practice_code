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
要从5个人中选取2个人作为礼仪，其中每个人的身高范围为160-190，要求2个人的身高差值最小（如果差值相同的话，选取其中最高的两人），以升序输出两个人的身高。
?
Smple?input：161?189?167?172?188?Sample?outPut:?188?189?
*/
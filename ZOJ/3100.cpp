#include <iostream>

using namespace std;


int main()
{
	int n, sum = 0, tmp = 0, max = 0, min = 1000;
	while (cin >> n && n != 0)
	{
		sum = 0;
		max = 0;
		min = 1000;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			sum += tmp;
			if (tmp > max)
				max = tmp;
			if (tmp < min)
				min = tmp;
		}
		cout << (sum - max - min) / (n - 2) << endl;
	}
	system("pause");
	return 0;
}
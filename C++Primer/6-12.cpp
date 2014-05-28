#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string str1,str, max_str;
	int max_count = 0, count = 1;
	cin >> str;
	str1 = str;
	while (cin >> str)
	{
		if (str == str1)
		{
			count ++;
		}
		else
		{
			if (count > max_count)
			{
				max_count = count;
				max_str = str1;
			}
			count = 1;
		}
		str1 = str;
	}
	if (count > max_count)
	{
		max_count = count;
		max_str = str1;
	}
	cout << max_count << " : " << max_str << endl;

	system("pause");
	return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main()
{
	vector<int> num(10);
	vector<int>::iterator iter_begin = num.begin();
	vector<int>::iterator iter_end = num.end();
	for (vector<int>::iterator iter  = iter_begin; iter != iter_end; ++iter)
	{
		cin >> *iter;
		*iter = *iter * 2;
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}
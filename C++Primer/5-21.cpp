#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<int> num;
	int tmp;
	while(cin >> tmp)
		num.push_back(tmp);
	vector<int>::iterator itr = num.begin();
	while (itr != num.end())
	{
		(*itr) = ((*itr) % 2) ? (2 * (*itr)) : (*itr);
		itr ++;
	}

	itr = num.begin();
	while (itr != num.end())
		cout << *itr++ << endl;


	system("pause");
	return 0;
}


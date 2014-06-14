#include <iostream>
#include <vector>
#include <string>


using namespace std;

#define N 100

int main(void)
{
	string first;
	int second;
	vector<pair<string, int> > vec;
	while (cin >> first >> second)
	{
		pair<string, int> num(first, second);
		vec.push_back(num);
	}
	vector<pair<string, int>>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << (*iter).first << " " << (*iter).second << endl;
	}
	

	system("pause");
	return 0;
}


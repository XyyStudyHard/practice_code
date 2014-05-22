#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string *> vp;
	string tmp;
	while (cin >> tmp)
	{
		string *pstr = new string;
		*pstr = tmp;
		vp.push_back(pstr);
	}
	vector<string *>::iterator itr = vp.begin();
	while (itr != vp.end())
	{
		cout << *(*itr) << " " << (*itr)->size() << endl;
		itr ++;
	}
	itr = vp.begin();
	while (itr != vp.end())
	{
		delete *itr;
		itr ++;
	}


	system("pause");
	return 0;
}


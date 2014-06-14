#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

#define N 100

int main(void)
{
	map<string, vector<string> > family;
	string firstname, name;
	

	while(cin >> firstname)
	{
		vector<string> secondname;
		pair<map<string, vector<string> >::iterator, bool> ret = family.insert(make_pair(firstname, secondname));
		//该家族姓氏已在map容器中存在
		if (!ret.second)
		{
			cout << "repeated surname: " << firstname << endl;
			continue;
		}
		while (cin >> name)
			family[firstname].push_back(name);
		cin.clear();
	}

	cin.clear();
	cout << "to find:" << endl;
	cin >> firstname;
	map<string, vector<string> >::iterator iter;
	iter = family.find(firstname);
	vector<string> secondname = iter->second;
	vector<string>::iterator veciter = secondname.begin();
	while (veciter != secondname.end())
	{
		cout << *veciter++ << endl;
	}


	system("pause");
	return 0;
}


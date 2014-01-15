#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main()
{
	vector<string> word;
	string tmp;
	int cnt = 0;
	while (cin >> tmp)
		word.push_back(tmp);

	for (vector<string>::size_type index = 0; index != word.size(); index ++)
	{
		tmp = word[index];
		for (string::size_type index2 = 0; index2 != tmp.size(); index2 ++)
			tmp[index2] = toupper(tmp[index2]);
		cout << tmp << " ";
		cnt ++;
		if (cnt == 8)
		{
			cnt = 0;
			cout << endl;
		}
	}

	system("pause");
	return 0;
}
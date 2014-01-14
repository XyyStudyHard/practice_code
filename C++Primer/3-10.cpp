#include <iostream>
#include <string>
#include <cctype>



using namespace std;


int main()
{
	string s, after_s;
	string::size_type index, ssize, index2;
	bool has_punct = false;
	cout << "input a string: " << endl;
	getline(cin, s);
	ssize = s.size();
	cout << ssize << "dfs" << endl;
	for (index = 0; index < ssize; index ++)
	{
		if (ispunct(s[index]))
		{
			has_punct = true;
		}
		else
		{
			after_s += s[index];
		}
	}
	if (has_punct)
		cout << after_s << endl;
	else
		cout << "no punctuation charater in the string" << endl;
	system("pause");
	return 0;
}
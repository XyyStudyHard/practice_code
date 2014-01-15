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
			after_s += s[index];  //不能像s一样，用index来表示after_s，因为after_s开始是个空值，
			                      //增加的时候，那个index所指向的位置对after_s字符串时越界的，因此会产生错误
		}
	}
	if (has_punct)
		cout << after_s << endl;
	else
		cout << "no punctuation charater in the string" << endl;
	system("pause");
	return 0;
}

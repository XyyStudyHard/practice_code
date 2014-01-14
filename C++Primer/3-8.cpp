#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s, s_space, tmp;
	while (cin >> tmp)
	{
		s += tmp;
		if (!s_space.empty())
			s_space = s_space + " " + tmp;
		else
			s_space = tmp;  
	}
	cout << s << endl;
	cout << s_space << endl;
	system("pause");
	return 0;
}
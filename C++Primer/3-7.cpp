#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)
		cout << "equal" << endl;
	else if (s1 > s2)
		cout << s1 << " is bigger than" << s2 << endl;
	else if (s1 < s2)
		cout << s2 << " is bigger than " << s1 << endl;
	string::size_type s1_size, s2_size;
	s1_size = s1.size();
	s2_size = s2.size();
	if (s1_size == s2_size)
		cout << "equal" << endl;
	else if (s1_size > s2_size)
		cout << s1 << " is longer than " << s2 << "'s size" << endl;
	else if (s1_size < s2_size)
		cout << s2 << " is longer than " << s1 << "'s size" << endl;
	system("pause");
	return 0;
}
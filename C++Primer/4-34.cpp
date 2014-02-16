#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(void)
{
	
	vector<string> strvect;
	string str;
	
	cout << "input strings" << endl;
	while(cin >> str)
		strvect.push_back(str);

	char **chrstr =  new char*[strvect.size()];
	int i = 0;
	for (vector<string>::iterator iter = strvect.begin(); iter != strvect.end(); iter ++, i++)
	{
		char *p = new char[(*iter).size() + 1];   // don't forget to plus 1
		strcpy (p, (*iter).c_str());
		chrstr[i] = p;
		cout << p << endl;
	}

	//release the strings' spaces in the string pointer array
	for (i = 0; i != strvect.size(); i ++)
		delete [] chrstr[i];
	// release the string pointer array
	delete [] chrstr;

	system("pause");
	return 0;
}
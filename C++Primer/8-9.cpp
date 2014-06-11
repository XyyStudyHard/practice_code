#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

#define N 100

int main(void)
{
	vector<string> lines;
	string filename("out.txt");
	ifstream infile;
	infile.open(filename.c_str()); // open file
	if (!infile)
	{	
		cout << "error: can not open file: " << filename << endl;
		return -1;
	}
	string s;
	infile.clear();
	while (getline(infile, s))
	{
		cout << "s: " << s << endl;
		lines.push_back(s);
	}
	infile.close();

	if (infile.eof())
	{
		cout << "vector: " << endl;
		for (vector<string>::iterator iter = lines.begin(); iter != lines.end(); iter++)
			cout << *iter << endl;
	}
	else if (infile.bad()) // 发生系统故障
		cout << "error: system failure" << endl;
	else if (infile.fail())  // 读入数据失败
		cout << "error : read failure " << endl;
	
	system("pause");
	return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 20

int main(void)
{
	freopen("in.txt", "r", stdin);
	string strs;
	stack<char> stks;
	cin >> strs;
	int flag = 0;
	for (int i = 0; i < strs.size(); i++)
	{
		switch (strs[i])
		{
		case '(':
		case '[':
			stks.push(strs[i]);
			break;
		case ')':
			if (stks.top() == '(')
			{
				stks.pop();
			}
			else
				flag = 1;
			break;
		case ']':
			if (stks.top() == '[')
			{
				stks.pop();
			}
			else
				flag = 1;
			break;
		}
		if (flag == 1)
		{
			cout << 1 << endl;
			return  0;
		}
	}
	cout << flag << endl;

	return 0;

}

/*
����һ���ַ�������������ͨ���ַ���������ɣ�����������������������[��,']'��,Ҫ����֤�����Ƿ�ƥ�䣬���ƥ�������0���������1.
?Smple?input��dfa(sdf)df[dfds(dfd)]????Smple?outPut:0
*/
*/
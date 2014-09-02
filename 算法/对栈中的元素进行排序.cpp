#include <iostream>
#include <vector>
#include <stack>



using namespace std;

stack<int> QuickSort(stack<int> stk)
{
	if (stk.empty())
		return stk;
	stack<int> s1, s2, s3;
	int pivot = stk.top();
	stk.pop();

	while (!stk.empty())
	{
		int tmp = stk.top();
		if (tmp <= pivot)
			s1.push(tmp);
		else
			s2.push(tmp);
		stk.pop();
	}
	s1 = QuickSort(s1);
	s2 = QuickSort(s2);

	while (!s1.empty())
	{
		s3.push(s1.top());
		s1.pop();
	}
	while (!s3.empty())
	{
		stk.push(s3.top());
		s3.pop();
	}
	stk.push(pivot);
	while (!s2.empty())
	{
		s3.push(s2.top());
		s2.pop();
	}
	while (!s3.empty())
	{
		stk.push(s3.top());
		s3.pop();
	}
	return stk;
}

int main(void)
{
	stack<int> stk;
	int tmp;
	while (cin >> tmp)
		stk.push(tmp);
	stk = QuickSort(stk);
	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
	return 0;
}


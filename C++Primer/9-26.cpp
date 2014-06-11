#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vec(ia, ia + 11);
	list<int> lst(ia, ia + 11);
	vector<int>::iterator itvec = vec.begin();
	list<int>::iterator itlst = lst.begin();
	for (; itvec != vec.end() && itlst != lst.end(); )
	{
		 //erase之后，迭代器都失效了，需要重新赋值，而且它返回的是已删除元素的下一个元素
		if (*itvec % 2 == 0)
			itvec = vec.erase(itvec); 
		else
			itvec ++;
		
		if (*itlst % 2)
			itlst = lst.erase(itlst);
		else
			itlst ++;
	}

	itvec = vec.begin();
	itlst = lst.begin();
	cout << "vector: " << endl;
	for (; itvec != vec.end(); itvec++)
		cout << *itvec << " "; 
	cout << endl << "list: " << endl;
	for (; itlst != lst.end(); itlst++)
		cout << *itlst << " ";
	cout << endl;
	system("pause");
	return 0;
}
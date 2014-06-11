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
		 //erase֮�󣬵�������ʧЧ�ˣ���Ҫ���¸�ֵ�����������ص�����ɾ��Ԫ�ص���һ��Ԫ��
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
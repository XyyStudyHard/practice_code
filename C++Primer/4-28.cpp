#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> ivec;
	int tmp;
	vector<int>::size_type n, i;
	while (cin >> tmp)
		ivec.push_back(tmp);
	n = ivec.size();
	int *intp = new int[n];
	cout << "this vector: ";
	i = 0;
	while (i < n)
	{
		cout << ivec[i] << " ";
		*intp = ivec[i];
		cout << *intp << endl;
		intp ++;
		i = i + 1;
	}

	system("pause");
	return 0;
}
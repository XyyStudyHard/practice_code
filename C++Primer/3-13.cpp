#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	vector<int> num;
	int tmp_num;
	vector<int>::size_type index;
	while (cin >> tmp_num)
		num.push_back(tmp_num);
	vector<int>::size_type num_size = num.size();
	if (num_size == 0)
	{
		cout << "no element!" << endl;
		return -1;
	}
	for (index = 0; index < num_size; index += 2)
		if (index + 1 != num_size)
			cout << "the sum of two adjacent elements" << num[index] + num[index + 1] << endl;
	if (num_size % 2)
		cout << "the count of numbers is odd. The last number is " << num[num_size - 1] << endl;

	for (index = 0; index < num_size - index; index ++)
		if (index != num_size - index - 1)
			cout << num[index] + num[num_size - 1 - index] << endl;
		else
			cout << "this number is not been sumed, and it's value is " << num[index];
	system("pause");
	return 0;
}
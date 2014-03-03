#include <iostream>
#include <vector>
#include <string>

using namespace std;


int lis(vector<int> arr)
{
	vector<int>::size_type len = arr.size();
	vector<int> longest(len, 1), num(len), result_list;
	int i, j;

	for (i = 0; i < len; i++)
		num[i] = i;

	for (i = 1; i < len; i ++)
	{
		for (j = 0; j < i; j ++)
		{
			if ((arr[i] > arr[j]) && (longest[i] < longest[j] + 1))
			{
				longest[i] = longest[j] + 1;
				num[i] = j;
			}
		}
	}

	int max = 0, index = 0;
	for (i = 0; i < len; i ++)
		if (longest[i] > max)
		{
			max = longest[i];
			index = i;
		}

	cout << "the list: ";
	result_list.push_back(arr[index]);
	for (j = index; num[j] != j;)
	{
		result_list.push_back(arr[num[j]]);
		j = num[j];
	}
	for (i = result_list.size() - 1; i >= 0; i -- )
		cout << result_list[i] << " ";
	cout << endl;

	return max;
}

int main(void)
{
	
	vector<int> arr;
	int tmp, longest_len;
	while(cin >> tmp)
		arr.push_back(tmp);

	longest_len = lis(arr);

	cout << "longest length: " << longest_len << endl;

	system("pause");
	return 0;
}
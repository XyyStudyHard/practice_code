#include <iostream>
#include <vector>
#include <string>

using namespace std;

// two side -- longest increase string 
int lis(vector<int> arr)
{
	vector<int>::size_type len = arr.size();
	//vector B,C are to store the longest length of the value in the same index in arr.
	//B: increase from left to right, C: inscrease from right to left
	vector<int> longest(len), B(len), C(len);
	int i, left, right, max = 0, mid;

	// from left to right
	longest[0] = arr[0];
	cout << "B:";
	//B[0] = 1;
	for (i = 1; i < len; i++)
	{
		left = 0;
		right = max;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (longest[mid] < arr[i])
				left = mid + 1;
			else
				right = mid - 1;
		}
		longest[left] = arr[i];
		B[i] = left + 1; 
		cout << B[i];
		if (left > max)
			max = left;
		
	}
	cout << endl;
	cout << max + 1 << endl;

	// from right to left
	max = 0;
	cout << endl << "C:";
	for (i = 0; i < len; i++)
		longest[i] = 0;
	longest[0] = arr[len -1];
	for (i = len - 2; i >= 0; i --)
	{
		left =0;
		right = max;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (longest[mid] < arr[i])
				left = mid + 1;
			else
				right = mid - 1;
		}
		longest[left] = arr[i];
		C[i] = left + 1;
		cout << C[i];
		if (left > max)
			max = left;
		
	}
	cout << endl;
	cout <<  max + 1 << endl;
	
	max = 0;
	for (i = 0; i < len; i ++)
		if (B[i] + C[i] > max)
			max = B[i] + C[i];
	cout << "i = " << i << endl;

	return (len - max + 1);
}

int main(void)
{
	
	vector<int> arr;
	int tmp, longest_len;
	while(cin >> tmp)
		arr.push_back(tmp);

	longest_len = lis(arr);

	cout << "least number need to be removed: " << longest_len << endl;

	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 10

void Swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



//随机产生快排的基准点的位置
int Rand(int a, int b)
{
	return (int)(a + rand() % (b - a + 1));
}

//采用挖坑、从字符串两边“同时”开始比较的方法，常见的方法
//需要一个额外的空间O(1)保存基准值
int QuickSortPartition1(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left > right)
		return 0;
	int rand_num = Rand(left, right); //随机产生基准点
	//cout << rand_num << endl;
	//int rand_num = left;
	//将基准值和字符串的第一个字符交换，这样第一个位置的字符变成基准值，
	//基准值保存在ref中，就在第一个位置产生了空缺位
	Swap(&arr[rand_num], &arr[left]);
	char ref = arr[left]; 
	int i, j;
	i = left;
	j = right;
	while (i < j)
	{
		//先从后面向前面比较 （因为基准值放在字符串的第一个，将小的填到基准值的）
		while (i < j && arr[j] >= ref)
			j--;
		//填补空缺
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//从前往后比较
		while (i < j && arr[i] <= ref)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	//最后的空缺在i=j处，将ref的值放到“中间”，前面小于该值，后面的大于该值
	arr[i] = ref;
	//i值将这个字符串分为了三部分，返回这个i值，便于之后分治的进行
	return i;
}


void QuickSort(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return;
	int i = QuickSortPartition1(arr, left, right);
	if (i > left)
		QuickSort(arr, left, i - 1);
	if (i < right)
		QuickSort(arr, i + 1, right);
}

//从n个字符中取出m个字符的组合
void CombinationPartition(char *arr, int m, vector<char> &path)
{
	//递归终止条件是m为0，表示不需要再取了
	if (m == 0)
	{
		int len = path.size();
		for (int i = 0; i < len; i++)
			printf("%c", path[i]);
		printf("\n");
		return ;
	}
	if (*arr != '\0')
	{
		//如果m个字符中包含当前的字符，在剩下的字符中选出m-1个字符的组合
		path.push_back(*arr);
		CombinationPartition(arr + 1, m - 1, path);
		path.pop_back();
		//如果m个字符中不包含当前的字符,在剩下的字符中选出m个字符的组合
		CombinationPartition(arr + 1, m, path);
	}
}


void Combination(char *arr)
{
	int m = 0;
	vector<char> path;
	if (arr == NULL)
		return ;
	for (m = 1; m <= strlen(arr); m ++)
	{
		//从arr数组中取出m个字符的组合，该组合放在path中
		CombinationPartition(arr, m, path);
	}
}

int main(void)
{
	char arr[MAX];

	while (cin >> arr)
	{
		if (arr == NULL)
			continue;
		QuickSort(arr, 0, strlen(arr) - 1);
		Combination(arr);
	}

//	system("pause");
	return 0;
}
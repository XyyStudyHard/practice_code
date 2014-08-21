#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//完全背包！每次不是有选和不选这两个选项，而是可以选择多次，即最后的结果队中，
//可以有该项多个。因此是完全背包，01背包延生
int MaxAns(int N, int M, vector<int> need, vector<int> value)
{
	vector<int> f(M + 1), p(M + 1);
	int j ;
	for (int i = 0; i <= M; i++)
	{
		f[i] = 0;
		p[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		//j表示当前所持有的奖券数。最多的为M个
		//和01背包的区别，仅仅是这个for循环是倒过来了，
		//但是产生了很不一样的效果.
		//二阶的递推公式存在差别。因为可以选取多次，所以f[j-need[i]]其实是需要
		//二阶的f[i][j - need[i]],是以本次的为基础的,而01背包里是f[i - 1][j - need[i]]
		//以上次的为基础。
		for (j = need[i]; j <= M; j++)
		{
			f[j] = max(f[j], f[j - need[i]] + value[i]); 
		}
	}
	return f[M];
	
}

	
int main(void)
{
	freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	vector<int> need, value;
	int needs, values;
	for (int i = 0; i < N; i++)
	{
		cin >> needs >> values;
		need.push_back(needs);
		value.push_back(values);
	}
	int Ans;
	Ans = MaxAns(N, M, need, value);
	cout << "最大喜好值： " << Ans << endl;
	return 0;
}
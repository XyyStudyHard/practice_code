#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxAns(int N, int M, vector<int> need, vector<int> value)
{
	vector<int> f(M + 1);
	int j ;
	for (int i = 0; i <= M; i++)
		f[i] = 0;
	for (int i = 0; i < N; i++)
	{
		//j表示当前所持有的奖券数。最多的为M个
		for (j = M; j >= need[i]; j--)
		{
			//不要第i个的时候，f[j]的值不变，仍然是前一次的结果
			//要第i个的时候，由于不能超过当前的奖券数，所以要从f[j - need[i]]项的结果为基础，加上当前的喜好度
			f[j] = max(f[j], f[j - need[i]] + value[i]); 
		}
	//	cout << f[M] << endl;
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
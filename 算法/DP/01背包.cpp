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
		//j��ʾ��ǰ�����еĽ�ȯ��������ΪM��
		for (j = M; j >= need[i]; j--)
		{
			//��Ҫ��i����ʱ��f[j]��ֵ���䣬��Ȼ��ǰһ�εĽ��
			//Ҫ��i����ʱ�����ڲ��ܳ�����ǰ�Ľ�ȯ��������Ҫ��f[j - need[i]]��Ľ��Ϊ���������ϵ�ǰ��ϲ�ö�
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
	cout << "���ϲ��ֵ�� " << Ans << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��ȫ������ÿ�β�����ѡ�Ͳ�ѡ������ѡ����ǿ���ѡ���Σ������Ľ�����У�
//�����и��������������ȫ������01��������
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
		//j��ʾ��ǰ�����еĽ�ȯ��������ΪM��
		//��01���������𣬽��������forѭ���ǵ������ˣ�
		//���ǲ����˺ܲ�һ����Ч��.
		//���׵ĵ��ƹ�ʽ���ڲ����Ϊ����ѡȡ��Σ�����f[j-need[i]]��ʵ����Ҫ
		//���׵�f[i][j - need[i]],���Ա��ε�Ϊ������,��01��������f[i - 1][j - need[i]]
		//���ϴε�Ϊ������
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
	cout << "���ϲ��ֵ�� " << Ans << endl;
	return 0;
}
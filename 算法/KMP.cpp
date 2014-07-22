#include <iostream>
#include <string>
#include <vector>

using namespace std;

//递推的思想
void getNext(string par, vector<int> &next)
{
	next.push_back(-1);
	int j = 0, k = -1;
	while (j < par.size() - 1)
	{
		if (k == -1 || par[k] == par[j])
		{
			j ++;
			k ++;
			next.push_back(k);
		}
		else
			k = next[k];
	}
}

//p[0...k - 1] = p[j - k...j - 1]
bool equals(string par, int j, int k)
{
	int i = 0;
	int s = j - k;
	for (; i < k && s < j; i ++, s ++ )
		if (par[i] != par[s])
			return false;
	return true;
}

//一般解法
void getNext2(string par, vector<int> &next)
{
	next.push_back(-1);
	next.push_back(0);
	int j = 2, k = 0;
	while (j < par.size())
	{
		for (k = j - 1; k > 0; k --)
			if (equals(par, j, k))
			{
				next.push_back(k);
				break;
			}
		if (k == 0)
			next.push_back(0);
		j++;
	}
}




int KMP(string ori, string par)
{
	vector<int> next;
	int i = 0, j = 0, count = 0;
	int lenori = ori.size(), lenpar = par.size();
	getNext2(par, next);
	while (i < lenori)
	{
		if (j == -1 || ori[i] == par[j])
		{
			i ++;
			j ++;
		}
		else
			j = next[j];
		if (j == lenpar)
		{
			count ++;
			j = next[j - 1];
			i --;
		}
	}
	return count;

}

int main(void)
{
	string ori, par;
	int n, count;
	cin >> n;
	while (n --)
	{
		cin >> par >> ori;
		count = KMP(ori, par);
		cout << count << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 65535

int main(void)
{
	int count, light;
	int n;
	cin >> n;
	int j = 0;
	light = 0;

	for (j = 1; j <= n; j++) 
	{
		count = 0;
		for (int i = 1; i <= j; i++)
		{
			if (j % i == 0) count ++;
		}
		if (count % 2 == 1)
			light ++;
	}
	cout << light << endl;
	cout << (int)sqrt(n) << endl;
	return 0;
}


/*

样题-中级题：亮着电灯的盏数   
一条长廊里依次装有n(1 ≤ n ≤ 65535)盏电灯，从头到尾编号1、2、3、…n-1、n。
每盏电灯由一个拉线开关控制。开始，电灯全部关着。  有n个学生从长廊穿过。
第一个学生把号码凡是1的倍数的电灯的开关拉一下；接着第二个学生把号码凡是
2的倍数的电灯的开关拉一下；接着第三个学生把号码凡是3的倍数的电灯的开关拉
一下；如此继续下去，最后第n个学生把号码凡是n的倍数的电灯的开关拉一下。n个
学生按此规定走完后，长廊里电灯有几盏亮着。 注：电灯数和学生数一致。 
*/
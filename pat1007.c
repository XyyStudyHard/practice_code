#include <stdio.h>

#define MAX 10000

int isprime(int *prime, int N, int *count)
{
	int i, YN, k, flag;
	prime[0] = 2;
	for (i = 1, YN = 3; YN <= N; YN += 2)
	{
		flag = 0;
		for (k = 2; k * k <= YN; k ++)
		{
			if (YN % k == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			prime[i] = YN;
			if ((prime[i] - prime[i - 1]) == 2)
				(*count) ++;
			i ++;
		}
	}
	return i;
}

int main(void)
{
	int prime[MAX], count;
	int i, N, num, result;
	while(scanf("%d", &N) != EOF)
	{
		count = 0;
		num = isprime(prime, N, &count);
		for (i = 0 ; i <num ; i++ )
			printf("%d ", prime[i]);
	//	for (i = 0; i < num; i ++)
	//	{
	//		if (((i + 1) < num) && ((prime[i+1] - prime[i]) == 2))
	//			count ++;
	//	}
		printf("%d\n", count);
	}
	return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int A[30], n, i, num, temp;
	
	i = 0;
	while(scanf("%d", &n) != EOF)
	{
		A[i] = n;
		i++;
	}

	num = i;
	//for (i = 0; i < num; i++)
	//	printf("%d ", A[i]);

	n = A[0];
	for (i = 1; i < num; i++)
		n = A[i] ^ n;
	printf("%d\n", n);
	system("pause");
}
*/

#include <iostream>

class Solution {
public:
	int singleNumber(int A[], int n){
		while(--n)
			A[0] = A[0] ^ A[n];
		return A[0];
	}
};

int main()
{
	int A[] = {11, 11, 22, 23, 23, 22, 34};
	Solution Solut;
	int m = Solut.singleNumber(A, 7);
	std::cout << m << std::endl; 
	system("pause");
}
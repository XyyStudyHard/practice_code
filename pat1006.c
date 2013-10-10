#include <stdio.h>
#include <string.h>


int main(void)
{
	int num, i;
	int resultB = 0, resultS = 0;
	int resultG = 0;
	while (scanf("%d", &num) != EOF)
	{
		resultB = 0;
		resultS = 0;
		resultG = 0;
		i = 1;
		while (num && (i <= 3))
		{
			switch(i)
			{
				case 1:	resultG = num % 10; break;
				case 2: resultS = num % 10; break;
				case 3: resultB = num % 10; break;
				default: break;
			}
			i ++;
			num = num / 10;		
		}
		while (resultB --)
			printf("B");
		while (resultS --)
			printf("S");
		i = 1;
		while (resultG --)
		{
			printf("%d", i);
			i ++;
		}
		printf("\n");
	}
	return 0;
}

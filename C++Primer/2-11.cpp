#include <iostream>


int main()
{
	int base, exp, i;
	long result = 1;

	std::cin >> base >> exp;

	//if exponent is smaller than 0, return
	if (exp < 0)
	{
		std::cout << "exponent mustn't smaller than 0" << std::endl;
		return -1;
	}

	for (i = 0; i < exp; i++)
		result = result * base;
	std::cout << "the result is "
			  << result 
			  << std::endl;
	system("pause");
}
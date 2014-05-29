#include <iostream>
#include <bitset>


using namespace std;

#define N 100

int main(void)
{
	bitset<N> bs;

	try{
		for (size_t ix = 0; ix != bs.size(); ++ix)
			bs[ix] = 1;
		bs.to_ulong();
	}catch(overflow_error err){
		cout << "overflow_error" << endl;
		cout << err.what() << endl;
	}

	system("pause");
	return 0;
}


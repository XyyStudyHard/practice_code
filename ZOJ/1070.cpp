#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	double vs, r, c, vr, w;
	int n;
	cin >> vs >> r >> c >> n;
	while (n --)
	{
		cin >> w;
		vr = vs * r * c * w / sqrt(double(r * r * c * c * w * w + 1));
		cout  << fixed << setprecision(3) << vr << endl;
	}
	system("pause");
	return 0;
}
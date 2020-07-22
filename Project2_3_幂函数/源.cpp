#include<iostream>
#include<iomanip>

using namespace std;
double Power(double x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	return x * Power(x, y - 1);
}

int main()
{
	double x;
	int y;
	cin >> x >> y;
	cout << fixed << setprecision(2) << Power(x, y) << endl;
	return 0;
}
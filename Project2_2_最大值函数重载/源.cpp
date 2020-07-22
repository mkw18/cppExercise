#include<iostream>
#include<iomanip>

using namespace std;
int MaxPro(int a, int b)
{
	return (a > b) ? a : b;
}
double MaxPro(double a, double b)
{
	return (a > b) ? a : b;
}

int main()
{
	int type;
	int i1;
	int i2;
	double d1;
	double d2;
	cin >> type;
	if (type == 1)
	{
		cin >> i1 >> i2;
		cout << MaxPro(i1, i2);
	}
	else if (type == 2)
	{
		cin >> d1 >> d2;
		cout << fixed << setprecision(1) << MaxPro(d1, d2);
	}
	return 0;
}
#include<iostream>
#include<iomanip>

using namespace std;
double LP(int n, double x)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	return ((2 * n - 1) * x * LP(n - 1, x) - (n - 1) * LP(n - 2, x)) / n;
}

int main()
{
	int n;
	double x;
	cin >> n >> x;
	cout << fixed << setprecision(1) << LP(n, x) << endl;
	return 0;
}
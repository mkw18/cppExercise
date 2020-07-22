#include<iostream>

using namespace std;
int Fib(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int n;
	int sum;
	cin >> n;
	sum = Fib(n);
	cout << sum << endl;
	return 0;
}
#include<iostream>

using namespace std;
int HCF(int a, int b)
{
	int r;
	if (a % b == 0)
	{
		return b;
	}
	while (1)
	{
		r = a % b;
		if (b % r == 0)
		{
			return r;
		}
		else
		{
			a = b;
			b = r;
		}
	}
}

int LCM(int a, int b)
{
	return a * b / HCF(a, b);
}

int main()
{
	int a;
	int b;
	int temp;
	cin >> a >> b;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	cout << HCF(a, b) << ' ' << LCM(a, b) << endl;
	return 0;
}
#include<iostream>

using namespace std;
void IsPrime(int n)
{
	int i;
	if ((n == 1) || (n ==2))
	{
		cout << n << " is a prime" << endl;
		return;
	}
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			break;
		}
	}
	if (n == i)
	{
		cout << n << " is a prime" << endl;
	}
	else if (n > i)
	{
		cout << n << " isn't a prime,it has factors:" << endl;
		for (i = i; i <= (n / 2); i++)
		{
			if (n % i == 0)
			{
				cout << i << endl;
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	IsPrime(n);
	return 0;
}
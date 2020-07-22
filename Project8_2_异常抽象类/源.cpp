#include<iostream>
using namespace std;

class Exception
{
public:
	Exception() {}
	~Exception() {}
	virtual void disp() = 0;
};

class OutOfMemory :public Exception
{
public:
	void disp()
	{
		cout << "Out Of Memory!" << endl;
	}
};

class RangeError :public Exception
{
public:
	void disp()
	{
		cout << "Number Out Of Range!" << endl;
	}
};

void funO(int n) throw(OutOfMemory)
{
	if (n > 10000)
	{
		throw OutOfMemory();
	}
}

void funR(int m, int n) throw(RangeError)
{
	if ((m < 0) || (m >= n))
	{
		throw RangeError();
	}
}

int main()
{
	int n;
	int k;
	cin >> n >> k;
	int* a = new int[n];
	try
	{
		funO(n);
	}
	catch (OutOfMemory& o)
	{
		o.disp();
		return 0;
	}
	int m;
	for (int i = 0; i < k; i++)
	{
		cin >> m;
		try
		{
			funR(m, n);
		}
		catch (RangeError& r)
		{
			r.disp();
			return 0;
		}
	}
	return 0;
}
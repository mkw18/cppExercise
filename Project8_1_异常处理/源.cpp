#include<iostream>
using namespace std;

class CException
{
public:
	CException(int t) :trigger(t) {}
	~CException() {}
	void Reason();
private:
	int trigger;
};

void CException::Reason()
{
	switch (trigger)
	{
	case 1:
	{
		cout << "out of memory" << endl;
		break;
	}
	case 2:
	{
		cout << "index out of range" << endl;
		break;
	}
	case 3:
	{
		cout << "divided by zero" << endl;
		break;
	}
	default:
		break;
	}
	return;
}

void e1(int t)throw(CException)
{
	throw CException(t);
}

int main()
{
	int t;
	for (t = 1; t <= 3; t++)
	{
		try
		{
			e1(t);
		}
		catch (CException& e)
		{
			e.Reason();
		}
	}
	return 0;
}
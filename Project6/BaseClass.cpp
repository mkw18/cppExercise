#include<iostream>
using namespace std;

class BaseClass
{
public:
	BaseClass()
	{
		cout << "BaseClass Construct" << endl;
	}
	~BaseClass()
	{
		cout << "BaseClass Destroy" << endl;
	}
};

class DerivedClass:public BaseClass
{
public:
	DerivedClass() :BaseClass()
	{
		cout << "DerivedClass Construct" << endl;
	}
	~DerivedClass()
	{
		cout << "DerivedClass Destroy" << endl;
	}
};

int main()
{
	DerivedClass derived;
	return 0;
}
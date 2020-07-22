#ifndef BASE_H
#define BASE_H
#include<iostream>
using namespace std;

class BaseClass
{
public:
	void fn1()
	{
		cout << "BaseClass fn1 run!" << endl;
	}
	void fn2()
	{
		cout << "BaseClass fn2 run!" << endl;
	}
};

class DerivedClass :public BaseClass
{
public:
	void fn1()
	{
		cout << "DerivedClass fn1 run!" << endl;
	}
	void fn2()
	{
		cout << "DerivedClass fn2 run!" << endl;
	}
};

#endif
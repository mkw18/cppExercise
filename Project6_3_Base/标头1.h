#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H
#include<iostream>
#include"BaseClass.h"
using namespace std;

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
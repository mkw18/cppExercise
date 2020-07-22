//Complex.h
#include<iostream>
#include<iomanip>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
public:
	Complex(double aa, double bb = 0)
	{
		a = aa;
		b = bb;
	}
	void add(Complex xc2);
	void show();
private:
	double a;
	double b;
};

void Complex::add(Complex xc2)
{
	//Complex c1(a,b);
	a += xc2.a;
	b += xc2.b;
	return;
}

void Complex::show()
{
	cout << fixed << setprecision(2) << a << " + " << b << "i" << endl;
	return;
}

#endif
#pragma once

#include<iostream>
#include"Shape.h"
using namespace std;

int main()
{
	Rectangle rect(1, 2);
	Circle cir(1);
	cout << funArea(&rect) << endl;
	cout << funPerim(&rect) << endl;
	cout << funArea(&cir) << endl;
	cout << funPerim(&cir) << endl;
	return 0;
}
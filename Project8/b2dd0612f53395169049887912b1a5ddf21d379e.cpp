#include<iostream>
using namespace std;

class Animal
{
public:
	int age;
};

class dog :public Animal
{
public:
	void SetAge(int n)
	{
		age = n;
	}
};

int main()
{
	return 0;
}
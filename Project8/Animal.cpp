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
	int getage()
	{
		return age;
	}
	void showage()
	{
		cout << "the age is: " << age << endl;
	}
};

int main()
{
	dog Dog;
	int n;
	cin >> n;
	Dog.SetAge(n);
	cout << "age is: " << Dog.getage() << endl;
	Dog.showage();
	return 0;
}
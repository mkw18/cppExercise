#include<iostream>
using namespace std;

class Vehicle
{
public:
	Vehicle()
	{
		cout << "vehicle Construct" << endl;
	}
	~Vehicle()
	{
		cout << "vehicle Destroy" << endl;
	}
};

class bicycle :virtual public Vehicle
{
public:
	bicycle():Vehicle()
	{
		cout << "bicycle Construct" << endl;
	}
	~bicycle()
	{
		cout << "bicycle Destroy" << endl;
	}
};

class motorcar :virtual public Vehicle
{
public:
	motorcar() :Vehicle()
	{
		cout << "motorcar Construct" << endl;
	}
	~motorcar()
	{
		cout << "motorcar Destroy" << endl;
	}
};

class motorcycle :public bicycle, public motorcar
{
public:
	motorcycle() :Vehicle(), bicycle(), motorcar()
	{
		cout << "motorcycle Construct" << endl;
	}
	~motorcycle()
	{
		cout << "motorcycle Destroy" << endl;
	}
};

int main()
{
	motorcycle a;
	return 0;
}
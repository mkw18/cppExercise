#include<iostream>
using namespace std;

class vehicle
{
public:
	virtual void Run()
	{
		cout << "vehicle run" << endl;
	}
	virtual void Stop()
	{
		cout << "vehicle stop" << endl;
	}
};

class bicycle :virtual public vehicle
{
public:
	virtual void Run()
	{
		cout << "bicycle run" << endl;
	}
	virtual void Stop()
	{
		cout << "bicycle stop" << endl;
	}
};

class motorcar :virtual public vehicle
{
public:
	virtual void Run()
	{
		cout << "motorcar run" << endl;
	}
	virtual void Stop()
	{
		cout << "motorcar stop" << endl;
	}
};

class motorcycle :public bicycle, public motorcar
{
public:
	void Run()
	{
		cout << "motorcycle run" << endl;
	}
	void Stop()
	{
		cout << "motorcycle stop" << endl;
	}
};

void run(vehicle* ptr)
{
	ptr->Run();
}
void stop(vehicle* ptr)
{
	ptr->Stop();
}

int main()
{
	vehicle Vehicle;
	bicycle Bicycle;
	motorcar Motorcar;
	motorcycle Motorcycle;
	run(&Vehicle);
	stop(&Vehicle);
	run(&Bicycle);
	stop(&Bicycle);
	run(&Motorcar);
	stop(&Motorcar);
	run(&Motorcycle);
	stop(&Motorcycle);
	return 0;
}
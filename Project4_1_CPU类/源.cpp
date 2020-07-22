#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class CPU
{
public:
	CPU(int nn, int ff, double vv)
	{
		n = (rank)nn;
		f = ff;
		v = vv;
	}
	void run();
	void stop();
	~CPU() {}
private:
	enum rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
	rank n;
	int f;
	double v;
};

void CPU::run()
{
	cout << "CPU RUN\n";
	cout << "CPU rank: P" << n << endl;
	cout << "CPU frequency: " << f << " MHz" << endl;
	cout << "CPU voltage: " << setiosflags(ios::fixed) << setprecision(2) << v << " V" << endl;
}

void CPU::stop()
{
	cout << "CPU STOP\n";
}

class RAM
{
public:
	RAM(string newtype)
	{
		type = newtype;
	}
	void run();
	void stop();
	~RAM() {}
private:
	string type;
};

void RAM::run()
{
	cout << "RAM RUN\n";
	cout << "RAM type: " << type << endl;
}

void RAM::stop()
{
	cout << "RAM STOP\n";
}

class CDROM
{
public:
	CDROM(string newtype)
	{
		type = newtype;
	}
	void run();
	void stop();
	~CDROM() {}
private:
	string type;
};

void CDROM::run()
{
	cout << "CDROM RUN\n";
	cout << "CDROM type: " << type << endl;
}

void CDROM::stop()
{
	cout << "CDROM STOP\n";
}

class Computer
{
public:
	Computer(CPU ccpu, RAM rram, CDROM cd) :cpu(ccpu), ram(rram), cdrom(cd)
	{
		cpu = ccpu;
		ram = rram;
		cdrom = cd;
	}
	void run();
	void stop();
	~Computer() {}
private:
	CPU cpu;
	RAM ram;
	CDROM cdrom;
};

void Computer::run()
{
	cout << "Computer RUN\n";
	cpu.run();
	ram.run();
	cdrom.run();
}
void Computer::stop()
{
	cdrom.stop();
	ram.stop();
	cpu.stop();
	cout << "Computer STOP\n";
}

int main()
{
	int f;
	int n;
	double v;
	int i = 0;
	int j;
	string type1;
	string type2;
	string member;
	while (i < 3)
	{
		cin >> member;
		if (member == "CPU")
		{
			cin >> n >> f >> v;
			i++;
		}
		else if (member == "RAM")
		{
			cin >> type1;
			i++;
		}
		else if (member == "CDROM")
		{
			cin >> type2;
			i++;
		}
	}
	CPU cpu(n, f, v);
	RAM ram(type1);
	CDROM cdrom(type2);
	Computer computer(cpu, ram, cdrom);
	computer.run();
	computer.stop();
	return 0;
	/*
CPU 1 2500 1.1
RAM DOR2
CDROM IDE
*/
}
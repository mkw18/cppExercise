/*#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
class Employee
{
public:
	Employee(char Name[], char Address[], char City[], char Postcode[])
	{
		for (int i = 0; i < 50; i++)
		{
			name[i] = 0;
			address[i] = 0;
			city[i] = 0;
			postcode[i] = 0;
		}
		strcat(name, Name);
		strcat(address, Address);
		strcat(city, City);
		strcat(postcode, Postcode);
	}
	void change_name(Employee &c,char NewName[])
	{
		for (int i = 0; i < 50; i++)
		{
			c.name[i] = 0;
		}
		strcat(c.name, NewName);
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "City: " << city << endl;
		cout << "Address: " << address << endl;
		cout << "Postcode: " << postcode << endl;
	}
private:
	char name[50];
	char address[50];
	char city[50];
	char postcode[50];
};

int main()
{
	char name[50];
	char city[50];
	char address[50];
	char postcode[50];
	char newname[50];
	int i;
	for (i = 0; i < 50; i++)
	{
		name[i] = 0;
		city[i] = 0;
		address[i] = 0;
		postcode[i] = 0;
		newname[i] = 0;
	}
	cin >> name;
	cin >> city;
	cin >> address;
	cin >> postcode;
	Employee employee(name, address, city, postcode);
	employee.display();
	cin >> newname;
	employee.change_name(employee, newname);
	employee.display();
	return 0;
}*/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Employee
{
private:
	char name[50];
	char address[50];
	char city[50];
	char postcode[50];
public:
	Employee(char Name[], char Address[], char City[], char Postcode[]) {
		for (int i = 0; i < 50; i++)
		{
			name[i] = 0;
			address[i] = 0;
			city[i] = 0;
			postcode[i] = 0;
		}
		strcpy(name, Name);
		strcpy(address, Address);
		strcpy(city, City);
		strcpy(postcode, Postcode);
	}
	void change_name(char Name[])
	{
		for (int i = 0; i < 50; i++)
			name[i] = 0;
		strcpy(name, Name);
	}
	void display();
};

void Employee::display()
{
	cout << "Name: " << name << endl << "City: " << city << endl << "Address: " << address << endl << "Postcode: " << postcode << endl;
}

int main() {
	char Name[50], Address[50], City[50], Postcode[50], new_name[50];
	for (int i = 0; i < 50; i++)
	{
		Name[i] = 0;
		Address[i] = 0;
		City[i] = 0;
		Postcode[i] = 0;
		new_name[i] = 0;
	}
	gets(Name);
	gets(City);
	gets(Address);
	gets(Postcode);
	Employee e(Name, Address, City, Postcode);
	e.display();
	cin >> new_name;
	e.change_name(new_name);
	e.display();
	return 0;
}
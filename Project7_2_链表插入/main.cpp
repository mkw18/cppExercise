#include<iostream>
#include"LinkedList.h"
#include"Node.h"
using namespace std;

int main()
{
	LinkedList<int>listA;
	LinkedList<int>listB;
	for (int i = 0; i < 5; i++)
	{
		int item;
		cin >> item;
		listA.insertRear(item);
	}
	listA.reset();
	for (int i = 0; i < 5; i++)
	{
		int item;
		cin >> item;
		listB.insertRear(item);
	}
	listB.reset();
	for (int i = 0; i < 5; i++)
	{
		listA.insertRear(listB.data());
		listB.next();
	}
	listA.reset();
	for (int i = 0; i < 10; i++)
	{
		cout << listA.data() << ' ';
		listA.next();
	}
	cout << endl;
	return 0;
}
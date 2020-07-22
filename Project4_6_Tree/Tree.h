#ifndef TREE_H
#define TREE_H
#include<iostream>
using namespace std;

class Tree
{
public:
	int grow(int year)
	{
		return ages + year;
	}
	int age()
	{
		return ages;
	}
private:
	int ages;
};

#endif
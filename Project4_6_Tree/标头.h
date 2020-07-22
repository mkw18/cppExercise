#ifndef _TREE_H_
#define _TREE_H_
#include<iostream>
using namespace std;

class Tree
{
public:
	Tree(int age) :ages(age) {}
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
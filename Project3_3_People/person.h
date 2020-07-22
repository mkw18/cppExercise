#ifndef _PERSON_H
#define _PERSON_H
#include<iostream>
#include<iomanip>

using namespace std;
class Person
{
public:
	Person(const int& height, const float& weight);
	void showInfo();
private:
	int height;
	float weight;
};
Person::Person(const int& height, const float& weight) :height(height), weight(weight) {}
void Person::showInfo()
{
	cout << height << ',' << fixed << setprecision(2) << weight << endl;
}
#endif
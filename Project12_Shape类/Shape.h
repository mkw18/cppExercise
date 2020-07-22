#ifndef __SHAPE_H
#define __SHAPE_H
#include<iostream>

using namespace std;
static const float Pi = 3.14;
class Shape
{
public:
	virtual float getArea() = 0;
	virtual float getPerim() = 0;
};
class Rectangle :public Shape
{
public:
	Rectangle(const float& width, const float& height) :Width(width), Height(height) {}
	virtual float getArea()
	{
		return Width * Height;
	}
	virtual float getPerim()
	{
		return 2 * (Width + Height);
	}
private:
	float Width;
	float Height;
};
class Circle :public Shape
{
public:
	Circle(const float& radius) :Radius(radius) {}
	virtual float getArea()
	{
		return Pi * Radius * Radius;
	}
	virtual float getPerim()
	{
		return 2 * Pi * Radius;
	}
private:
	float Radius;
};
float funArea(Shape* ptr)
{
	return ptr->getArea();
}
float funPerim(Shape* ptr)
{
	return ptr->getPerim();
}
#endif
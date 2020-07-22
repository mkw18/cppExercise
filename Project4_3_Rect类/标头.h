#ifndef RECT_H
#define RECT_H
#include<iostream>
using namespace std;

class Rect
{
public:
	Rect(const float& top, const float& left, const float& bottom, const float& right);
	float getArea() const;
private:
	float top;
	float left;
	float bottom;
	float right;
};

Rect::Rect(const float& top, const float& left, const float& bottom, const float& right) :
	top(top), left(left), bottom(bottom), right(right) {}

float Rect::getArea() const
{
	return (top - bottom) * (right - left);
}

#endif
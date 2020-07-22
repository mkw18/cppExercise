#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
const float Pi = 3.1415926;
int main()
{
	int n;
	int width;
	int height;
	int square;
	int tri1;
	int tri2;
	int tri3;
	double p;
	int radius;
	double area = 0;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		cin >> width >> height;
		area = width * height;
		break;
	}
	case 2:
	{
		cin >> square;
		area = square * square;
		break;
	}
	case 3:
	{
		cin >> tri1 >> tri2 >> tri3;
		p = (double)(tri1 + tri2 + tri3) / 2;
		//cout << p << endl;
		area = sqrt(p * (p - tri1) * (p - tri2) * (p - tri3));
		break;
	}
	case 4:
	{
		cin >> radius;
		area = Pi * radius * radius;
		break;
	}
	default:
		break;
	}
	cout << fixed << setprecision(2) << area << endl;
	return 0;
}
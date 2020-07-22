#include<iostream>
using namespace std;

class Point
{
public:
	Point(int x, int y)
	{
		_x = x;
		_y = y;
	}
	int getx()
	{
		return _x;
	}
	int gety()
	{
		return _y;
	}
	Point operator++()
	{
		return Point(_x + 1, _y + 1);
	}
	Point operator--()
	{
		return Point(_x - 1, _y - 1);
	}
private:
	int _x;
	int _y;
};

int main()
{
	int type;
	int x;
	int y;
	cin >> type >> x >> y;
	Point point(x, y);
	if (type == 1)
	{
		cout << (++point).getx() << ' ' << (++point).gety() << endl;
	}
	else if (type == 2)
	{
		cout << (--point).getx() << ' ' << (--point).gety() << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class T
{
public:
	int x;
	int y;
	T(int xx, int yy);
	bool operator <(const T& p) const;
	bool operator ==(const T& p) const;
};

T::T(int xx = 0, int yy = 0)
{
	x = xx;
	y = yy;
}

bool T::operator<(const T& p) const
{
	if (x < p.x)
	{
		return true;
	}
	else if ((x == p.x) && (y < p.y))
	{
		return true;
	}
	return false;
}

bool T::operator==(const T& p) const
{
	return ((x == p.x) && (y == p.y));
}

int main()
{
	int N;
	cin >> N;
	vector<T> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (vector<T>::iterator i = a.begin(); i < a.end(); i++)
	{
		cout << i->x << " " << i->y << endl;
	}
	return 0;
}
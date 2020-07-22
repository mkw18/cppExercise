#include<iostream>
using namespace std;

class BOX
{
public:
	BOX(int aa)
	{
		a = aa;
	}
	~BOX() {}
	int volume(int a)
	{
		return a * a * a;
	}
	int area(int a)
	{
		return 6 * a * a;
	}
private:
	int a;
};

int main()
{
	int a;
	cin >> a;
	BOX box(a);
	cout << box.volume(a) << ' ' << box.area(a) << endl;
	return 0;
}
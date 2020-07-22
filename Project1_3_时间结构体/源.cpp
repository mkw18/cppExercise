#include<iostream>
using namespace std;

struct Time
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

int main()
{
	Time time;
	cin >> time.year >> time.month >> time.day >> time.hour >> time.minute >> time.second;
	cout << time.year << ' ' << time.month << ' ' << time.day << ' ' 
		<< time.hour << ' ' << time.minute << ' ' << time.second << endl;
	return 0;
}
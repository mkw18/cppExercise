#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class date
{
public:
	void changedate(string Year, string Month, string Day)
	{
		year = Year;
		month = Month;
		day = Day;
	}
	date() :year("0"), month("0"), day("0") {}
	void showdate(string year, string month, string day);
	string getyear();
	string getmonth();
	string getday();
	~date() {}
private:
	string year;
	string month;
	string day;
};

void date::showdate(string year, string month, string day)
{
	cout << year << "-" << month << "-" << day << ' ';
	return;
}
string date::getyear()
{
	return year;
}
string date::getmonth()
{
	return month;
}
string date::getday()
{
	return day;
}

class People
{
public:
	void changePeople(string Number, char Sex, date Birthday, string Id)
	{
		number = Number;
		sex = Sex;
		birthday = Birthday;
		id = Id;
	}
	People() :number("0"), sex("0"), birthday(), id("0") {}
	~People() {}
	void showinfo();
	string getnum()
	{
		return number;
	}
private:
	string number;
	string sex;
	date birthday;
	string id;
};

void People::showinfo()
{
	cout << number << ' ' << sex << ' ';
	birthday.showdate(birthday.getyear(), birthday.getmonth(), birthday.getday());
	cout << id << endl;
}

template<class T>
void sort(T p[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j <= (n - 1 - i); j++)
		{
			if (p[j].getnum() > p[j + 1].getnum())
			{
				T temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

template<class T1, class T2>
int search(T1 p[], int n, T2 key)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].getnum() == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	People p[5];
	int n = 5;
	for (int i = 0; i < n; i++)
	{
		string number;
		char sex;
		string Birthday;
		string id;
		string year;
		string month;
		string day;
		cin >> number >> sex >> Birthday >> id;
		year.assign(Birthday, 0, 4);
		month.assign(Birthday, 5, 1);
		day.assign(Birthday, 7, 1);
		date birthday;
		birthday.changedate(year, month, day);
		p[i].changePeople(number, sex, birthday, id);
	}
	sort(p, n);
	for (int i = 0; i < n; i++)
	{
		p[i].showinfo();
	}
	string key;
	cin >> key;
	int match = search(p, n, key);
	p[match].showinfo();
	return 0;
}
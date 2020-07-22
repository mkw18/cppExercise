#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class date
{
public:
	date(string Year, string Month, string Day)
	{
		year = Year;
		month = Month;
		day = Day;
	}
	void showdate(string year,string month,string day);
	string getyear();
	string getmonth();
	string getday();
	~date() {}
private:
	string year;
	string month;
	string day;
};

void date::showdate(string year,string month,string day)
{
	cout << "birthday: " << year << "-" << month << "-" << day << endl;
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
	People(string Number, char Sex, date Birthday, string Id) :birthday(Birthday)
	{
		number = Number;
		sex = Sex;
		id = Id;
	}
	void check(date birthday, string id);
	void showinfo(string number, char sex, date birthday, string id);
	~People() {}
private:
	string number;
	char sex;
	date birthday;
	string id;
};

void People::check(date birthday, string id)
{
	string idyear;
	string idmonth;
	string idday;
	idyear.assign(id, 6, 4);
	idmonth.assign(id, 10, 2);
	idday.assign(id, 12, 2);
	if (idyear == birthday.getyear() && idmonth == birthday.getmonth() && idday == birthday.getday())
	{
		return;
	}
	else
	{
		cout << "birthday mismatch!" << endl;
	}
}
void People::showinfo(string number, char sex, date birthday, string id)
{
	check(birthday, id);
	cout << "number: " <<number << endl;
	if (sex == 'M')
	{
		cout << "sex: male\n";
	}
	else if (sex == 'F')
	{
		cout << "sex: female\n";
	}
	birthday.showdate(birthday.getyear(), birthday.getmonth(), birthday.getday());
	cout << "id: " << id << endl;
}

int main()
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
	month.assign(Birthday, 5, 2);
	day.assign(Birthday, 8, 2);
	date birthday(year, month, day);
	People people(number, sex, birthday, id);
	people.showinfo(number, sex, birthday, id);
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

class date
{
public:
	date(char y[], char m[], char d[])
	{
		for (int i = 0; i < 5; i++)
		{
			year[i] = y[i];
		}
		for (int i = 0; i < 3; i++)
		{
			month[i] = m[i];
			day[i] = d[i];
		}
	}
	~date() {}
	char* gety()
	{
		return year;
	}
	char* getm()
	{
		return month;
	}
	char* getd()
	{
		return day;
	}
	void show();
private:
	char year[5];
	char month[3];
	char day[3];
};
void date::show()
{
	cout << "Birthday: " << year << "-" << month << "-" << day << endl;
}

class People
{
public:
	People(char Name[11], char Num[7], char Sex[7], date Birth, char Id[20]);
	void show();
	void judge(date &birthday);
private:
	char name[11];
	char number[7];
	char sex[7];
	date birthday;
	char id[20];
};

People::People(char Name[11], char Num[7], char Sex[7], date Birth, char Id[20]):birthday(Birth)
{
	for (int i = 0; i < 11; i++)
	{
		name[i] = Name[i];
	}
	for (int i = 0; i < 7; i++)
	{
		number[i] = Num[i];
		sex[i] = Sex[i];
	}
	for (int i = 0; i < 20; i++)
	{
		id[i] = Id[i];
	}
}

void People::judge(date &birthday)
{
	for (int i = 0; i < 4; i++)
	{
		if (birthday.gety()[i] != id[i + 6])
		{
			//cout << birthday.gety()[i] << endl;
			//cout << id[i + 5] << endl;
			cout << "birthday mismatch!\n";
			return;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (birthday.getm()[i] != id[i + 10])
		{
			cout << "birthday mismatch!\n";
			return;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (birthday.getd()[i] != id[i + 12])
		{
			cout << "birthday mismatch!\n";
			return;
		}
	}
	return;
}
void People::show()
{
	judge(birthday);
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Sex: " << sex << endl;
	birthday.show();
	cout << "ID: " << id << endl;
}

int main()
{
	char name[11];
	char number[7];
	char sex[7];
	char birth[11];
	char year[5];
	char month[3];
	char day[3];
	char id[20];
	for (int i = 0; i < 11; i++)
	{
		name[i] = 0;
		birth[i] = 0;
	}
	for (int i = 0; i < 7; i++)
	{
		number[i] = 0;
		sex[i] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		id[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		year[i] = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		month[i] = 0;
		day[i] = 0;
	}
	cin >> name >> number >> sex >> birth >> id;
	for (int i = 0; i < 4; i++)
	{
		year[i] = birth[i];
	}
	for (int i = 0; i < 2; i++)
	{
		month[i] = birth[i + 5];
		day[i] = birth[i + 8];
	}
	date birthday(year, month, day);
	People peo(name, number, sex, birthday, id);
	peo.show();
	return 0;
}
#include<iostream>
#include<string>

using namespace std;
class People
{
public:
	People(string n, string s, string b, string i) :number(n), sex(s), birthday(b), id(i) {}
	friend int operator== (const People& p1, const People& p2);
	void operator= (const People& p1);
private:
	string number;
	string sex;
	string birthday;
	string id;
};

int operator==(const People& p1, const People& p2)
{
	return (p1.id == p2.id);
}

void People::operator=(const People& p1)
{
	number = p1.number;
	sex = p1.sex;
	birthday = p1.birthday;
	id = p1.id;
	cout << p1.number << ' ' << p1.sex << ' ' << p1.birthday << ' ' << p1.id << endl;
}

int main()
{
	int type;
	string p1_n;
	string p1_s;
	string p1_b;
	string p1_i;
	string p2_n;
	string p2_s;
	string p2_b;
	string p2_i;
	cin >> type;
	if (type == 1)
	{
		cin >> p1_n >> p1_s >> p1_b >> p1_i >> p2_n >> p2_s >> p2_b >> p2_i;
		People p1(p1_n, p1_s, p1_b, p1_i);
		People p2(p2_n, p2_s, p2_b, p2_i);
		cout << (p1 == p2) << endl;
	}
	else if (type == 2)
	{
		cin >> p1_n >> p1_s >> p1_b >> p1_i;
		People p1(p1_n, p1_s, p1_b, p1_i);
		People p2("0", "0", "0", "0");
		p2 = p1;
	}
	return 0;
}
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class CLIENT
{
public:
	CLIENT()
	{
	cout << "server name: " << ServerName << endl;
	cout << "client number: " << ClientNum << endl;
	}
	string getServerName()
	{
		return ServerName;
	}
	int getClientNum()
	{
		return ClientNum;
	}
	static void ChangeServerName(/*CLIENT &c,*/string NewName)
	{
		/*c.*/ServerName = NewName;
	}
	void add(int diff)
	{
		ClientNum += diff;
		if (ClientNum > 100000)
		{
			ClientNum = 100000;
		}
	}
	void sub(int diff)
	{
		if (ClientNum >= diff)
		{
			ClientNum -= diff;
		}
		else
		{
			ClientNum = 0;
		}
	}
	~CLIENT() {}
private:
	static string ServerName;
	static int ClientNum;
};


string CLIENT::ServerName = "Server1";
int CLIENT::ClientNum = 0;

int main()
{
	int n;
	string type;
	string NewName = "Server1";
	int diff;
	int NewNum = 0;
	cin >> n;
	CLIENT client;
	for (int i = 0; i < n; i++)
	{
		cin >> type;
		if (type == "rename")
		{
			cin >> NewName;
			CLIENT::ChangeServerName(/*client,*/NewName);
		}
		else if (type == "add")
		{
			cin >> diff;
			client.add(diff);
		}
		else if (type == "sub")
		{
			cin >> diff;
			client.sub(diff);
		}
		cout << "server name: " <<  client.getServerName() << endl;
		cout << "client number: " << client.getClientNum() << endl;
	}
	return 0;
}
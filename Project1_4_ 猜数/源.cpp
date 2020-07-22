#include<iostream>
using namespace std;

int main()
{
	char type;
	int set = 0;
	int guess= 0;
	cin >> type >> set;
	if (type == 'w')
	{
		while (1)
		{
			cin >> guess;
			if (guess == set)
			{
				cout << "True" << endl;
				break;
			}
			else
			{
				cout << "False" << endl;
			}
		}
	}
	else if (type == 'd')
	{
		do
		{
			cin >> guess;
			if (guess == set)
			{
				cout << "True" << endl;
				break;
			}
			else
			{
				cout << "False" << endl;
			}
		} while (1);
	}
	return 0;
}
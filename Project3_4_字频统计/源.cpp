#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct charInfo
{
	char c;
	int code;
	int f;
};

int main()
{
	string s;
	getline(cin, s);
	int space = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '\0';
			space++;
			for (unsigned int j = i; j < s.length() - 1; j++)
			{
				if (s[j + 1] == '\0')
				{
					break;
				}
				else
				{
					char temp;
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
		}
	}
	int len = s.length() - space;
	charInfo* info = new charInfo[len];
	for (int i = 0; i < len; i++)
	{
		info[i].c = s[i];
		info[i].code = (int)s[i];
	}
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
		{
			if (info[j].code > info[j + 1].code)
			{
				charInfo temp;
				temp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		info[i].f = 0;
	}
	for (int i = 0; i < len; i++)
	{
		info[i].f = 0;
		for (int j = i; j < len; j++)
		{
			if (info[i].c == info[j].c)
			{
				info[i].f++;
			}
			else
			{
				break;
			}
		}
		cout << info[i].c << ' ' << info[i].f << endl;
		i += info[i].f - 1;
	}
	return 0;
}
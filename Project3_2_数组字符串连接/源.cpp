#include<iostream>

using namespace std;
int main()
{
	int m;
	int n;
	cin >> m >> n;
	char* s1 = new char[m + 1];
	char* s2 = new char[n + 1];
	char* s3 = new char[m + n + 1];
	for (int i = 0; i < m; i++)
	{
		s1[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		s2[i] = 0;
	}
	for (int i = 0; i < (m + n + 1); i++)
	{
		s3[i] = 0;
	}
	cin >> s1 >> s2;
	for (int i = 0; i < m; i++)
	{
		s3[i] = s1[i];
	}
	for (int i = 0; i < n; i++)
	{
		s3[m + i] = s2[i];
	}
	cout << s3 << endl;
	delete s1;
	delete s2;
	delete s3;
	return 0;
}
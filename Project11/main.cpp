#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N;
	string a;
	string b;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		int len1 = a.length();
		int len2 = b.length();
		vector<int> c(len1 + len2);
		for (int m = 0; m < len1 + len2; m++)
		{
			c[m] = 0;
		}
		for (int j = 0; j < len2; j++)
		{
			int multi1 = b[len2 - j - 1] - 48;
			for (int k = 0; k < len1; k++)
			{
				int multi2 = a[len1 - k - 1] - 48;
				int result = multi1 * multi2;
				c[len1 + len2 - k - j - 1] += result % 10;
				c[len1 + len2 - k - j - 2] += result / 10 + c[len1 + len2 - k - j - 1] / 10;
				if (c[len1 + len2 - k - j - 2] / 10 != 0)
				{
					c[len1 + len2 - k - j - 3] += c[len1 + len2 - k - j - 2] / 10;
				}
				c[len1 + len2 - k - j - 1] %= 10;
				c[len1 + len2 - k - j - 2] %= 10;
			}
		}
		while (1)
		{
			if (c[0] == 0)
			{
				c.erase(c.begin());
			}
			else
			{
				break;
			}
		}
		int len = c.size();
		for (int n = 0; n < len; n++)
		{
			cout << c[n];
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		vector<int> a(M);
		vector<int> b(M);
		for (int j = 0; j < M; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < M; j++)
		{
			cin >> b[j];
		}
		stack<int> c;
		int apos = 0;
		int bpos = 0;
		for (bpos = 0; bpos < M; bpos++)
		{
			bool reach = false;
			int pred = 0;
			for (pred = apos; pred < M; pred++)
			{
				if (a[pred] == b[bpos])
				{
					reach = true;
					break;
				}
			}
			if (reach)
			{
				cout << a[pred] << ' ';
				for (int j = apos; j < pred; j++)
				{
					c.push(a[j]);
				}
				apos = ++pred;
			}
			else
			{
				while (!c.empty())
				{
					int x = c.top();
					if (x == b[bpos])
					{
						break;
					}
					else
					{
					c.pop();
					cout << x << ' ';
					}
				}
			}
		}
		while (!c.empty())
		{
			int x = c.top();
			cout << x << ' ';
			c.pop();
		}
		cout << endl;
	}
}
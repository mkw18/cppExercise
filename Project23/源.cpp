#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

const int maxn = 1e4 + 7;

int cnt = 0, first, last, ans[maxn];
bool vis[maxn], prime[maxn];

void getprime()
{
	int i, j;
	for (i = 1000; i <= maxn; i++)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0) { prime[i] = false; break; }
		if (j == i) prime[i] = true;
	}
}

int bfs()
{
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	queue<int>Q;
	int a[5], temp, temp1, now;
	Q.push(first);
	vis[first] = 1;
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if (now == last) return ans[now];
		a[0] = now / 1000;
		a[1] = (now / 100) % 10;
		a[2] = (now / 10) % 10;
		a[3] = now % 10;
		for (int i = 0; i < 4; i++)
		{
			temp = a[i];
			for (int j = 0; j < 10; j++)
			{
				if (j != temp)
				{
					a[i] = j;
					temp1 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
					if (prime[temp1] && !vis[temp1])
					{
						ans[temp1] = ans[now] + 1;
						vis[temp1] = 1;
						Q.push(temp1);
					}
					if (temp1 == last) return ans[temp1];
				}
			}
			a[i] = temp;
		}
	}
	return -1;
}

int main()
{
	getprime();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> first >> last;
		int ans = bfs();
		if (ans == -1) printf("Impossible\n");
		else cout << ans << endl;
	}
	return 0;
}
#include <iostream>
#define NL 100
#define MD 119997

using namespace std;


struct POINT {
	int x, y, num;
}P[NL];

void hashing(int k, int hash[])
{
	int key = ((P[k].x) * 1000 + P[k].y) % MD;
	if (key < 0)
		key += MD;
	hash[key] = k;
}

int searching(POINT po, int hash[])
{
	int key = ((po.x) * 1000 + po.y) % MD;
	if (key < 0)
		key += MD;
	int t = hash[key];
	if ((t >= 0) && (P[t].x == po.x) && (P[t].y == po.y))
		return t;
	return -1;
}

int main()
{
	int hash[MD];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (m <= 3)
			return 0;
		for (int j = 0; j < MD; j++)
		{
			hash[j] = -1;
		}
		for (int j = 0; j < m; j++)
		{
			cin >> P[j].x >> P[j].y;
			int k = searching(P[j], hash);
			if (k >= 0)
			{
				P[k].num++;
				j--;
				m--;
			}
			else
			{
				P[j].num = 1;
				hashing(j, hash);
			}
		}
		if (m <= 3)
			return 0;
		int sum = 0;
		int ok;
		POINT p1;
		for (int x = 0; x < m - 2; x++)
		{
			for (int y = x + 1; y < m; y++)
			{
				for (int z = y + 1; z < m; z++)
				{
					if ((P[x].x - P[y].x) * (P[x].y - P[z].y) == (P[x].y - P[y].y) * (P[x].x - P[z].x))
					{
						continue;
					}
					p1.x = -P[x].x + P[y].x + P[z].x;
					p1.y = -P[x].y + P[y].y + P[z].y;
					ok = searching(p1, hash);
					if (ok != -1)
					{
						sum += P[x].num * P[y].num * P[z].num * P[ok].num;
					}
					p1.x = P[x].x - P[y].x + P[z].x;
					p1.y = P[x].y - P[y].y + P[z].y;
					ok = searching(p1, hash);
					if (ok != -1)
					{
						sum += P[x].num * P[y].num * P[z].num * P[ok].num;
					}
					p1.x = P[x].x + P[y].x - P[z].x;
					p1.y = P[x].y + P[y].y - P[z].y;
					ok = searching(p1, hash);
					if (ok != -1)
					{
						sum += P[x].num * P[y].num * P[z].num * P[ok].num;
					}
				}
			}
		}
		sum /= 4;
		cout << sum << endl;
	}
	return 0;
}
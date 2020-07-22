#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct DATA {
	int id;
	int data;
};
//最大值优先
struct cmp1 {
	bool operator()(DATA& a, DATA& b)
	{
		return a.data < b.data;
	}
};
//最小值优先
struct cmp2 {
	bool operator()(DATA& a, DATA& b)
	{
		return a.data > b.data;
	}
};

int main()
{
	int n;
	int d;
	cin >> n >> d;
	vector<bool> isDel;
	int sum = 0;
	int delNum = 0;
	vector<priority_queue<DATA, vector<DATA>, cmp1>> b(1 << d);
	vector<priority_queue<DATA, vector<DATA>, cmp2>> c(1 << d);
	for (int i = 0; i < n; i++)
	{
		int mode;
		cin >> mode;
		isDel.push_back(false);
		if (mode == 0)
		{
			vector<int> newPoint;
			for (int j = 0; j < d; j++)
			{
				int data;
				cin >> data;
				newPoint.push_back(data);
			}
			for (int j = 0; j < (1 << d); j++)
			{
				int sum1 = 0;
				for (int k = 0; k < d; k++)
				{
					int t = j & 1 << k;
					if (t)
					{
						sum1 += newPoint[k];
					}
					else
					{
						sum1 -= newPoint[k];
					}
				}
				DATA da;
				da.data = sum1;
				da.id = sum;
				b[j].push(da);
				c[j].push(da);
			}
		}
		else if (mode == 1)
		{
			int del;
			cin >> del;
			if ((del <= sum) && (!isDel[del - 1]))
			{
				isDel[del - 1] = true;
			}
		}
		sum++;
		int dist = 0;
		for (int j = 0; j < (1 << d); j++)
		{
			while ((isDel[b[j].top().id]) && (!b[j].empty()))
				b[j].pop();
			while ((isDel[c[j].top().id]) && (!c[j].empty()))
				c[j].pop();
			int max = b[j].top().data;
			int min = c[j].top().data;
			if (dist < (max - min))
				dist = max - min;
		}
		cout << dist << endl;
	}
	return 0;
}
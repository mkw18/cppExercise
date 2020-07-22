#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[500];
bool edge[500][500];

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			edge[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int j, k;
		cin >> j >> k;
		edge[j][k] = true;
		indegree[k]++;
	}
	queue<int> Q1;
	for (int i = 0; i < N; i++)
	{
		if (indegree[i] == 0)
			Q1.push(i);
	}
	int temp;
	int num = 0;
	while (!Q1.empty())
	{
		temp = Q1.front();
		Q1.pop();
		num++;
		for (int i = 0; i < N; i++)
		{
			if (edge[temp][i])
			{
				indegree[i]--;
				if (indegree[i] == 0)
					Q1.push(i);
			}
		}
	}
	if (num != N)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < K; i++)
	{
		int V1, V2;
		cin >> V1 >> V2;
		queue<int> Q2;
		Q2.push(V1);
		int relation = 0;
		int temp1;
		while (!Q2.empty())
		{
			temp1 = Q2.front();
			Q2.pop();
			for (int j = 0; j < N; j++)
			{
				if (edge[temp1][j])
				{
					if (j == V2)
					{
						relation = 1;
						break;
					}
					Q2.push(j);
				}
			}
			if (relation == 1)
				break;
		}
		if (relation == 0)
		{
			queue<int> Q3;
			Q3.push(V2);
			int temp2;
			while (!Q3.empty())
			{
				temp2 = Q3.front();
				Q3.pop();
				for (int j = 0; j < N; j++)
				{
					if (edge[temp2][j])
					{
						if (j == V1)
						{
							relation = -1;
							break;
						}
						Q3.push(j);
					}
				}
				if (relation == -1)
					break;
			}
		}
		cout << relation << endl;
	}
	return 0;
}
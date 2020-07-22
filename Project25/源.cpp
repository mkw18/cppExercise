#include <iostream>
#include <vector>

using namespace std;

bool Route(int orign, int destination, int N, vector<vector<bool>>& edge)
{
	if (edge[orign][destination])
	{
		return true;
	}
	for (int i = 0; i < N; i++)
	{
		if ((edge[orign][i]) && (Route(i, destination, N, edge)))
		{
			return true;
		}
/*		if (edge[orign][i])
		{
			if (Route(i, destination, N, edge))
			{
				return true;
			}
		}*/
	}
	return false;
}

/*bool Route1(int orign, int search, int destination, int N, vector<vector<bool>>& edge)
{
	if (search == N)
	{
		return false;
	}
	if ((edge[orign][search]) && (edge[search][destination]))
	{
		return true;
	}
	if (!edge[orign][search] && (search < N))
	{
		if (Route1(orign, search + 1, destination, N, edge))
		{
			return true;
		}
	}
}*/

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<bool>> edge(N);
/*	for (int i = 0; i < N; i++)
	{
		edge.push_back(vector<bool>(N));
	}*/
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			edge[i].push_back(false);
//			edge[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int j, k;
		cin >> j >> k;
		edge[j][k] = true;
	}
	for (int i = 0; i < N; i++)
	{
		if (Route(i, i, N, edge))//edge矩阵第i行第j列表示是否存在从i到j的有向边，初始均为0
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int V1, V2;
		cin >> V1 >> V2;
		if (Route(V1, V2, N, edge))
		{
			cout << 1 << endl;
		}
		else if (Route(V2, V1, N, edge))
		{
			cout << -1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
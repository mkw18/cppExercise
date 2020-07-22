#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int M;
	int N;
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> N;
		vector<vector<int>> a;
		bool twl = false;
		vector<vector<bool>> step;
		for (int j = 0; j < N; j++)
		{
			a.push_back(vector<int>(N));
			step.push_back(vector<bool>(N));
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> a[j][k];
				step[j][k] = false;
			}
		}
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if ((a[i][k] != -1) && (a[k][j] != -1) && ((a[i][j] < 0) || (a[i][j] > a[i][k] + a[k][j])))
					{
						a[i][j] = a[i][k] + a[k][j];
						twl = true;
						a[i][j] = true;
					}
				}
			}
		}
		int minpath = -1;
		if (!twl)
		{
			for (int k = 0; k < N; k++)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						if ((a[i][j] > 0) && (a[j][k] > 0) && (a[k][i] > 0) && 
							((minpath == -1) || (minpath > a[i][j] + a[j][k] + a[k][i])))
						{
							minpath = a[i][j] + a[j][k] + a[k][i];
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if ((step[i][j] || step[j][i]) && (a[i][j] > 0) && (a[j][i] > 0) && 
						((minpath == -1) || (minpath > a[i][j] + a[j][i])))
					{
						minpath = a[i][j] + a[j][i];
					}
				}
			}
			for (int k = 0; k < N; k++)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						if ((!step[i][j]) && (!step[j][k]) && (!step[k][i]) && (a[i][j] > 0) 
							&& (a[j][k] > 0) && (a[k][i] > 0) && ((minpath == -1) || (minpath > a[i][j] + a[j][k] + a[k][i])))
						{
							minpath = a[i][j] + a[j][k] + a[k][i];
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			if ((a[i][i] != 0) && ((minpath == -1) || (a[i][i] < minpath)))
			{
				minpath = a[i][i];
			}
		}
		cout << minpath << endl;
	}
	return 0;
}
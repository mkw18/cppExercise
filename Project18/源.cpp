#include <iostream>

using namespace std;

int area = 0;

void expand(int row, int col, int m, int n, char** A)
{
	if ((m < 0) || (m >= row) || (n < 0) || (n >= col))
	{
		return;
	}
	else if (A[m][n] == '0')
	{
		return;
	}
	else
	{
		area++;
		A[m][n] = '0';
		expand(row, col, m - 1, n, A);
		expand(row, col, m + 1, n, A);
		expand(row, col, m, n - 1, A);
		expand(row, col, m, n + 1, A);
	}
}

int main()
{
	int row;
	int col;
	char** A;
	int max = 0;
	cin >> row >> col;
	A = new char* [row];
	for (int i = 0; i < row; i++)
	{
		A[i] = new char[col]();
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (A[i][j] == '1')
			{
				area = 0;
				expand(row, col, i, j, A);
				max = (max > area) ? max: area;
			}
		}
	}
	cout << max << endl;
	for (int i = 0; i < row; i++)
	{
		delete[]A[i];
		A[i] = NULL;
	}
	delete[]A;
	A = NULL;
	return 0;
}
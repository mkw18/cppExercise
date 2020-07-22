#include<iostream>

using namespace std;
int** Matrix(int n, int** matrix)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	return matrix;
}

int main()
{
	int n;
	cin >> n;
	int** matrix = new int*[n]();
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n]();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	Matrix(n, matrix);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	int n;
	int elem;
	cin >> m >> n >> elem;
	vector<int> vec(m * n);
	for (int i = 0; i < m * n; i++)
	{
		cin >> vec[i];
	}
	vector<int>::iterator goal = find(vec.begin(), vec.end(), elem);
	if (goal == vec.end())
	{
		cout << "-1" << endl;
	}
	else
	{
		int rank = distance(vec.begin(), goal) + 1;
		int row = rank / n + 1;
		int col = rank % n;
		if (col == 0)
		{
			row--;
			col = n;
		}
		cout << row << " " << col << endl;
	}
	return 0;
}
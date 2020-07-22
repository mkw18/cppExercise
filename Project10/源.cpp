#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	if ((n < 0) || (n > (5 * 10 ^ 5)) || (m < 0) || (m > (5 * 10 ^ 5)))
	{
		return -1;
	}
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if ((arr[i] < 0) || (arr[i] > (10 ^ 7)))
		{
			return -1;
		}
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == arr[i])
			{
				return -1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		if ((a < 0) || (a > (10 ^ 7)))
		{
			return -1;
		}
		if ((b < 0) || (b > (10 ^ 7)))
		{
			return -1;
		}
		if (a > b)
		{
			return -1;
		}
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if ((arr[j] >= a) && (arr[j] <= b))
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
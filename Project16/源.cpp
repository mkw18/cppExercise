#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		vector<int> outStack;
		for (int j = 0; j < K; j++)
		{
			int n;
			cin >> n;
			outStack.push_back(n);
		}
		int k = 1;
		int j = 0;
		vector<int> stack;
		while ((j < K) && (k <= K + 1))
		{
			if (k == outStack[j])
			{
				k++;
				j++;
			}
			else if ((stack.size() != 0) && (stack.back() == outStack[j]))
			{
				stack.pop_back();
				j++;
			}
			else
			{
				stack.push_back(k);
				k++;
			}
		}
		if (stack.size() == 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
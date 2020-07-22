#include <iostream>
#include <vector>
using namespace std;

void findPostorder(vector<int>& preorder, int low_1, int high_1, vector<int>& inorder, int low_2, int high_2, vector<int>& postorder, int low_3, int high_3) {
	if (low_1 == high_1) 
	{
		postorder[high_3] = preorder[low_1];
		return;
	}
	int i;
	for (i = low_2; i <= high_2; i++) 
	{
		if (preorder[low_1] == inorder[i]) 
		{
			break;
		}
	}
	postorder[high_3] = preorder[low_1];
	findPostorder(preorder, low_1 + 1, low_1 + i, inorder, low_2, low_2 + i - 1, postorder, low_3, low_3 + i - 1);
	findPostorder(preorder, low_1 + i + 1, high_1, inorder, low_2 + i + 1, high_2, postorder, low_3 + i, high_3 - 1);
}

int main() 
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		vector<int> preorder(M);
		vector<int> inorder(M);
		for (int j = 0; j < M; j++)
		{
			cin >> preorder[j];
		}
		for (int j = 0; j < M; j++)
		{
			cin >> inorder[j];
		}
		vector<int> postorder(M);
		findPostorder(preorder, 0, M - 1, inorder, 0, M - 1, postorder, 0, M - 1);
		for (int i = 0; i < M; i++) 
		{
			cout << postorder[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
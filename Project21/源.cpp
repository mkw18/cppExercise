#include <iostream>
#include <vector>
using namespace std;

typedef struct BinaryTree
{
	int data;
	BinaryTree* lchild;
	BinaryTree* rchild;
}BinaryTree;

int FindInOrder(vector<int>& inOrder,int begin, int end, int data)
{
	for (int i = begin; i < end; i++)
	{
		if (inOrder[i] == data)
		{
			return i;
		}
	}
	return -1;
}

BinaryTree* GetTree(vector<int>& PreOrder, int pbegin, int pend,
	vector<int>& InOrder, int ibegin, int iend)
{
	if ((pbegin >= pend) || (ibegin >= iend))
	{
		return NULL;
	}
	BinaryTree* Root = new BinaryTree;
	Root->data = PreOrder[pbegin];
	Root->lchild = NULL;
	Root->rchild = NULL;
	int r = FindInOrder(InOrder, ibegin, iend, PreOrder[pbegin]);
	Root->lchild = GetTree(PreOrder, pbegin + 1, pbegin + r - ibegin + 1, InOrder, ibegin, r);
	Root->rchild = GetTree(PreOrder, pbegin + r - ibegin + 1, pend, InOrder, r + 1, iend);
	return Root;
}

void travPost(BinaryTree* root)
{
	if (!root)
	{
		return;
	}
	travPost(root->lchild);
	travPost(root->rchild);
	cout << root->data << ' ';
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		vector<int> PreOrder(M);
		vector<int> InOrder(M);
		for (int j = 0; j < M; j++)
		{
			cin >> PreOrder[j];
		}
		for (int j = 0; j < M; j++)
		{
			cin >> InOrder[j];
		}
		BinaryTree* root = GetTree(PreOrder, 0, M, InOrder, 0, M);
		travPost(root);
		cout << endl;
	}
	return 0;
}
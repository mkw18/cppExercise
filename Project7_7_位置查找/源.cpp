#include<iostream>
using namespace std;

template<class T>
int seqSearch(const T list[], int n, const T& key)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int data1[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };
	int len = sizeof(data1)/sizeof(int);
	//cout << len << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int key;
		cin >> key;
		cout << seqSearch(data1, len, key) << endl;
	}
	return 0;
}
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	int length = (int)input.length();
	int freq[256];
	int freq1[256];
	int min = 0;
	for (int i = 0; i < 256; i++) freq[i] = 0;
	for (int i = 0; i < length; i++) freq[int(input[i]) + 128]++; //统计各个字符出现频次

	//从freq数组计算哈夫曼编码位数
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < 256; i++)
	{
		if (freq[i] != 0)
		{
			q.push(freq[i]);
		}
	}
	while (q.size() > 1)
	{
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		min += x + y;
		q.push(x + y);
	}
	cout << min;
	return 0;
}
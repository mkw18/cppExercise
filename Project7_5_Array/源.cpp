#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

template<class T>
class Array
{
private:
	T* list;
	int size;
public:
	Array(int sz = 50);
	~Array();
	T& operator[](int i);
};

template<class T>
Array<T>::Array(int sz)
{
	size = sz;
	list = new T[sz]();
}

template<class T>
Array<T>::~Array()
{
	delete[]list;
}

template<class T>
T& Array<T>::operator[](int n)
{
	assert((n >= 0) && (n < size));
	return list[n];
}

int main()
{
	int n;
	double aver = 0;
	cin >> n;
	Array<double>score(n);
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
		aver += score[i] / n;
	}
	cout << fixed << setprecision(2) << aver << endl;
	return 0;
}
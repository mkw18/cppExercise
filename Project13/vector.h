#pragma once
const int CAPACITY = 1;
typedef int Rank;
template<typename T> class Vector
{
protected:
	T* _elem;
	int _capacity;
	int _size;
	void expand();
	void shrink();

public:
	Vector(int c = CAPACITY, int s = 0, T v = 0)
	{
		_capacity = c;
		_size = s;
		_elem = new T[ _capacity ];
		for (int i = 0; i < _size; i++)
		{
			_elem[i] = v;
		}
	}
	T get(Rank n)
	{
		return _elem[n];
	}
	void set(Rank n, T v)
	{
		_elem[n] = v;
	}
	T& operator[](Rank n)
	{
		return _elem[n];
	}

	template <typename VST> void traverse(VST& visit);

	void insert(Rank k, T const& v);

	int remove(Rank lo, Rank hi);

	Rank find(T const& v, Rank lo, Rank hi) const;

	int deduplicate();
};

template <typename T>
void Vector<T>::expand()
{
	if (_capacity != _size)
	{
		return;
	}
	_capacity *= 2;
	T* old = _elem;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_elem[i] = old[i];
	}
}

template<typename T>
void Vector<T>::shrink()
{
	if (_capacity <= CAPACITY << 1)
	{
		return;
	}
	if (_size << 2 > _capacity)
	{
		return;
	}
	_capacity /= 2;
}

template <typename T>
void Vector<T>::insert(Rank k, T const& v)
{
	expand();
	for (int i = _size; i > k; i--)
	{
		_elem[i] = _elem[i - 1];
	}
	_elem[k] = v;
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
	while (hi < _size)
	{
		_elem[lo] = _elem[hi];
		lo++;
		hi++;
	}
	_size = lo;
	shrink();
	return hi- lo;
}

template<typename T>
Rank Vector<T>::find(T const& v, Rank lo, Rank hi) const
{
	while (lo < hi)
	{
		if (_elem[hi - 1] != v)
		{
			continue;
		}
		hi--;
		return hi;
	}
	return Rank();
}

template<typename T>
int Vector<T>::deduplicate()
{
	int oldsize = _size;
	Rank k = 1;
	while (k < _size)
	{
		(find(_elem[k], 0, k) < 0) ? k++ : remove(k);
	}
	return oldsize - _size;
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0; i < _size; i++)
	{

	}
}
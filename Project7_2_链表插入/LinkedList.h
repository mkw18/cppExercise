#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class LinkedList
{
private:
	Node<T>* front;
	Node<T>* rear;
	Node<T>* prevPtr;
	Node<T>* currPtr;
	int size;
	int position;

	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL);
	void freeNode(Node<T>* p);
	void copy(const LinkedList<T>& L);

public:
	LinkedList();
	LinkedList(const LinkedList<T>& L);
	~LinkedList();
	LinkedList<T>& operator=(const LinkedList<T>& L);

	int getSize() const;
	bool isEmpty() const;

	void reset(int pos = 0);
	void next();
	bool endOfList() const;
	int currentPosition(void) const;

	void insertFront(const T& item);
	void insertRear(const T& item);
	void insertAt(const T& item);
	void insertAfter(const T& item);

	T deleteFront();
	void deleteCurrent();

	T& data();
	const T& data() const;

	void clear();
};

template<class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T>* ptrNext)
{
	Node<T>* newNode = new Node<T>(item, ptrNext);
	if (newNode == NULL)
	{
		cerr << "Memory allocation failure!" << endl;
		exit(1);
	}
	return newNode;
}

template<class T>
void LinkedList<T>::freeNode(Node<T>* p)
{
	delete p;
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T>& L)
{
	if (L.size == 0)
	{
		return;
	}
	front = NewNode(L.front->data);
	rear = front;
	for (Node<T>* srcNode = L.front->nextNode(); srcNode != NULL; srcNode = srcNode->nextNode())
	{
		Node<T>* newNode = NewNode(srcNode->data);
		rear->insertAfter(newNode);
		rear = newNode;
	}
	size = L.size;
	reset(position = L.currentPosition());
}

template<class T>
LinkedList<T>::LinkedList() :front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0) {}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L) : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0)
{
	copy(L);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L)
{
	clear();
	copy(L);
	return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
	return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
	return (size == 0);
}

template<class T>
void LinkedList<T>::reset(int pos)
{
	if ((pos >= 0) && (pos <= size))
	{
		position = 0;
		prevPtr = NULL;
		currPtr = front;
		while (pos--)
		{
			next();
		}
	}
	else
	{
		position = pos;
		prevPtr = NULL;
		currPtr = NULL;
	}
}

template<class T>
void LinkedList<T>::next()
{
	prevPtr = currPtr;
	if (currPtr != NULL)
	{
		currPtr = currPtr->nextNode();
	}
	position++;
	return;
}

template<class T>
bool LinkedList<T>::endOfList() const
{
	return (currPtr == rear);
}

template<class T>
int LinkedList<T>::currentPosition(void) const
{
	return position;
}

template<class T>
void LinkedList<T>::insertFront(const T& item)
{
	front = newNode(item, front);
	if (isEmpty())
	{
		rear = front;
	}
	size++;
	position++;
	reset(position);
}

template<class T>
void LinkedList<T>::insertRear(const T& item)
{
	Node<T>* newnode = newNode(item);
	if (isEmpty())
	{
		rear = front = newnode;
	}
	else
	{
		rear->insertAfter(newnode);
		rear = newnode;
	}
	size++;
	reset(position);
}

template<class T>
void LinkedList<T>::insertAt(const T& item)
{
	if (currPtr != NULL)
	{
		Node<T>* newnode = newNode(item, currPtr);
		if (prevPtr != NULL)
		{
			prevPtr->insertAfter(newnode);
		}
		else
		{
			front = prevPtr = newnode;
		}
		size++;
		position++;
		reset(position);
	}
}

template<class T>
void LinkedList<T>::insertAfter(const T& item)
{
	if (currPtr != NULL)
	{
		Node<T>* newnode = newNode(item, currPtr->nextNode());
		currPtr->insertAfter(newnode);
		if (rear == currPtr)
		{
			rear = newnode;
		}
		size++;
	}
}

template<class T>
T LinkedList<T>::deleteFront()
{
	if (isEmpty())
	{
		cerr << "List is empty, delete error." << endl;
		exit(1);
	}
	Node<T>* temp = front;
	T item = front->data;
	front = front->nextNode();
	size--;
	if (size == 0)
	{
		rear = NULL;
	}
	position--;
	reset(position);
	freeNode(temp);
	return item;
}

template<class T>
void LinkedList<T>::deleteCurrent()
{
	if (currPtr != NULL)
	{
		if (front == currPtr)
		{
			front = currPtr->NextNode();
		}
		if (rear == currPtr)
		{
			rear = prevPtr;
		}
		if (prevPtr != NULL)
		{
			prevPtr->deleteAfter();
		}
		freeNode(currPtr);
		size--;
		reset(position);
	}
}

template<class T>
T& LinkedList<T>::data()
{
	if (currPtr == NULL)
	{
		cerr << "Current node is invalid." << endl;
		exit(1);
	}
	return currPtr->data;
}

template<class T>
const T& LinkedList<T>::data() const
{
	if (currPtr == NULL)
	{
		cerr << "Current node is invalid." << endl;
		exit(1);
	}
	return currPtr->data;
}

template<class T>
void LinkedList<T>::clear()
{
	while (!isEmpty())
	{
		deleteFront();
	}
}
#endif //LINKEDLIST_H
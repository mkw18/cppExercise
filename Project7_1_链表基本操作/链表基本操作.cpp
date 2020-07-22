#include<iostream>
#include<stdio.h>
using namespace std;

template<class T>
class Node
{
private:
	Node<T>* next;
public:
	T data;

	Node(const T& data, Node<T>* next = 0);
	void insertAfter(Node<T>* p);
	void deleteAfter();
	Node<T>* nextNode();
	const Node<T>* nextNode() const;
};

template<class T>
Node<T>::Node(const T& data, Node<T>* next) :data(data), next(next) {}

template<class T>
void Node<T>::insertAfter(Node<T>* p)
{
	p->next = next;
	next = p;
}

template<class T>
void Node<T>::deleteAfter()
{
	Node<T>* tempPtr = next;
	if (next == 0)
	{
		return;
	}
	next = tempPtr->next;
	delete tempPtr;
	return;
}

template<class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}

template<class T>
const Node<T>* Node<T>::nextNode() const
{
	return next;
}

template<class T>
void show(Node<T>* head)
{
	Node<T>* p = head;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->nextNode();
	}
	cout << endl;
	return;
}

int main()
{
	int n;
	int data1;
	int data[9];
	cin >> data1;
	Node<int>node1(data1);
	Node<int>* head = &node1;
	Node<int>* p = head;
	Node<int>* p1;
	for (int i = 0; i < 9; i++)
	{
		data[i] = 0;
		cin >> data[i];
		Node<int>*p1 = new Node<int>(data[i]);
		p->insertAfter(p1);
		p = p->nextNode();
	}
	cin >> n;
	show(head);
	while (head->data == n)
	{
		head = head->nextNode();
	}
	if (head->nextNode() == 0)
	{
		return 0;
	}
	p = head;
	p1 = p->nextNode();
	while (p->nextNode() != 0)
	{
		if (p1->data == n)
		{
			p->deleteAfter();
			p1 = p->nextNode();
		}
		else
		{
			p = p1;
			p1 = p->nextNode();
		}
	}
	show(head);
	return 0;
}
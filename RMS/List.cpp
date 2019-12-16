
#ifndef LIST_CPP
#define LIST_CPP
#include "List.h"

template <typename Data>
Node<Data>::Node(Data dataIn)
{
	data = dataIn;
	next = NULL;
}

template <typename Data>
Data Node<Data>::getData()
{
	return data;
}

template <typename Data>
List<Data>::List()
{
	start = NULL;
}

template <typename Data>
List<Data>::~List()
{
	if (!isEmpty())
	{
		Node<Data>* currentNode = start;
		Node<Data>* temp;

		while (currentNode != 0)
		{
			temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
		}
	}
}

template <typename Data>
bool List<Data>::isEmpty()
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

template <typename Data>
int List<Data>::insert(const Data& dataIn)
{
	if (isEmpty())
	{
		Node<Data>* newNode = new Node<Data>(dataIn);
		start = newNode;
	}
	else
	{

		Node<Data>* newNode = new Node<Data>(dataIn);
		newNode->next = start;
		start = newNode;
	}
}

template <typename Data>
int List<Data>::findAndRemove(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	while (temp != NULL && !(temp->data == dataIn))
	{
		temp = temp->next;
	}
	if (temp != NULL)
	{
		delete temp;
		start = start->next;
	}
}

template <typename Data>
int List<Data>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		Node<Data>* currentNode = start;
		while (currentNode != NULL) //prints until the end of the list is reached
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next; //moves to next node in list
		}
	}
}
#endif
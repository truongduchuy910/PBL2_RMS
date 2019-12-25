
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

		while (currentNode != NULL)
		{
			temp = currentNode;
			currentNode = currentNode->next;
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
		this->length++;
		return true;
	}
	else
	{
		Node<Data>* newNode = new Node<Data>(dataIn);
		newNode->next = start;
		start = newNode;
		this->length++;
		return true;
	}
	return false;
}
template <typename Data>
int List<Data>::update(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	while ((temp != NULL) && !(temp->data != dataIn)) {
		temp = temp->next;
	}
	if (temp != NULL) {
		temp->data = dataIn;
		return true;
	}
	return true;
}
template <typename Data>
int List<Data>::remove(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	if (start != NULL && (start->data == dataIn)) {
		start = start->next;
		this->length--;
		return true;

	}
	else {
		while ((temp->next != NULL) && !(temp->next->data == dataIn)) {
			temp = temp->next;
		}
		if (temp->next != NULL) {
			this->length--;
			temp->next = temp->next->next;
			return true;
		}
	}
	return true;
}

template <typename Data>
int List<Data>::out()
{
	if (isEmpty())
	{
		print(6, "The list is empty");
		print(8, "Insert values to continue, Please!");
	}
	else
	{
		Node<Data>* currentNode = start;
		while (currentNode != NULL) //prints until the end of the list is reached
		{
			if (currentNode != NULL) {
				cout << currentNode->data << endl;
			}
			currentNode = currentNode->next; //moves to next node in list
		}
	}
	return true;
}
template <typename Data>
int List<Data>::empty() {
	this->start = NULL;
	return true;
}
template <typename Data>
Data List<Data>::operator[](int i) {
	Node<Data>* temp = this->start;
	while (i && temp != NULL) {
		temp = temp->next;
		i--;
	}
	return temp->data;
};

#endif
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include "Tables.h"
using namespace std;

template <typename Data>
class List;
template <typename Data>
class Node;



template <typename Data>
class Node
{
	friend class List<Data>;

public:
	Node(Data);
	Data getData();

private:
	Data data;
	Node* next;
};

template <typename Data>
class List
{
public:
	List();
	~List();
	int insert(const Data&);
	int findAndRemove(const Data&);
	int print();

private:
	Node<Data>* start;
	bool isEmpty();
};
#endif




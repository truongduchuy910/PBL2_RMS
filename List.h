#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iomanip>
#include <string>
#include "tables.h"

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
	void insert(const Data&);
	void findAndRemove(const Data&);
	void print();

private:
	Node<Data>* start;
	bool isEmpty();
};
#endif

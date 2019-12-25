#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include "Tables.h"
#include "Print.h"
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
class List: public Print
{
public:
	int length;
	List();
	~List();
	int insert(const Data&);
	int update(const Data&);
	int remove(const Data&);
	int out();
	int empty();
	Data operator[](int);
	bool isEmpty();
private:
	Node<Data>* start;
	
};
#include "List.cpp"
#endif




#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iomanip>
#include <string>
using namespace std;

class Menu;

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
class Menu
{
public:
	int foodId;
	string name;
	double cost;
	Menu()
	{
		this->foodId = 0;
		this->cost = 0.0;
	}
	static void head()
	{
		cout << setw(6) << "foodId" << setw(6) << "name" << setw(6) << "cost" << endl;
	}
	const bool operator==(const Menu&);
	friend ostream& operator<<(ostream&, const Menu&);
	friend istream& operator>>(istream&, Menu&);
};
#endif




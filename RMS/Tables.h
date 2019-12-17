#ifndef TABLES_H
#define TABLES_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Menu
{
public:
	int foodId;
	char name[50];
	double cost;
	Menu() {
		foodId = 0;
		cost = 0.0;
		name[0] = '\0';
	}
	static void head()
	{
		cout << setw(7) << "foodId" << setw(50) << "name" << setw(7) << "cost" << endl;
	}
	const bool operator==(const Menu&);
	friend ostream& operator<<(ostream&, const Menu&);
	friend istream& operator>>(istream&, Menu&);
};
class Desk
{
public:
	int deskId;
	int available;
	Desk()
	{
		deskId = 0;
		available = false;
	}
	static void head()
	{
		cout << setw(7) << " deskId" << setw(7) << "available" << endl;
	}
	
};
class Bill
{
public:
	int billId, deskId;
	int payment;
	double total;
};
class AddFood
{
public:
	int addfoodId, foodId, quantity, deskId, billId;
};

#endif
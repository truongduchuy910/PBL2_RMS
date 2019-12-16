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
	Menu()
	{
		this->foodId = 0;
		this->cost = 0.0;
	}
	static void head()
	{
		cout << setw(7) << "foodId" << setw(50) << "name" << setw(7) << "cost" << endl;
	}
	const bool operator==(const Menu&);
	friend ostream& operator<<(ostream&, const Menu&);
	friend istream& operator>>(istream&, Menu&);
};
#endif
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
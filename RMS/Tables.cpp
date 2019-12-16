
#ifndef LIST_CPP
#define LIST_CPP
#include "Tables.h"
const bool Menu::operator==(const Menu& menu)
{
	if (this->foodId == menu.foodId)
	{
		return true;
	}
	else
	{
		return false;
	}
};

ostream& operator<<(ostream& os, const Menu& menu)
{
	os << setw(6) << menu.foodId << setw(6) << menu.name << setw(6) << menu.cost;
	return os;
}
istream& operator>>(istream& is, Menu& menu)
{
	cout << "name: ";
	is.ignore();
	getline(is, menu.name);
	cout << "cost: ";
	is >> menu.cost;
	return is;
}
#endif
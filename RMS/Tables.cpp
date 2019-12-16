
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
	os << setw(7) << menu.foodId << setw(50) << menu.name << setw(7) << menu.cost;
	return os;
}
istream& operator>>(istream& is, Menu& menu)
{
	cout << "name: ";
	is.ignore();
	is.getline(menu.name, 50);
	cout << "cost: ";
	is >> menu.cost;
	return is;
}
#endif
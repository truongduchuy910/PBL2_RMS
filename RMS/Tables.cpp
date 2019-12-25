
#ifndef LIST_CPP
#define LIST_CPP
#include "Tables.h"
const bool Menu::operator==(const Menu& menu)
{
	if (this->foodId && menu.foodId && (this->foodId == menu.foodId))
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
const bool Desk::operator==(const Desk& desk)
{
	return (this->available && desk.available);
}
ostream& operator<<(ostream& os, const Desk& desk)
{

	os << setw(7) << desk.deskId;
	if (desk.available == 1)
		os << setw(12) << "true";
	else
		os << setw(12) << "false";
	return os;
}
istream& operator>>(istream& is, Desk& desk)
{
	cout << "deskId: ";
	is.ignore();
	is >> desk.deskId;
	return is;
}
ostream& operator<<(ostream& os, const Bill& bill)
{

	os << setw(7) << bill.billId << setw(7) << bill.total;
	if (bill.payment == 1)
		os << setw(12) << "true";
	else
		os << setw(12) << "false";
	return os;
}
istream& operator>>(istream& is, Bill& bill)
{
	cout << "deskId: ";
	is.ignore();
	is >> bill.deskId;
	return is;
}
ostream& operator<<(ostream& os, const AddFood& addFood)
{
	os << setw(7) << addFood.billId << setw(7) << addFood.deskId;
	return os;
}
istream& operator>>(istream& is, AddFood& addFood)
{
	cout << "foodId: ";
	is >> addFood.foodId;
	cout << "quantity: ";
	is >> addFood.quantity;
	cout << "billId: ";
	is >> addFood.billId;
	return is;
}
#endif
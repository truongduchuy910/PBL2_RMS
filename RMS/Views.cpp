#ifndef VIEWS_CPP
#define VIEWS_CPP
#include"Views.h"
int Views::home()
{

	cout << endl
		<< "=============== HOME CONTROL" << endl;
	int n;
	do
	{
		cout << "0. exit" << endl;
		cout << "1. menu" << endl;
		cout << "2. desk" << endl;
		cout << "3. addFood" << endl;
		cout << "4. bill" << endl;
		cout << "Choose your option [0-4]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
}

int Views::menu()
{

	cout << endl
		<< "=============== MENU CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		cout << "2. add" << endl;
		cout << "3. remove" << endl;
		cout << "Choose your option [0-3]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
int Views::menuShow(List<Menu>& menus)
{
	Menu::head();
	menus.out();
	//dbMenus.print();
	//menus.print();
	return 0;
	/* for (int i = 0; i < table.menu.length; i++)
	 {
		 cout << table.menu[i];
	 }*/
}
Menu Views::menuAdd()
{
	Menu newMenu;
	cout << endl
		<< "=============== MENU ADD" << endl;
	cout << "Input values: ";
	cin >> newMenu;
	return newMenu;
}
Menu Views::menuRemove()
{
	Menu newMenu;
	cout << endl
		<< "=============== MENU REMOVE" << endl;
	cout << "Input foodId: ";
	cin >> newMenu.foodId;
	return newMenu;
}
int Views::desk()
{
	cout << endl
		<< "=============== DESK CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		cout << "2. add" << endl;
		cout << "3. remove" << endl;
		cout << "Choose your option [0-3]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
void Views::deskShow(List<Desk>& desks)
{
	Desk::head();
	desks.out();
	/*cout << endl
		<< "=============== DESK SHOW" << endl;*/

}
int Views::addFood()
{
	cout << endl
		<< "=============== order control" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "choose your option [0 or 1]: ";
		cin >> n;
	} while (n < 0 || n > 1);

	return n;
};
AddFood Views::addFoodAdd(List<Bill>& bills)
{
	cout << endl
		<< "=============== ADD FOOD" << endl;

	AddFood newAddFood;
	/*cout << "deskId: ";
	cin >> newAddFood.deskId;*/
	//views.menuShow();
	Bill::head();
	bills.out();
	cin >> newAddFood;
	return newAddFood;
}

//Desk Views::deskAdd()
//{
//    cout << endl
//        << "=============== DESK ADD" << endl;
//    Desk newDesk;
//    cin >> newDesk;
//    return newDesk;
//}
//Desk Views::deskRemove()
//{
//    Desk newDesk;
//    cin >> newDesk;
//    return newDesk;
//}
int Views::bill()
{

	cout << endl
		<< "=============== BILL CONTROL" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "2. payment" << endl;
		cout << "Choose your option [0-2]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
Bill Views::billAdd(List<Desk>& desks)
{
	cout << endl
		<< "=============== BILL ADD" << endl;
	cout << "Available Table" << endl;
	Desk::head();
	desks.out();
	Bill newBill;
	cout << "deskId:" << endl;
	cin >> newBill.deskId;
	return newBill;
}
Bill Views::billPayment(List<Bill> &bills)
{
	cout << endl
		<< "=============== BILL PAYMENT" << endl;
	Bill::head();
	bills.out();
	cout << "billId ";
	Bill temp;
	cin >> temp.billId;
	temp.payment = true;
	return temp;
}
#endif
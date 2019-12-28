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

	system("cls");
	cout << endl
		<< "=============== MENU SHOW" << endl;
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
	cout << endl
		<< "=============== MENU ADD" << endl;
	Menu newMenu;
	cout << "Input values: ";
	cin >> newMenu;
	return newMenu;
}
Menu Views::menuRemove()
{
	cout << endl
		<< "=============== MENU REMOVE" << endl;
	Menu newMenu;

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
		/*	cout << "2. add" << endl;
			cout << "3. remove" << endl;*/
		cout << "Choose your option [0-1]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
void Views::deskShow(List<Desk>& desks)
{
	system("cls");

	cout << endl
		<< "=============== DESK SHOW" << endl;

	Desk::head();
	desks.out();
	/*cout << endl
		<< "=============== DESK SHOW" << endl;*/

}
int Views::addFood()
{

	cout << endl
		<< "=============== ADD FOOD" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "2. show" << endl;
		cout << "choose your option [0-2]: ";
		cin >> n;
	} while (n < 0 || n > 2);

	return n;
};
AddFood Views::addFoodAdd(List<Bill>& bills, List<Menu>& menus)
{
	cout << endl
		<< "=============== ADD FOOD" << endl;
	AddFood newAddFood;
	Bill::head();
	bills.out();
	int deskId;
	cout << "deskId: ";
	cin >> deskId;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].deskId == deskId) {
			newAddFood.billId = bills[i].billId;
		}
	}
	Menu::head();
	menus.out();
	cout << "foodId: ";
	cin >> newAddFood.foodId;
	cout << "quantity: " << endl;
	cin >> newAddFood.quantity;
	return newAddFood;
}
int Views::addFoodShow(List<AddFood>& addFoods)
{
	system("cls");

	cout << endl
		<< "=============== ADDFOOD SHOW" << endl;
	AddFood::head();
	addFoods.out();
	return SUCCESS;

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
int Views::billAdd(List<Desk>& desks)
{
	cout << endl
		<< "=============== BILL ADD" << endl;
	cout << "Available Table" << endl;
	Desk::head();
	desks.out();
	int deskId;
	cout << "deskId: ";
	cin >> deskId;

	return deskId;
}
int Views::billPayment(List<Bill>& bills)
{
	system("cls");
	cout << endl
		<< "=============== BILL PAYMENT" << endl;
	Bill::head();
	bills.out();
	cout << "billId: ";
	int billId;
	cin >> billId;
	return billId;
}
int Views::billDetail(List<Menu>& menus, Bill& bill)
{
	system("cls");
	console
		.color(WHITE).p("=============== BILL DETAIL").hr()
		.color(PRIMARY).p("id: ").p(bill.billId).hr()
		.color(INFO).p("total: ").p(bill.total).hr();
	Menu::head();
	menus.out();
	cout << "Do you want to payment? (Y/N) ";
	char rep;
	cin >> rep;
	if (toupper(rep) == 'Y')
	{
		return true;
	}
	return false;
}
#endif
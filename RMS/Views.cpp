#ifndef VIEWS_CPP
#define VIEWS_CPP
#include"Views.h"
int Views::home()
{
	int n;
	do
	{
		cs.hr()
			.p("=============== HOME CONTROL")
			.p("0. Exit")
			.p("1. Menu")
			.p("2. Desk")
			.p("3. AddFood")
			.p("4. Bill")
			.l("Choose your option [0-4]: ");
		cin >> n;
	} while (n < 0 || n > 8);
	return n;
}

int Views::menu()
{
	int n;
	do
	{
		cs.hr()
			.p("=============== MENU CONTROL")
			.p("0. back")
			.p("1. show")
			.p("2. add")
			.p("3. remove")
			.l("Choose your option [0-3]: ");
		cin >> n;
	} while (n < 0 || n > 8);
	return n;
};
int Views::menuShow(List<Menu>& menus)
{
	cs.hr()
		.p("=============== MENU SHOW");
	Menu::head();
	menus.out();
	return 0;
}
Menu Views::menuAdd()
{
	cs.hr()
		.p("=============== MENU ADD");
	Menu newMenu;
	cin >> newMenu;
	return newMenu;
}
Menu Views::menuRemove()
{
	cs.hr()
		.p("=============== MENU REMOVE")
		.l("Input foodId: ");
	Menu newMenu;
	cin >> newMenu.foodId;
	return newMenu;
}
int Views::desk()
{
	int n;
	do
	{
		cs.hr()
			.p("=============== DESK CONTROL")
			.p("0. back")
			.p("1. show")
			.l("Choose your option [0-1]: ");
		cin >> n;
	} while (n < 0 || n > 8);
	return n;
};
void Views::deskShow(List<Desk>& desks)
{
	cs.hr()
		.p("=============== DESK SHOW");
	Desk::head();
	desks.out();
}
int Views::addFood()
{
	int n;
	do
	{
		cs.hr()
			.p("=============== ADD FOOD")
			.p("0. back")
			.p("1. add")
			.p("2. show")
			.l("choose your option [0-2]: ");
		cin >> n;
	} while (n < 0 || n > 2);

	return n;
};
AddFood Views::addFoodAdd(List<Bill>& bills, List<Menu>& menus)
{
	cs.hr()
		.p("=============== ADD FOOD");
	Bill::head();
	bills.out();
	cs.l("deskId: ");
	AddFood newAddFood;
	int deskId;
	cin >> deskId;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].deskId == deskId) {
			newAddFood.billId = bills[i].billId;
		}
	}
	Menu::head();
	menus.out();
	cs.l("foodId: ");
	cin >> newAddFood.foodId;
	cs.l("quantity: ");
	cin >> newAddFood.quantity;
	return newAddFood;
}
int Views::addFoodShow(List<AddFood>& addFoods)
{
	cs.hr()
		.p("=============== ADDFOOD SHOW");
	AddFood::head();
	addFoods.out();
	return SUCCESS;

}
int Views::bill()
{
	int n;
	do
	{
		cs.hr()
			.p("=============== BILL CONTROL")
			.p("0. back")
			.p("1. add")
			.p("2. payment")
			.l("Choose your option [0-2]: ");
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
int Views::billAdd(List<Desk>& desks)
{
	cs.hr()
		.p("=============== BILL ADD")
		.p("Available Table");
	Desk::head();
	desks.out();
	int deskId;
	cs.l("deskId: ");
	cin >> deskId;
	return deskId;
}
int Views::billPayment(List<Bill>& bills)
{
	cs.p("=============== BILL PAYMENT");
	Bill::head();
	bills.out();
	cs.l("billId: ");
	int billId;
	cin >> billId;
	return billId;
}
int Views::billDetail(List<Menu>& menus, Bill& bill)
{
	cs
		.p("=============== BILL DETAIL")
		.l("id: ").color(PRIMARY).p(bill.billId)
		.l("total: ").color(INFO).p(bill.total);
	Menu::head();
	menus.out();
	char rep;
	cs.l("Do you want to payment? (Y/N) ");
	cin >> rep;
	if (toupper(rep) == 'Y')
	{
		return true;
	}
	return false;
}
#endif
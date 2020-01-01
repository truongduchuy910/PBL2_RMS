
#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	cs.status("[MODELS] Prepare menus", models.select(menus));
	cs.status("[MODELS] Prepare desks", models.select(desks));
	cs.status("[MODELS] Prepare bills", models.select(bills));
	cs.status("[MODELS] Prepare addFoods", models.select(addFoods));
}
int Controllers::home()
{
	switch (views.home())
	{
	case 0:
		break;

	case 1:
		this->menu();
		this->home();
		break;

	case 2:
		this->desk();
		this->home();
		break;

	case 3:
		this->addFood();
		this->home();
		break;

	case 4:
		this->bill();
		this->home();
		break;

	default:
		break;

	}
	return ACCEPT;
}
int Controllers::menu()
{
	switch (views.menu())
	{
	case 0:
		break;
	case 1:
		this->menuShow();
		this->menu();
		break;
	case 2:
		this->menuAdd();
		this->menu();

		break;
	case 3:
		this->menuRemove();
		this->menu();

		break;

	default:
		break;
	}
	return ACCEPT;
}

int Controllers::menuShow()
{
	views.menuShow(menus);
	return ACCEPT;
}

int Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	cs.status("[MODELS] Insert menu", models.insert(menus, temp));
	models.select(menus);
	return ACCEPT;
}

int Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	cs.status("[MODELS] Remove menu", models.remove(menus, temp));
	models.select(menus);
	return ACCEPT;
}

int Controllers::desk()
{
	switch (views.desk())
	{
	case 0:
		break;
	case 1:
		this->deskShow();
		this->desk();
		break;
	}
	return ACCEPT;
}
int Controllers::deskShow()
{
	views.deskShow(desks);
	return ACCEPT;
}
int Controllers::addFood()
{
	switch (views.addFood())
	{
	case 0:
		break;
	case 1:
		this->addFoodAdd();
		this->addFood();
		break;
	case 2:
		this->addFoodShow();
		this->addFood();
		break;
	default:
		break;
	}
	return ACCEPT;
}
int Controllers::addFoodAdd()
{
	if (menus.isEmpty()) {
		cs
			.status("No menu to addFood!", WARNING)
			.status("Add menu to continues..", PRIMARY).wait();
		return INCORRECT;
	}
	List<Bill> availableBill;
	for (int i = 0; i < bills.length; i++)
		if (bills[i].payment == false)
			availableBill.insert(bills[i]);


	if (availableBill.isEmpty()) {
		cs
			.status("All bills have been paid! Cannot addFood", WARNING)
			.status("Add bill to continues..", PRIMARY).wait();
		return WARNING;
	}
	AddFood temp = views.addFoodAdd(availableBill, menus);
	bool haveBill = false;
	bool haveFood = false;

	for (int i = 0; i < availableBill.length; i++)
		if (temp.billId == availableBill[i].billId)
			haveBill = true;

	for (int i = 0; i < menus.length; i++)
		if (temp.foodId == menus[i].foodId)
			haveFood = true;

	if (haveBill && haveFood && temp.quantity) {
		cs.status("[VIEWS] AddFood Add", ACCEPT);
		cs.status("[MODELS] Insert addFood", models.insert(addFoods, temp));
		models.select(addFoods);
		models.select(bills);
		return ACCEPT;
	}
	cs.status("[VIEWS] AddFood Add", INCORRECT);
	return INCORRECT;
}
int Controllers::addFoodShow() {
	views.addFoodShow(addFoods);
	return ACCEPT;
}
int Controllers::bill()
{
	int billId;
	int status;
	switch (views.bill())
	{
	case 0:
		return INCORRECT;
		break;
	case 1:
		this->billAdd();
		this->bill();
		break;
	case 2:
		billId = 0;
		status = this->billPayment(billId);
		cs.status("[VIEWS] Input billId", status);
		if (status == ACCEPT)
			this->billDetail(billId);
		this->bill();
		break;
	default:
		return INCORRECT;
		break;
	}
	return ACCEPT;
}
int Controllers::billAdd()
{
	List<Desk> availableDesk;
	for (int i = 0; i < desks.length; i++)
	{
		if (desks[i].available == true)
		{
			availableDesk.insert(desks[i]);
		}
	}
	if (availableDesk.isEmpty()) {
		cs.status("No tables available!", WARNING).wait();
		return INCORRECT;
	}
	else {
		Bill temp;
		temp.deskId = views.billAdd(availableDesk);
		cs.status("[MODELS] Insert bill", models.insert(bills, temp));
		models.select(bills);
		models.select(desks);
	}
	return ACCEPT;
}
int Controllers::billPayment(int& billId)
{
	List<Bill> notPayment;
	for (int i = 0; i < bills.length; i++)
	{
		if (bills[i].payment == false)
		{
			notPayment.insert(bills[i]);
		}
	}
	if (notPayment.isEmpty()) {
		cs.status("All bills have been paid!", WARNING).wait();
	}
	else {
		billId = views.billPayment(notPayment);
		for (int i = 0; i < notPayment.length; i++)
		{
			if (notPayment[i].billId == billId)
				return ACCEPT;
		}

	}
	return INCORRECT;
}
int Controllers::billDetail(int billId)
{
	List<Menu> menuOfBill;
	//JOIN
	for (int i = 0; i < addFoods.length; i++) {
		if (addFoods[i].billId == billId) {
			for (int j = 0; j < menus.length; j++) {
				if (menus[j].foodId == addFoods[i].foodId) {
					menuOfBill.insert(menus[j]);
				}
			}
		}
	}
	Bill temp;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].billId == billId) {
			temp.total = bills[i].total;
		}
	}
	temp.billId = billId;
	temp.payment = views.billDetail(menuOfBill, temp);
	if (temp.payment == false) return INCORRECT;
	cs.status("[MODELS] Update bills", models.update(bills, temp)).wait();
	models.select(bills);
	models.select(desks);
	return ACCEPT;
}
#endif
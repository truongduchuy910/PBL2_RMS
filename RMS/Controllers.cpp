
#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	console.color(PRIMARY).p("[SQL] Prepare menus - ");
	console.status(models.select(menus)).hr();

	console.color(PRIMARY).p("[SQL] Prepare desks - ");
	console.status(models.select(desks)).hr();

	console.color(PRIMARY).p("[SQL] Prepare bills - ");
	console.status(models.select(bills)).hr();

	console.color(PRIMARY).p("[SQL] Prepare addFoods - ");
	console.status(models.select(addFoods)).hr();
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
	return SUCCESS;
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
	return SUCCESS;
}

int Controllers::menuShow()
{
	views.menuShow(menus);
	return SUCCESS;
}

int Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	models.insert(menus, temp);
	models.select(menus);
	return SUCCESS;
}

int Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	models.remove(menus, temp);
	return SUCCESS;
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
		/*case 2:
			this->deskAdd();
			break;
		case 3:
			this->deskRemove();
			break;
		default:
			break;*/
	}
	return SUCCESS;
}
int Controllers::deskShow()
{
	views.deskShow(desks);
	return SUCCESS;
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
	return SUCCESS;
}
int Controllers::addFoodAdd()
{
	if (menus.isEmpty()) {
		console
			.color(WARNING).p("No menu to addFood!").hr()
			.color(PRIMARY).p("Add menu to continues..").wait();
		return FAIL;
	}
	List<Bill> availableBill;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].payment == false) {
			availableBill.insert(bills[i]);
		}
	}
	if (availableBill.isEmpty()) {
		console
			.color(WARNING).p("All bills have been paid! Cannot addFood").hr()
			.color(PRIMARY).p("Add bill to continues..").wait();
		return FAIL;
	}
	models.insert(addFoods, views.addFoodAdd(availableBill, menus));
	models.select(addFoods);
	models.select(bills);
	return SUCCESS;
}
int Controllers::addFoodShow() {
	views.addFoodShow(addFoods);
	return SUCCESS;
}
int Controllers::bill()
{
	switch (views.bill())
	{
	case 0:
		break;
	case 1:
		this->billAdd();
		this->bill();
		break;
	case 2:
		int billId = 0;
		if (this->billPayment(billId) == SUCCESS) this->billDetail(billId);
		this->bill();
		break;
		/*default:
			break;*/
	}
	return SUCCESS;
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
		console.color(WARNING).p("No tables available!").wait();
	}
	else {
		Bill temp;
		temp.deskId = views.billAdd(availableDesk);
		models.insert(bills, temp);
		models.select(bills);
		models.select(desks);
	}
	return SUCCESS;
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
		console.color(WARNING).p("All bills have been paid!").wait();
	}
	else {
		billId = views.billPayment(notPayment);
		return SUCCESS;

	}
	return FAIL;
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
	if (temp.payment == false) return FAIL;
	console
		.color(PRIMARY).p("[UPDATE] BILL ").hr()
		.status(models.update(bills, temp)).wait();

	models.select(bills);
	models.select(desks);
	return SUCCESS;
}
#endif

#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	cout << "get data";
	models.select(menus);
	models.select(desks);
	models.select(bills);
	models.select(addFoods);
}
void Controllers::home()
{
	switch (views.home())
	{
	case 0:
		break;
	case 1:
		this->menu();
		break;
	case 2:
		this->desk();
		break;
	case 3:
		this->addFood();
		break;
	case 4:
		this->bill();
		break;
	default:
		break;
	}
}
void Controllers::menu()
{
	switch (views.menu())
	{
	case 0:
		this->home();
		break;
	case 1:
		this->menuShow();
		break;
	case 2:
		this->menuAdd();
		break;
	case 3:
		this->menuRemove();
		break;

	default:
		break;
	}
}

void Controllers::menuShow()
{
	views.menuShow(menus);
	menus.out();
	this->menu();
}

void Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	menus.insert(temp);
	models.insert(temp);
	models.select(menus);
	this->menu();
}

void Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	menus.remove(temp);
	models.remove(temp);
	this->menu();
}

void Controllers::desk()
{
	switch (views.desk())
	{
	case 0:
		this->home();
		break;
	case 1:
		this->deskShow();
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
}
void Controllers::deskShow()
{
	views.deskShow(desks);
	this->desk();
}
void Controllers::addFood()
{
	switch (views.addFood())
	{
	case 0:
		this->home();
		break;
	case 1:
		this->addFoodAdd();
		this->addFood();
		break;
	default:
		break;
	}
}
void Controllers::addFoodAdd()
{
	if (menus.isEmpty()) {
		this->menuAdd();
		this->addFoodAdd();
	}
	else {
		views.menuShow(menus);
		if (bills.isEmpty()) {
			this->billAdd();
			this->addFoodAdd();
		}
		else {

			AddFood temp = views.addFoodAdd(bills);
			addFoods.insert(temp);
			models.insert(temp);
			models.select(addFoods);
			models.select(bills);
		}
	}
}

void Controllers::bill()
{
	switch (views.bill())
	{
	case 0:
		this->home();
		break;
	case 1:
		this->billAdd();
		this->bill();
		break;
	case 2:
		this->billPayment();
		this->bill();
		break;
	default:
		break;
	}
}
void Controllers::billAdd()
{
	List<Desk> availableDesk;
	for (int i = 0; i < desks.length; i++)
	{
		if (desks[i].available == true)
		{
			availableDesk.insert(desks[i]);
		}
	}
	Bill temp;
	temp = views.billAdd(availableDesk);
	bills.insert(temp);
	models.insert(temp);
	models.select(bills);
	models.select(desks);
}
void Controllers::billPayment()
{
	List<Bill> notPayment;
	cout << bills.length << endl;
	for (int i = 0; i < bills.length; i++)
	{
		if (bills[i].payment == false)
			notPayment.insert(bills[i]);
	}
	views.billPayment(notPayment);
}
//void Controllers::deskAdd()
//{
//    Desk temp;
//    temp = views.deskAdd();
//    table.desk.insertFirst(temp);
//    this->desk();
//}
//void Controllers::deskRemove()
//{
//    Desk temp;
//    temp = views.deskRemove();
//    table.desk.findOneAndRemove(temp);
//    this->desk();
//}

#endif
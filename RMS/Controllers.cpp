
#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	console.print(PRIMARY, "[SQL] Prepare menus ");
	console.println(models.select(menus));

	console.print(PRIMARY, "[SQL] Prepare desks ");
	console.println(models.select(desks));

	console.print(PRIMARY, "[SQL] Prepare bills ");
	console.println(models.select(bills));

	console.print(PRIMARY, "[SQL] Prepare addFoods ");
	console.println(models.select(addFoods));

}
void Controllers::home()
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
}
void Controllers::menu()
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
}

void Controllers::menuShow()
{
	views.menuShow(menus);
}

void Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	menus.insert(temp);
	models.insert(temp);
	models.select(menus);
}

void Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	menus.remove(temp);
	models.remove(temp);
}

void Controllers::desk()
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
}
void Controllers::deskShow()
{
	views.deskShow(desks);
}
void Controllers::addFood()
{
	switch (views.addFood())
	{
	case 0:
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
		if (bills.isEmpty()) {
			this->billAdd();
			this->addFoodAdd();
		}
		else {
			List<Bill> availableBill;
			for (int i = 0; i < bills.length; i++) {
				if (bills[i].payment == false) {
					availableBill.insert(bills[i]);
				}
			}
			AddFood temp = views.addFoodAdd(availableBill, menus);
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
		break;
	case 1:
		this->billAdd();
		this->bill();
		break;
	case 2:
		int billId = 0;
		billId=	this->billPayment();
		this->billDetail(billId);
		this->bill();
		break;
	/*default:
		break;*/
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
	temp.deskId = views.billAdd(availableDesk);
	bills.insert(temp);
	models.insert(temp);
	models.select(bills);
	models.select(desks);
}
int Controllers::billPayment()
{
	List<Bill> notPayment;
	cout << bills.length << endl;
	for (int i = 0; i < bills.length; i++)
	{
		if (bills[i].payment == false)
		{
			notPayment.insert(bills[i]);
		}
	}
	return views.billPayment(notPayment);
	/*temp.payment = true;
	console.print(PRIMARY, "[LIST] Update BILL ");
	bills.update(temp);
	console.println(SUCCESS);
	console.print(PRIMARY, "[SQL] Update BILL ");
	console.println(models.update(temp));
	models.select(desks);*/
}
void Controllers::billDetail(int billId)
{
	Bill temp;
	temp.billId = billId;
	temp.payment = views.billDetail(addFoods);
	console.print(PRIMARY, "[LIST] Update BILL ");
	bills.update(temp);
	console.println(SUCCESS);
	console.print(PRIMARY, "[SQL] Update BILL ");
	console.println(models.update(temp));
	models.select(desks);
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
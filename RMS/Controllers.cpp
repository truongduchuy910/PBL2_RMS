
#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	cout << "get data";
	models.get(menus);
	models.get(desks);
	models.get(bills);
	models.get(addFoods);
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
	/*case 3:
		this->order();
		break;*/
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
	views.menuShow();
	menus.print();
	this->menu();
}

void Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	int id = models.insert(temp);
	if (id)
	{
		temp.foodId = id;
		menus.insert(temp);
	}
	this->menu();
}

void Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	menus.findAndRemove(temp);
	models.findAndRemove(temp);
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
//void Controllers::order()
//{
//    switch (views.order())
//    {
//    case 0:
//        this->home();
//        break;
//    case 1:
//        this->orderAdd();
//        break;
//    default:
//        break;
//    }
//}
//void Controllers::orderAdd()
//{
//	AddFood temp = views.orderAdd();
//	int id = models.insert(temp);
//	if (id)
//	{
//		temp.foodId = id;
//		menus.insert(temp);
//	}
//	this->menu();
//}
//
void Controllers::bill()
{
    switch (views.bill())
    {
    case 0:
        this->home();
        break;
    case 1:
        this->billAdd();
        break;
    case 2:
        //this->billOrder();
        break;
    case 3:
        // this->billPayment();
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
    this->bill();
}
//void Controllers::deskShow()
//{
//    views.deskShow();
//    this->desk();
//}
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
//void Controllers::orderAdd()
//{
//    Order temp;
//    temp = views.orderAdd();
//    table.order.insertFirst(temp);
//    this->order();
//}

#endif
#ifndef VIEWS_H
#define VIEWS_H
#include<iostream>
#include "List.h"
#include<ctime>
#include<cstdlib>
#include "Print.h"
class Views;
class Views : public Print
{
public:
	Print console;
	Views()
	{
		srand(time(NULL));
	}
	int home();
	int menu();
	int menuShow(List<Menu>& menus);
	Menu menuAdd();
	Menu menuRemove();

	int desk();
	/*Desk deskAdd();
	Desk deskRemove();*/
	void deskShow(List<Desk>&);
	int addFood();
	AddFood addFoodAdd(List<Bill>&, List<Menu>&);
	int bill();
	int billAdd(List<Desk>&);
	int billPayment(List<Bill>&);
	int billDetail(List<AddFood>&);
};
//Views views;
#endif

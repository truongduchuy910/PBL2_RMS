
#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include<iostream>
#include "Tables.h"
#include"List.h"
#include"Views.h"
#include"Models.h"
#include "Print.h"
using namespace std;
class Controllers
{
public:
	List<Menu> menus;
	List<Desk> desks;
	List<Bill> bills;
	List<AddFood> addFoods;
	Views views;
	Models models;
	Print console;
	void init();
	int home();
	int menu();
	int menuShow();
	int menuAdd();
	int menuRemove();
	int deskShow();
	int desk();
	int addFood();
	int addFoodAdd();
	int addFoodShow();
	int bill();
	int billAdd();
	int billPayment(int&);
	int billDetail(int);
};
#endif
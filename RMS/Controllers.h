
#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include<iostream>
#include "Tables.h"
#include"List.h"
#include"Views.h"
#include"Models.h"
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
	void init();
	void home();
	void menu();
	void menuShow();
	void menuAdd();
	void menuRemove();
	void deskShow();
	void deskAdd();
	void deskRemove();
	void desk();
	void addFood();
	void addFoodAdd();
	void bill();
	void billShow();
	void billAdd();
	void billPayment();
};
#endif
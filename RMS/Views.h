#ifndef VIEWS_H
#define VIEWS_H
#include<iostream>
#include "List.h"
class Views;
class Views
{
public:
    int home();
    int menu();
    int menuShow(List<Menu>&);
    Menu menuAdd();
    Menu menuRemove();
	/*
    int desk();
    Desk deskAdd();
    Desk deskRemove();
    int deskShow();
    int order();
    Order orderAdd();
    int bill();
    Bill billAdd();
    int billShow();*/
};
//Views views;
#endif

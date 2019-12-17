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
    int menuShow();
    Menu menuAdd();
    Menu menuRemove();
	
    int desk();
    /*Desk deskAdd();
    Desk deskRemove();*/
    void deskShow(List<Desk>&);
    /*int order();
    AddFood orderAdd();*/
    int bill();
    Bill billAdd(List<Desk>&);
    void billShow();
};
//Views views;
#endif

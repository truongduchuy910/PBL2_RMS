#ifndef VIEWS_H
#define VIEWS_H
#include<iostream>
#include "List.h"
#include<ctime>
#include<cstdlib>

class Views;
class Views
{
public:
    Views()
    {
        srand(time(NULL));
    }
    int home();
    int menu();
    int menuShow(List<Menu> &menus);
    Menu menuAdd();
    Menu menuRemove();

    int desk();
    /*Desk deskAdd();
    Desk deskRemove();*/
    void deskShow(List<Desk>&);
    int addFood();
    AddFood addFoodAdd( List<Bill>&);
    int bill();
    Bill billAdd(List<Desk>&);
    Bill billPayment(List<Bill>& bills);
};
//Views views;
#endif

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
    int menuShow();
    Menu menuAdd();
    Menu menuRemove();

    int desk();
    /*Desk deskAdd();
    Desk deskRemove();*/
    void deskShow(List<Desk>&);
    int addFood();
    AddFood addFoodAdd();
    int bill();
    Bill billAdd(List<Desk>&);
    void billShow();
};
//Views views;
#endif

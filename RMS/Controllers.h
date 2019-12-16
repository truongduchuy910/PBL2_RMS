
#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include<iostream>
#include"List.h"
#include"Tables.h"
#include"Views.h"
using namespace std;

class Controllers;
class Controllers
{
public:
    class
    {
        List<Menu> menus;
    }db;
    Views views;
    void home();
    void menu();
    void menuShow();
    void menuAdd();
    void menuRemove();
    //void deskShow();
    //void deskAdd();
    //void deskRemove();
    //void desk();
    //void order();
    //void orderAdd();
    //void bill();
    //void billShow();
    //void billOrder();
    //void billPayment();
};
#endif
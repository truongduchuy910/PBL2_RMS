
#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include"Views.h"
class Controllers;
class Controllers
{
public:
    void home();
    void menu();
    void menuShow();
    void menuAdd();
    void menuRemove();
    void deskShow();
    void deskAdd();
    void deskRemove();
    void desk();
    void order();
    void orderAdd();
    void bill();
    //void billShow();
    void billAdd();
    //void billOrder();
   // void billPayment();
};
extern Controllers controllers;
#endif
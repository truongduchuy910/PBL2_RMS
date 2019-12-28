//#include <iostream>
//#include "Models.h"
//#include "Tables.h"
//#include "List.h"
//#include"Controllers.h"
//
//using namespace std;
//Controllers controllers;
//int main()
//{
//	controllers.init();
//	controllers.home();
//	return 0;
//}
#define SUCCESS 2
#define INFO 3
#define DANGER 4
#define FAIL 4
#define WARNING 6
#define PRIMARY 8
#define LIGHT 7
#define WHITE 15
#ifndef MODELS_H
#define MODELS_H
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <string>
#include <cstring>
#include <time.h>
#include <cstdlib>
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
using namespace std;

template <typename Data>
class List;
template <typename Data>
class Node;

class Models;
class Controlles;
class Views;
class Print;
class Menu;
class Desk;
class AddFood;
class Bill;
class Models {
public:
	Models();

	int insert(List<Menu>&, const Menu&);
	int update(List<Menu>&, const Menu&);
	int remove(List<Menu>&, const Menu&);
	int select(List<Menu>&);

	int insert(List<Desk>&, const Desk&);
	int remove(List<Desk>&, const Desk&);
	int select(List<Desk>&);

	int insert(List<Bill>&, const Bill&);
	int update(List<Bill>&, const Bill&);
	int select(List<Bill>&);

	int insert(List<AddFood>&, const AddFood&);
	int select(List<AddFood>&);
protected:

	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	string parentheses(const string);
	string apostrophe(const double);
	string apostrophe(const int);
	string apostrophe(const string);
	string apostrophe(const char[]);
	string plus = ",";
	wstring s2ws(const string& s);
};
#endif // !MODEL_H
#ifndef TABLES_H
#define TABLES_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Menu
{
public:
	int foodId;
	char name[50];
	double cost;
	Menu() {
		foodId = 0;
		cost = 0.0;
		name[0] = '\0';
	}
	static void head()
	{
		cout << setw(7) << "foodId" << setw(50) << "name" << setw(7) << "cost" << endl;
	}
	const bool operator==(const Menu&);
	friend ostream& operator<<(ostream&, const Menu&);
	friend istream& operator>>(istream&, Menu&);
};
class Desk
{
public:
	int deskId;
	int available;
	Desk()
	{
		deskId = 0;
		available = false;
	}
	static void head()
	{
		cout << setw(7) << " deskId" << setw(12) << "available" << endl;
	}
	const bool operator==(const Desk&);
	friend ostream& operator<<(ostream&, const Desk&);
	friend istream& operator>>(istream&, Desk&);
};
class Bill
{
public:
	int billId, deskId;
	int payment;
	double total;
	Bill()
	{
		billId = 0;
		total = 0;
		payment = 0;
		deskId = 0;
	}
	static void head()
	{
		cout << setw(7) << "billId" << setw(7) << "deskId" << setw(7) << "total" << setw(12) << "payment" << endl;
	}
	friend ostream& operator<<(ostream&, const Bill&);
	friend istream& operator>>(istream&, Bill&);
	bool operator==(const Bill&);
};
class AddFood
{
public:
	AddFood()
	{
		addfoodId = 0;
	}
	static void head()
	{
		cout << setw(7) << " billId" << setw(7) << "foodId" << endl;
	}
	int addfoodId, foodId, quantity, deskId, billId;
	friend ostream& operator<<(ostream&, const AddFood&);
	friend istream& operator>>(istream&, AddFood&);
	bool operator==(const AddFood&);

};

#endif
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
using namespace std;

template <typename Data>
class Node
{
	friend class List<Data>;

public:
	Node(Data);
	Data getData();

private:
	Data data;
	Node* next;
};

template <typename Data>
class List
{
public:
	int length;
	Print cs;
	List();
	~List();
	int insert(const Data&);
	int update(const Data&);
	int remove(const Data&);
	int out();
	int empty();
	Data& operator[](int);
	bool isEmpty();
private:
	Node<Data>* start;

};
template <typename Data>
Node<Data>::Node(Data dataIn)
{
	data = dataIn;
	next = NULL;
}

template <typename Data>
Data Node<Data>::getData()
{
	return data;
}

template <typename Data>
List<Data>::List()
{
	start = NULL;
}

template <typename Data>
List<Data>::~List()
{
	if (!isEmpty())
	{
		Node<Data>* currentNode = start;
		Node<Data>* temp;

		while (currentNode != NULL)
		{
			temp = currentNode;
			currentNode = currentNode->next;
		}
	}
}

template <typename Data>
bool List<Data>::isEmpty()
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

template <typename Data>
int List<Data>::insert(const Data& dataIn)
{
	if (isEmpty())
	{
		Node<Data>* newNode = new Node<Data>(dataIn);
		start = newNode;
		this->length++;
		return true;
	}
	else
	{
		Node<Data>* newNode = new Node<Data>(dataIn);
		newNode->next = start;
		start = newNode;
		this->length++;
		return true;
	}
	return false;
}
template <typename Data>
int List<Data>::update(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	while ((temp != NULL) && !(temp->data == dataIn)) {
		temp = temp->next;
	}
	if (temp != NULL) {
		temp->data = dataIn;
		return true;
	}
	return true;
}
template <typename Data>
int List<Data>::remove(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	if (start != NULL && (start->data == dataIn)) {
		start = start->next;
		this->length--;
		return true;

	}
	else {
		while ((temp->next != NULL) && !(temp->next->data == dataIn)) {
			temp = temp->next;
		}
		if (temp->next != NULL) {
			this->length--;
			temp->next = temp->next->next;
			return true;
		}
	}
	return true;
}

template <typename Data>
int List<Data>::out()
{
	if (isEmpty())
	{
		cs.color(WARNING).p("The list is empty").hr().color(WHITE);
		cs.color(LIGHT).p("Insert values to continue, Please!").hr().color(WHITE);

	}
	else
	{
		Node<Data>* currentNode = start;
		while (currentNode != NULL) //prints until the end of the list is reached
		{
			if (currentNode != NULL) {
				cout << currentNode->data << endl;
			}
			currentNode = currentNode->next; //moves to next node in list
		}
	}
	return true;
}
template <typename Data>
int List<Data>::empty() {
	this->start = NULL;
	this->length = 0;
	return true;
}
template <typename Data>
Data& List<Data>::operator[](int i) {
	Node<Data>* temp = this->start;
	while (i && temp != NULL) {
		temp = temp->next;
		i--;
	}
	if (temp != NULL) {
		return temp->data;
	}
	else {
		return this->start->data;
	}
};

#endif


#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include<iostream>
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


#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include"Controllers.h"
void Controllers::init() {
	console.color(PRIMARY).p("[SQL] Prepare menus - ");
	console.status(models.select(menus)).hr();

	console.color(PRIMARY).p("[SQL] Prepare desks - ");
	console.status(models.select(desks)).hr();

	console.color(PRIMARY).p("[SQL] Prepare bills - ");
	console.status(models.select(bills)).hr();

	console.color(PRIMARY).p("[SQL] Prepare addFoods - ");
	console.status(models.select(addFoods)).hr();
}
int Controllers::home()
{
	switch (views.home())
	{
	case 0:
		break;
	case 1:
		this->menu();
		this->home();
		break;
	case 2:
		this->desk();
		this->home();

		break;
	case 3:
		this->addFood();
		this->home();

		break;
	case 4:
		this->bill();
		this->home();

		break;
	default:
		break;
	}
	return SUCCESS;
}
int Controllers::menu()
{
	switch (views.menu())
	{
	case 0:
		break;
	case 1:
		this->menuShow();
		this->menu();
		break;
	case 2:
		this->menuAdd();
		this->menu();

		break;
	case 3:
		this->menuRemove();
		this->menu();

		break;

	default:
		break;
	}
	return SUCCESS;
}

int Controllers::menuShow()
{
	views.menuShow(menus);
	return SUCCESS;
}

int Controllers::menuAdd()
{
	Menu temp = views.menuAdd();
	models.insert(menus, temp);
	models.select(menus);
	return SUCCESS;
}

int Controllers::menuRemove()
{
	Menu temp = views.menuRemove();
	models.remove(menus, temp);
	return SUCCESS;
}

int Controllers::desk()
{
	switch (views.desk())
	{
	case 0:
		break;
	case 1:
		this->deskShow();
		this->desk();
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
	return SUCCESS;
}
int Controllers::deskShow()
{
	views.deskShow(desks);
	return SUCCESS;
}
int Controllers::addFood()
{
	switch (views.addFood())
	{
	case 0:
		break;
	case 1:
		this->addFoodAdd();
		this->addFood();
		break;
	case 2:
		this->addFoodShow();
		this->addFood();
		break;
	default:
		break;
	}
	return SUCCESS;
}
int Controllers::addFoodAdd()
{
	if (menus.isEmpty()) {
		console
			.color(WARNING).p("No menu to addFood!").hr()
			.color(PRIMARY).p("Add menu to continues..").wait();
		return FAIL;
	}
	List<Bill> availableBill;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].payment == false) {
			availableBill.insert(bills[i]);
		}
	}
	if (availableBill.isEmpty()) {
		console
			.color(WARNING).p("All bills have been paid! Cannot addFood").hr()
			.color(PRIMARY).p("Add bill to continues..").wait();
		return FAIL;
	}
	models.insert(addFoods, views.addFoodAdd(availableBill, menus));
	models.select(addFoods);
	models.select(bills);
	return SUCCESS;
}
int Controllers::addFoodShow() {
	views.addFoodShow(addFoods);
	return SUCCESS;
}
int Controllers::bill()
{
	switch (views.bill())
	{
	case 0:
		break;
	case 1:
		this->billAdd();
		this->bill();
		break;
	case 2:
		int billId = 0;
		if (this->billPayment(billId) == SUCCESS) this->billDetail(billId);
		this->bill();
		break;
		/*default:
			break;*/
	}
	return SUCCESS;
}
int Controllers::billAdd()
{
	List<Desk> availableDesk;
	for (int i = 0; i < desks.length; i++)
	{
		if (desks[i].available == true)
		{
			availableDesk.insert(desks[i]);
		}
	}
	if (availableDesk.isEmpty()) {
		console.color(WARNING).p("No tables available!").wait();
	}
	else {
		Bill temp;
		temp.deskId = views.billAdd(availableDesk);
		models.insert(bills, temp);
		models.select(bills);
		models.select(desks);
	}
	return SUCCESS;
}
int Controllers::billPayment(int& billId)
{
	List<Bill> notPayment;
	for (int i = 0; i < bills.length; i++)
	{
		if (bills[i].payment == false)
		{
			notPayment.insert(bills[i]);
		}
	}
	if (notPayment.isEmpty()) {
		console.color(WARNING).p("All bills have been paid!").wait();
	}
	else {
		billId = views.billPayment(notPayment);
		return SUCCESS;

	}
	return FAIL;
}
int Controllers::billDetail(int billId)
{
	List<Menu> menuOfBill;
	//JOIN
	for (int i = 0; i < addFoods.length; i++) {
		if (addFoods[i].billId == billId) {
			for (int j = 0; j < menus.length; j++) {
				if (menus[j].foodId == addFoods[i].foodId) {
					menuOfBill.insert(menus[j]);
				}
			}
		}
	}
	Bill temp;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].billId == billId) {
			temp.total = bills[i].total;
		}
	}
	temp.billId = billId;
	temp.payment = views.billDetail(menuOfBill, temp);
	if (temp.payment == false) return FAIL;
	console
		.color(PRIMARY).p("[UPDATE] BILL ").hr()
		.status(models.update(bills, temp)).wait();

	models.select(bills);
	models.select(desks);
	return SUCCESS;
}
#endif


#ifndef MODELS_CPP
#define MODELS_CPP
//MODELS STATUS DEFINE

Models::Models() {
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
	}
	if (SQL_SUCCESS == SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
	}
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
	}
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost;DATABASE=qlNhaHang;Trusted=true;UID=sa;PWD=truongduc910",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT))
	{
	case SQL_SUCCESS:
		break;
	case SQL_SUCCESS_WITH_INFO:
		break;
	default:
		break;
	}
}

//MENU
int Models::insert(List<Menu>& menus, const Menu& menu) {
	menus.insert(menu);
	wstring stemp = s2ws(
		"INSERT INTO MENU (FoodName, Cost) VALUES" +
		parentheses(
			apostrophe(menu.name) + plus +
			apostrophe(menu.cost)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		return SUCCESS;
	}
	else {
		return FAIL;
	};
	return SUCCESS;
};

int Models::update(List<Menu>& menus, const Menu& menu) {
	menus.update(menu);
	wstring stemp = s2ws(
		"UPDATE MENU SET Cost = " +
		apostrophe(menu.cost) + plus +
		"FoodName = " + apostrophe(menu.name) +
		"WHERE FoodID = " + apostrophe(menu.foodId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		return SUCCESS;
	}
	else {
		return FAIL;
	};	return SUCCESS;
};
int Models::remove(List<Menu>& menus, const Menu& menu) {
	menus.remove(menu);
	wstring stemp = s2ws(
		"DELETE FROM MENU WHERE FoodID = " + apostrophe(menu.foodId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		return SUCCESS;
	}
	else {
		return FAIL;
	};
	return SUCCESS;
};



int Models::select(List<Menu>& menus) {

	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
		Menu temp;
		menus.empty();
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
			menus.insert(temp);
		}
	}
	else {
		return FAIL;
	}
	return SUCCESS;
}


int Models::insert(List<Desk>& desks, const Desk& desk) {
	desks.insert(desk);
	wstring stemp = s2ws(
		"INSERT INTO DESK (DeskID) VALUES" +
		parentheses(
			apostrophe(desk.deskId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
	}
	else {
		return FAIL;
	};
	return SUCCESS;
};

int Models::remove(List<Desk>& desks, const Desk& desk) {
	desks.remove(desk);
	wstring stemp = s2ws(
		"DELETE FROM DESK WHERE DeskID  = " + apostrophe(desk.deskId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
	}
	else {
		return FAIL;
	};
	return SUCCESS;
};

int Models::select(List<Desk>& desks) {
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM DESK", SQL_NTS)) {
		Desk temp;
		desks.empty();
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.available, SQL_RESULT_LEN, &ptrSqlVersion);
			desks.insert(temp);
		}
	}
	else {
		return FAIL;
	}
	return SUCCESS;
}

//BILL
int Models::insert(List<Bill>& bills, const Bill& bill) {
	bills.insert(bill);
	wstring stemp = s2ws(
		"INSERT INTO BILL (DeskID) VALUES" +
		parentheses(
			apostrophe(bill.deskId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
	}
	else {
		return FAIL;
	};
	return SUCCESS;

}

int Models::update(List<Bill>& bills, const Bill& bill) {
	bills.update(bill);
	wstring stemp = s2ws(
		"UPDATE BILL SET Payment = " +
		apostrophe(bill.payment)
		+
		"WHERE BillID = " +
		apostrophe(bill.billId)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
	}
	else {
		return FAIL;
	};
	return SUCCESS;

}

int Models::select(List<Bill>& bills) {
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM BILL", SQL_NTS)) {
		Bill temp;
		bills.empty();
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.billId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &temp.payment, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_DOUBLE, &temp.total, SQL_RESULT_LEN, &ptrSqlVersion);
			bills.insert(temp);
		}
	}
	else {
		return FAIL;
	}
	return SUCCESS;
}

//ADDFOOD

int Models::insert(List<AddFood>& addFoods, const AddFood& addFood) {
	addFoods.insert(addFood);
	wstring stemp = s2ws(
		"INSERT INTO ADDFOOD (FoodID, Quantity,BillID) VALUES" +
		parentheses(
			apostrophe(addFood.foodId) + plus +
			apostrophe(addFood.quantity) + plus +
			apostrophe(addFood.billId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
	}
	else {
		return FAIL;
	};
	return SUCCESS;

}

int Models::select(List<AddFood>& addFoods) {
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT FoodID,Quantity,BillID FROM ADDFOOD", SQL_NTS)) {
		AddFood temp;
		addFoods.empty();
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			/*SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.addfoodId, SQL_RESULT_LEN, &ptrSqlVersion);*/
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.quantity, SQL_RESULT_LEN, &ptrSqlVersion);
			/*SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);*/
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &temp.billId, SQL_RESULT_LEN, &ptrSqlVersion);
			addFoods.insert(temp);
		}
	}
	else {
		return FAIL;
	}
	return SUCCESS;
}
string Models::parentheses(const string s) {
	return (" (" + s + ") ");
}
string Models::apostrophe(const double s) {
	return (" '" + to_string(s) + "' ");
};
string Models::apostrophe(const int s) {
	return (" '" + to_string(s) + "' ");
};
string Models::apostrophe(const string s) {
	return (" '" + s + "' ");
};
string Models::apostrophe(const char s[]) {
	return (" '" + string(s) + "' ");
};
wstring Models::s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wstring r(buf);
	delete[] buf;
	return r;
}
#endif
#pragma once
#pragma once
#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <cstring>
#include "Tables.h"
using namespace std;
class Print {
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Print& color(const int);
	Print& hr();
	template <typename OutData>
	Print& p(const OutData s) {
		cout << s;
		color(WHITE);
		return *this;
	};
	template <typename OutData>
	Print& alert(const OutData s) {
		CONSOLE_SELECTION_INFO selectionInf;
		GetConsoleSelectionInfo(&selectionInf);
		move(0, 0);
		cout << s;
		color(WHITE);
		move(selectionInf.dwSelectionAnchor.X, selectionInf.dwSelectionAnchor.Y);
		return *this;
	};
	void move(const int, const int);
	Print& status(int);
	Print& wait();
};
#endif
#ifndef PRINT_CPP
#define PRINT_CPP
Print& Print::color(const int color) {
	SetConsoleTextAttribute(hConsole, color);
	return *this;
}

Print& Print::hr() {
	cout << endl;
	return *this;
}

void Print::move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Print& Print::status(int status) {
	color(status);
	switch (status) {
	case SUCCESS:
		p("Success");
		break;
	case FAIL:
		p("Fail");
		break;
	case WARNING:
		p("Warning");
		break;
	}
	return *this;
}
Print& Print::wait() {
	color(PRIMARY);
	cout << endl;
	system("pause");
	color(WHITE);
	return *this;
}
#endif

#ifndef LIST_CPP
#define LIST_CPP
const bool Menu::operator==(const Menu& menu)
{
	if (this->foodId && menu.foodId && (this->foodId == menu.foodId))
	{
		return true;
	}
	else
	{
		return false;
	}
};

ostream& operator<<(ostream& os, const Menu& menu)
{
	os << setw(7) << menu.foodId << setw(50) << menu.name << setw(7) << menu.cost;
	return os;
}
istream& operator>>(istream& is, Menu& menu)
{
	cout << "name: ";
	is.ignore();
	is.getline(menu.name, 50);
	cout << "cost: ";
	is >> menu.cost;
	return is;
}
const bool Desk::operator==(const Desk& desk)
{
	return (this->available && desk.available);
}
ostream& operator<<(ostream& os, const Desk& desk)
{

	os << setw(7) << desk.deskId;
	if (desk.available == 1)
		os << setw(12) << "true";
	else
		os << setw(12) << "false";
	return os;
}
istream& operator>>(istream& is, Desk& desk)
{
	cout << "deskId: ";
	is >> desk.deskId;
	return is;
}
ostream& operator<<(ostream& os, const Bill& bill)
{

	os << setw(7) << bill.billId << setw(7) << bill.deskId << setw(7) << bill.total;
	if (bill.payment == 1)
		os << setw(12) << "true";
	else
		os << setw(12) << "false";
	return os;
}
istream& operator>>(istream& is, Bill& bill)
{
	cout << "deskId: ";
	is >> bill.deskId;
	return is;
}

bool Bill::operator==(const Bill& content) {

	return (this->billId == content.billId);
}
ostream& operator<<(ostream& os, const AddFood& addFood)
{
	os << setw(7) << addFood.billId << setw(7) << addFood.foodId;
	return os;
}
istream& operator>>(istream& is, AddFood& addFood)
{
	cout << "foodId: ";
	is >> addFood.foodId;
	cout << "quantity: ";
	is >> addFood.quantity;
	return is;
}
bool AddFood::operator==(const AddFood& content) {

	return (this->billId == content.billId);
}
#endif
#ifndef VIEWS_CPP
#define VIEWS_CPP
#include"Views.h"
int Views::home()
{
	cout << endl
		<< "=============== HOME CONTROL" << endl;
	int n;
	do
	{
		cout << "0. exit" << endl;
		cout << "1. menu" << endl;
		cout << "2. desk" << endl;
		cout << "3. addFood" << endl;
		cout << "4. bill" << endl;
		cout << "Choose your option [0-4]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
}

int Views::menu()
{
	cout << endl
		<< "=============== MENU CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		cout << "2. add" << endl;
		cout << "3. remove" << endl;
		cout << "Choose your option [0-3]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
int Views::menuShow(List<Menu>& menus)
{

	system("cls");
	cout << endl
		<< "=============== MENU SHOW" << endl;
	Menu::head();
	menus.out();
	//dbMenus.print();
	//menus.print();
	return 0;
	/* for (int i = 0; i < table.menu.length; i++)
	 {
		 cout << table.menu[i];
	 }*/
}
Menu Views::menuAdd()
{
	cout << endl
		<< "=============== MENU ADD" << endl;
	Menu newMenu;
	cout << "Input values: ";
	cin >> newMenu;
	return newMenu;
}
Menu Views::menuRemove()
{
	cout << endl
		<< "=============== MENU REMOVE" << endl;
	Menu newMenu;

	cout << "Input foodId: ";
	cin >> newMenu.foodId;
	return newMenu;
}
int Views::desk()
{

	cout << endl
		<< "=============== DESK CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		/*	cout << "2. add" << endl;
			cout << "3. remove" << endl;*/
		cout << "Choose your option [0-1]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
void Views::deskShow(List<Desk>& desks)
{
	system("cls");

	cout << endl
		<< "=============== DESK SHOW" << endl;

	Desk::head();
	desks.out();
	/*cout << endl
		<< "=============== DESK SHOW" << endl;*/

}
int Views::addFood()
{

	cout << endl
		<< "=============== ADD FOOD" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "2. show" << endl;
		cout << "choose your option [0-2]: ";
		cin >> n;
	} while (n < 0 || n > 2);

	return n;
};
AddFood Views::addFoodAdd(List<Bill>& bills, List<Menu>& menus)
{
	cout << endl
		<< "=============== ADD FOOD" << endl;
	AddFood newAddFood;
	Bill::head();
	bills.out();
	int deskId;
	cout << "deskId: ";
	cin >> deskId;
	for (int i = 0; i < bills.length; i++) {
		if (bills[i].deskId == deskId) {
			newAddFood.billId = bills[i].billId;
		}
	}
	Menu::head();
	menus.out();
	cout << "foodId: ";
	cin >> newAddFood.foodId;
	cout << "quantity: " << endl;
	cin >> newAddFood.quantity;
	return newAddFood;
}
int Views::addFoodShow(List<AddFood>& addFoods)
{
	system("cls");

	cout << endl
		<< "=============== ADDFOOD SHOW" << endl;
	AddFood::head();
	addFoods.out();
	return SUCCESS;

}
//Desk Views::deskAdd()
//{
//    cout << endl
//        << "=============== DESK ADD" << endl;
//    Desk newDesk;
//    cin >> newDesk;
//    return newDesk;
//}
//Desk Views::deskRemove()
//{
//    Desk newDesk;
//    cin >> newDesk;
//    return newDesk;
//}
int Views::bill()
{
	cout << endl
		<< "=============== BILL CONTROL" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "2. payment" << endl;
		cout << "Choose your option [0-2]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
int Views::billAdd(List<Desk>& desks)
{
	cout << endl
		<< "=============== BILL ADD" << endl;
	cout << "Available Table" << endl;
	Desk::head();
	desks.out();
	int deskId;
	cout << "deskId: ";
	cin >> deskId;

	return deskId;
}
int Views::billPayment(List<Bill>& bills)
{
	system("cls");
	cout << endl
		<< "=============== BILL PAYMENT" << endl;
	Bill::head();
	bills.out();
	cout << "billId: ";
	int billId;
	cin >> billId;
	return billId;
}
int Views::billDetail(List<Menu>& menus, Bill& bill)
{
	system("cls");
	console
		.color(WHITE).p("=============== BILL DETAIL").hr()
		.color(PRIMARY).p("id: ").p(bill.billId).hr()
		.color(INFO).p("total: ").p(bill.total).hr();
	Menu::head();
	menus.out();
	cout << "Do you want to payment? (Y/N) ";
	char rep;
	cin >> rep;
	if (toupper(rep) == 'Y')
	{
		return true;
	}
	return false;
}
#endif

using namespace std;
Controllers controllers;
int main()
{
	controllers.init();
	controllers.home();
	return 0;
}
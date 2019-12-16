
#ifndef LIST_CPP
#define LIST_CPP
#include "List.h"
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

		while (currentNode != 0)
		{
			temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
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
	}
	else
	{

		Node<Data>* newNode = new Node<Data>(dataIn);
		newNode->next = start;
		start = newNode;
	}
}

template <typename Data>
int List<Data>::findAndRemove(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	while (temp != NULL && !(temp->data == dataIn))
	{
		temp = temp->next;
	}
	if (temp != NULL)
	{
		delete temp;
		start = start->next;
	}
}

template <typename Data>
int List<Data>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		Node<Data>* currentNode = start;
		while (currentNode != NULL) //prints until the end of the list is reached
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next; //moves to next node in list
		}
	}
}
//
//int Models::getData(List<Menu>& menus) {
//	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
//	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
//		SQLCHAR sqlVersion[SQL_RESULT_LEN];
//		SQLINTEGER ptrSqlVersion;
//		Menu temp;
//		cout << "Quering..." << endl;
//		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
//			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.name, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
//			menus.insert(temp);
//		}
//		cout << "Quering done!" << endl;
//	}
//	else {
//		cout << "fail" << endl;
//	}
//}
////int Models::menuAdd(const Menu& menu) {
////	string command = "INSERT INTO MENU (FoodName, Cost) VALUES('";
////	command += string(menu.name) + AND + to_string(menu.cost);
////	command += "')";
////	std::wstring stemp = s2ws(command);
////	LPCWSTR result = stemp.c_str();
////	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
////	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
////	case SQL_SUCCESS:
////		cout << "[INSERT] Successful!" << endl;
////		break;
////	case SQL_SUCCESS_WITH_INFO:
////		cout << "[INSERT] Successful!" << endl;
////		break;
////	default:
////		cout << "[INSERT] Fail!" << endl;
////		break;
////	}
////}
////int Models::menuRemove(const int& foodId) {
////	string command = "DELETE FROM MENU WHERE FoodId = '" + to_string(foodId) + s;
////	cout << command << endl;
////	std::wstring stemp = s2ws(command);
////	LPCWSTR result = stemp.c_str();
////	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
////	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
////	case SQL_SUCCESS:
////		cout << "[DELETE] Successful!" << endl;
////		break;
////	case SQL_SUCCESS_WITH_INFO:
////		cout << "[DELETE] Successful!" << endl;
////		break;
////	default:
////		cout << "[DELETE] Fail!" << endl;
////		break;
////	}
////}
////int Models::menuUpdate(const Menu& menu) {
////	string command = "UPDATE MENU SET FoodName = '";
////	command += string(menu.foodName) + s;
////	command += ", Cost = '";
////	command += to_string(menu.cost) + s;
////	command += " WHERE FoodId = '";
////	command += to_string(menu.foodId) + s;
////	std::wstring stemp = s2ws(command);
////	LPCWSTR result = stemp.c_str();
////	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
////	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
////	case SQL_SUCCESS:
////		cout << "[UPDATE] Successful!" << endl;
////		break;
////	case SQL_SUCCESS_WITH_INFO:
////		cout << "[UPDATE] Successful!" << endl;
////		break;
////	default:
////		cout << "[UPDATE] Fail!" << endl;
////		break;
////	}
////}
//wstring Models::s2ws(const string& s)
//{
//	int len;
//	int slength = (int)s.length() + 1;
//	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
//	wchar_t* buf = new wchar_t[len];
//	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
//	wstring r(buf);
//	delete[] buf;
//	return r;
//}
const bool Menu::operator==(const Menu& menu)
{
	if (this->foodId == menu.foodId)
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
	os << setw(6) << menu.foodId << setw(6) << menu.name << setw(6) << menu.cost;
	return os;
}
istream& operator>>(istream& is, Menu& menu)
{
	cout << "name: ";
	is.ignore();
	getline(is, menu.name);
	cout << "cost: ";
	is >> menu.cost;
	return is;
}
#endif
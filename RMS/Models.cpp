#ifndef MODELS_CPP
#define MODELS_CPP
#include "Models.h"
Models::Models() {

	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	cout << "Connecting   0%... Initialize." << endl;
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
		cout << "Connecting  15%... SQLAllocHandle." << endl;
	}
	if (SQL_SUCCESS == SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
		cout << "Connecting  30%... SQLSetEnvAttr." << endl;
	}
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
		cout << "Connecting  45%... SQLAllocHandle." << endl;
	}
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=192.168.97.253;DATABASE=qlNhaHang;Trusted=true;UID=sa;PWD=truongduc910",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT))
	{
	case SQL_SUCCESS:
		cout << "Connecting  95%... Successfully connected to SQL Server." << endl;
		break;
	case SQL_SUCCESS_WITH_INFO:
		cout << "Connecting  95%... Successfully connected to SQL Server." << endl;
		break;
	default:
		cout << "Connecting fail... Could not connect to SQL Server." << endl;
		break;
	}
	cout << "Connecting 100%... Ready to query." << endl;
}

//MENU
int Models::insert(const Menu& menu) {
	LPCWSTR result =
		s2ws(
			"INSERT INTO MENU (FoodName, Cost) VALUES" +
			parentheses(
				apostrophe(menu.name) + plus +
				apostrophe(menu.cost)
			)
		).c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;
}

int Models::update(const Menu& menu) {
	LPCWSTR result =
		s2ws(
			"UPDATE MENU SET Cost = " +
			apostrophe(menu.cost) + plus +
			"FoodName = " + apostrophe(menu.name) +
			"WHERE FoodID = " + apostrophe(menu.foodId)
		).c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;
}

int Models::remove(const Menu& menu) {
	LPCWSTR result =
		s2ws(
			"DELETE FROM MENU WHERE FoodID = " + apostrophe(menu.foodId)
		).c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;
}

int Models::select(List<Menu>& menus) {
	cout << endl;
	cout << "SQL  [SELECT] ";
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
		Menu temp;
		menus.empty();
		cout << "success" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
			menus.insert(temp);
		}
	}
	else {
		cout << "fail" << endl;
	}
	return true;
}


//DESK
int Models::insert(const Desk& desk) {
	string command = "INSERT INTO BILL (BillID, DeskID, Payment, Total) VALUES('";
	command += "')";
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;

}
int Models::remove(const Desk& desk) {
	string command = "INSERT INTO BILL (BillID, DeskID, Payment, Total) VALUES('";
	command += "')";
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;

}
int Models::select(List<Desk>& desks) {
	cout << endl;
	cout << "SQL  [SELECT] ";
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM DESK", SQL_NTS)) {
		Desk temp;
		desks.empty();
		cout << "success" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.available, SQL_RESULT_LEN, &ptrSqlVersion);
			desks.insert(temp);
		}
	}
	else {
		cout << "fail" << endl;
	}
	return true;
}

//BILL
int Models::insert(const Bill& bill) {
	string command = "INSERT INTO BILL (BillID, DeskID, Payment, Total) VALUES('";
	command += "')";
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;

}

int Models::select(List<Bill>& bills) {
	cout << endl;
	cout << "SQL  [SELECT] ";
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM BILL", SQL_NTS)) {
		Bill temp;
		bills.empty();
		cout << "success" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.billId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &temp.payment, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_DOUBLE, &temp.total, SQL_RESULT_LEN, &ptrSqlVersion);
			bills.insert(temp);
		}
	}
	else {
		cout << "fail" << endl;
	}
	return true;
}

//ADDFOOD

int Models::insert(const AddFood& addFood) {
	string command = "INSERT INTO ADDFOOD (AddfoodId, FoodId, Quantity, DeskId, BillId) VALUES('";
	command += "')";
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS);
	return true;

}

int Models::select(List<AddFood>& addFoods) {
	cout << endl;
	cout << "SQL  [SELECT] ";
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM ADDFOOD", SQL_NTS)) {
		AddFood temp;
		addFoods.empty();
		cout << "success" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.addfoodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &temp.quantity, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_INTEGER, &temp.billId, SQL_RESULT_LEN, &ptrSqlVersion);
			addFoods.insert(temp);
		}
	}
	else {
		cout << "fail" << endl;
	}
	return true;
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
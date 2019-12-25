#ifndef MODELS_CPP
#define MODELS_CPP
#include "Models.h"
Models::Models() {
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	setColor(8);
	print("Connecting   0%... Initialize.");
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
		print("Connecting  15%... SQLAllocHandle.");
	}
	if (SQL_SUCCESS == SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
		print("Connecting  30%... SQLSetEnvAttr.");
	}
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
		print("Connecting  45%... SQLAllocHandle.");
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
		print("Connecting  95%... Successfully connected to SQL Server.");
		break;
	case SQL_SUCCESS_WITH_INFO:
		print("Connecting  95%... Successfully connected to SQL Server.");
		break;
	default:
		print("Connecting fail... Could not connect to SQL Server.");
		break;
	}
	print("Connecting 100%... Ready to query.");
	setColor(15);
}

//MENU
int Models::insert(const Menu& menu) {

	print(8, "[INSERT] to SQL");
	Menu::head();
	print(1, menu);

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
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;
}

int Models::update(const Menu& menu) {

	print(8, "[UPDATE] to SQL");
	Menu::head();
	print(1, menu);
	wstring stemp = s2ws(
		"UPDATE MENU SET Cost = " +
		apostrophe(menu.cost) + plus +
		"FoodName = " + apostrophe(menu.name) +
		"WHERE FoodID = " + apostrophe(menu.foodId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};	return true;
}

int Models::remove(const Menu& menu) {

	print(8, "[REMOVE] to SQL");
	Menu::head();
	print(1, menu);
	wstring stemp = s2ws(
		"DELETE FROM MENU WHERE FoodID = " + apostrophe(menu.foodId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}

int Models::select(List<Menu>& menus) {

	print(8, "[SELECT] MENU from SQL");
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
		Menu temp;
		menus.empty();
		print(2, "Success");
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
			menus.insert(temp);
		}
	}
	else {
		print(4, "Fail");
	}
	return true;
}


//DESK
int Models::insert(const Desk& desk) {

	print(8, "[INSERT] to SQL");
	Desk::head();
	print(1, desk);
	wstring stemp = s2ws(
		"INSERT INTO DESK (DeskID) VALUES" +
		parentheses(
			apostrophe(desk.deskId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}
int Models::remove(const Desk& desk) {

	print(8, "[REMOVE] to SQL");
	Desk::head();
	print(1, desk);	wstring stemp = s2ws(
		"DELETE FROM DESK WHERE DeskID  = " + apostrophe(desk.deskId)
	).c_str();
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}
int Models::select(List<Desk>& desks) {
	print(8, "[SELECT] DESK from SQL");
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM DESK", SQL_NTS)) {
		Desk temp;
		desks.empty();
		print(2, "Success");
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.available, SQL_RESULT_LEN, &ptrSqlVersion);
			desks.insert(temp);
		}
	}
	else {
		print(4, "Fail");
	}
	return true;
}

//BILL
int Models::insert(const Bill& bill) {

	print(8, "[INSERT] to SQL");
	Bill::head();
	print(1, bill);
	wstring stemp = s2ws(
		"INSERT INTO BILL (DeskID) VALUES" +
		parentheses(
			apostrophe(bill.deskId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}

int Models::update(const Bill& bill) {

	print(8, "[UPDATE] to SQL");
	Bill::head();
	print(1, bill);
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
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}

int Models::select(List<Bill>& bills) {
	print(8, "[SELECT] BILL from SQL");
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM BILL", SQL_NTS)) {
		Bill temp;
		bills.empty();
		print(2, "Success");
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.billId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &temp.deskId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &temp.payment, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_DOUBLE, &temp.total, SQL_RESULT_LEN, &ptrSqlVersion);
			bills.insert(temp);
		}
	}
	else {
		print(4, "Fail");
	}
	return true;
}

//ADDFOOD

int Models::insert(const AddFood& addFood) {

	print(8, "[INSERT] to SQL");
	AddFood::head();
	print(1, addFood);
	wstring stemp = s2ws(
		"INSERT INTO ADDFOOD (FoodID, Quantity,BillId) VALUES" +
		parentheses(
			apostrophe(addFood.foodId) + plus +
			apostrophe(addFood.quantity) + plus +
			apostrophe(addFood.billId)
		)
	);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS) == SQL_SUCCESS) {
		print(2, "Success");
	}
	else {
		print(4, "Fail");
	};
	return true;

}

int Models::select(List<AddFood>& addFoods) {
	print(8, "[SELECT] ADDFOOD from SQL");
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLLEN ptrSqlVersion;
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM ADDFOOD", SQL_NTS)) {
		AddFood temp;
		addFoods.empty();
		print(2, "Success");
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
		print(4, "Fail");
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
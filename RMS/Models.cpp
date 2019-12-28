#ifndef MODELS_CPP
#define MODELS_CPP
#include "Models.h"
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
#ifndef MODELS_H
#define MODELS_H
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <string>
#include <cstring>
#include "Tables.h"
#include "List.h"

using namespace std;
class Models {
public:

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	string AND = "', '";
	string s = "'";

	Models();
	~Models() {};
	int get(List<Menu>&);
	int insert(const Menu&);
	int findAndRemove(const Menu&);
	//	//void menuShow(List<Menu>& menus);
	//	//void menuAdd(const Menu&);
	//	//void menuRemove(const int&);
	//	//void menuUpdate(const Menu&);
	//
		wstring s2ws(const string& s);
	
};
#endif // !MODEL_H

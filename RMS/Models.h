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
#include "Tables.h"
#include "List.h"
#include "Print.h"
using namespace std;
class Models :public Print {
public:
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

	Models();
	~Models() {};

	int insert(const Menu&);
	int update(const Menu&);
	int remove(const Menu&);
	int select(List<Menu>&);

	int insert(const Desk&);
	int remove(const Desk&);
	int select(List<Desk>&);

	int insert(const Bill&);
	int update(const Bill&);
	int select(List<Bill>&);

	int insert(const AddFood&);
	int select(List<AddFood>&);
	string parentheses(const string);
	string apostrophe(const double);
	string apostrophe(const int);
	string apostrophe(const string);
	string apostrophe(const char[]);
	string plus = ",";
	wstring s2ws(const string& s);
};
#endif // !MODEL_H

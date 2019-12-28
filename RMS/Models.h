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
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
using namespace std;
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

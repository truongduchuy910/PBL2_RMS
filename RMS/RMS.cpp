#include <iostream>
#include "Models.h"
#include "Tables.h"
#include "List.h"
#include"Controllers.h"
using namespace std;
Controllers controllers;
int main()
{
	controllers.init();
	for (int i = 0; i < controllers.bills.length; i++) {
		cout << controllers.bills[i];
	}
	controllers.home();
	/*Models models;
	List<Desk> desks;
	models.get(desks);
	desks.print();*/
	return 0;
}

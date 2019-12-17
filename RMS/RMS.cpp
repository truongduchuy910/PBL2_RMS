#include <iostream>
#include "Models.h"
#include "Tables.h"
#include "List.h"
using namespace std;
int main()
{
	Models models;
	List<Desk> desks;
	models.get(desks);
	desks.print();
}
                
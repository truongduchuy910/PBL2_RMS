#include <iostream>
#include "Models.h"
#include "Tables.h"
#include "List.h"
#include"Controllers.h"
#define SUCCESS 2
#define INFO 3
#define DANGER 4
#define WARNING 6
#define PRIMARY 8
#define LIGHT 7
#define WHITE 15

using namespace std;
Controllers controllers;
int main()
{
	controllers.init();
	controllers.home();
	return 0;
}

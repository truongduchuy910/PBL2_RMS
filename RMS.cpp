
#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List<Menu> menus;
	Menu menu;
	cin >> menu;
	menus.insert(menu);
	menus.insert(menu);
	menus.insert(menu);
	menus.insert(menu);
	menus.findAndRemove(menu);
	Menu::head();
	menus.print();
}

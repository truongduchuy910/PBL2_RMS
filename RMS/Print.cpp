#pragma once
#ifndef PRINT_CPP
#define PRINT_CPP
#include "Print.h"
Print& Print::print(const string s) {
	SetConsoleTextAttribute(hConsole, 15);
	cout << s << endl;
	return *this;
};
Print& Print::print(const int color, const string s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
#endif
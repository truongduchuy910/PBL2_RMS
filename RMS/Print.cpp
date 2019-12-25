#pragma once
#ifndef PRINT_CPP
#define PRINT_CPP
#include "Print.h"
Print& Print::setColor(const int color) {
	SetConsoleTextAttribute(hConsole, color);
	return *this;
}
Print& Print::print(const string s) {
	cout << s << endl;
	return *this;
};
Print& Print::print(const int color, const string s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::print(const int color, const Menu s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::print(const int color, const Bill s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::print(const int color, const Desk s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::print(const int color, const AddFood s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
#endif
#pragma once
#ifndef PRINT_CPP
#define PRINT_CPP
#include "Print.h"
Print& Print::setColor(const int color) {
	SetConsoleTextAttribute(hConsole, color);
	return *this;
}
Print& Print::print(const string s) {
	cout << s;
	return *this;
};
Print& Print::print(const int color, const string s) {
	SetConsoleTextAttribute(hConsole, color);
	int space = 30 - s.length();
	cout << s;
	while (space--) cout << " ";
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::println(const string s) {
	cout << s << endl;
	return *this;
};
Print& Print::println(const int color) {
	SetConsoleTextAttribute(hConsole, color);
	cout << detail(color) << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::println(const int color, const string s) {
	SetConsoleTextAttribute(hConsole, color);
	cout << s << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return *this;
};
Print& Print::print(const int x, const int y, const int color, const string s) {
	move(x, y);
	SetConsoleTextAttribute(hConsole, color);
	cout << s;
	SetConsoleTextAttribute(hConsole, 15);

	move(0, 0);
	return *this;
};
void Print::move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
string Print::detail(int status) {
	switch (status) {
	case SUCCESS:
		return "Success";
		break;
	case FAIL:
		return "Fail";
		break;
	case WARNING:
		return "Warning";
		break;
	}
}
#endif
#pragma once
#ifndef PRINT_CPP
#define PRINT_CPP
#include "Print.h"
Print& Print::color(const int color) {
	SetConsoleTextAttribute(hConsole, color);
	return *this;
}

Print& Print::hr() {
	cout << endl;
	return *this;
}

void Print::move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Print& Print::status(int status) {
	color(status);
	switch (status) {
	case SUCCESS:
		p("Success");
		break;
	case FAIL:
		p("Fail");
		break;
	case WARNING:
		p("Warning");
		break;
	}
	return *this;
}
#endif
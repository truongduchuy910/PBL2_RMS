#pragma once
#ifndef PRINT_H
#define PRINT_H
#define SUCCESS 2
#define INFO 3
#define DANGER 4
#define FAIL 4
#define WARNING 6
#define PRIMARY 8
#define LIGHT 7
#define WHITE 15
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <cstring>
#include "Tables.h"
using namespace std;
class Print {
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Print& color(const int);
	Print& hr();
	template <typename Data>
	Print& p(const Data s) {
		cout << s;
		color(WHITE);
		return *this;
	};
	template <typename Data>
	Print& alert(const Data s) {
		CONSOLE_SELECTION_INFO selectionInf;
		GetConsoleSelectionInfo(&selectionInf);
		move(0, 0);
		cout << s;
		color(WHITE);
		move(selectionInf.dwSelectionAnchor.X, selectionInf.dwSelectionAnchor.Y);
		return *this;
	};
	void move(const int, const int);
	Print& status(int);
};
#endif
#pragma once
#ifndef PRINT_H
#define PRINT_H
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
	Print& setColor(const int);
	Print& print(const string);
	Print& print(const int, const string);
	Print& print(const int, const Menu);
	Print& print(const int, const Bill);
	Print& print(const int, const Desk);
	Print& print(const int, const AddFood);
};
#endif
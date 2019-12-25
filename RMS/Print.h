#pragma once
#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
class Print {
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Print& print(const string);
	Print& print(const int, const string);
};
#endif
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
	Print& setColor(const int);
	Print& print(const string);
	Print& print(const int, const string); 
	Print& println(const string);
	Print& println(const int, const string);
	Print& println(const int);
	Print& print(const int, const int, const int, const string);
	void move(const int,const int);
	string detail(int);
};
#endif
#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Test
{
protected:
	string login;
	string password;
public:
	virtual bool log_in() = 0;
};


#pragma once
#include "Test.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User :public Test
{
	string name;
	string address;
	string phone;
public:
	User() = default;
	void sign_up();
	bool log_in() override;
	void test();
};

int choose();
int enter();


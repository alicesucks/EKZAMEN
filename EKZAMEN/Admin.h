#pragma once
#include "Test.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Admin:public Test
{
public:
	void sign_up();
	bool log_in() override;
	void statistics();
	void log_user();
	void change_password();
};

int adm_enter();
int adm_enter2();
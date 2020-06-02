#pragma once

#include <string>
#include <vector>
using namespace std;

class Module
{
private:
	string moduleName;
	int moduleGrade;


public:
	Module(string modName, int modGrade);

	void showModule();

	string getName();

	int getGrade();
};


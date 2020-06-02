#include "Module.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Module::Module(string modName, int modGrade)
{
	this->moduleName = modName;
	this->moduleGrade = modGrade;
}

void Module::showModule()
{
	if (this != NULL)
		cout << "Module " << moduleName << " has grade: " << moduleGrade << endl;
	else
		cout << "There are no modules to show." << endl;
}

string Module::getName()
{
	return this->moduleName;
}

int Module::getGrade()
{
	return this->moduleGrade;
}

#include "Person.h"
#include <iostream>

Person::Person()
{
	this->name = "";
	this->age = 0;
}

Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}

string Person::getName()
{
	return this->name;
}

int Person::getAge()
{
	return this->age;
}

//ostream& operator<<(ostream& output, Person& person)
//{
//	output << person.name << endl;
//	output << person.age << endl;
//
//	return output;
//}

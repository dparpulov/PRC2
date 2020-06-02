#pragma once
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
	string name;
	int age;

public:
	Person();

	Person(string name, int age);

	string getName();

	int getAge();

	//friend ostream& operator << (ostream& output, Person& person);
	//friend istream& operator >> (istream& input, Person& person);

};


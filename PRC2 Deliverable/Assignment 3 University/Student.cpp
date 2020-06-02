#include "Student.h"
#include "Person.h"
#include "Module.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;


Student::Student(string name, int age, int stNum)
	:Person{name, age}
{
	this->studentNumber = stNum;
	this->gradeList.clear();
}

Student::Student(const Student& student)
	:Person(student)
{
	this->studentNumber = student.studentNumber;
	int size = student.gradeList.size();
	for (int i = 0; i < size; i++)
	{
		Module* m;
		m = new Module(*(student.gradeList[i]));
		this->gradeList.push_back(m);
	}

}

Student::~Student()
{
	for (unsigned int i = 0; i < this->gradeList.size(); i++)
	{
		delete this->gradeList[i];
		this->gradeList[i] = NULL;
	}
}

void Student::addModule(string modName, int modGrade)
{
	Module* newModule = new Module(modName, modGrade);

	this->gradeList.push_back(newModule);
}

void Student::showGradeList()
{
	for (unsigned int i = 0; i < this->gradeList.size(); i++)
	{
		this->gradeList[i]->showModule();
	}
}

void Student::clearGradeList()
{
	for (unsigned int i = 0; i < this->gradeList.size(); i++)
	{
		delete this->gradeList[i];
		this->gradeList[i] = NULL;
	}
}

Student& Student::operator=(const Student& student)
{
	if (&student == this) return *this;

	Person::operator=(student);

	this->studentNumber = student.studentNumber;

	//delete modules/grades of this
	for (unsigned int i = 0; i < this->gradeList.size(); i++)
		delete this->gradeList[i];
	
	this->gradeList.clear();

	//fill it with the new modules/grades
	for (unsigned int i = 0; i < student.gradeList.size(); i++)
	{
		Module* m = new Module(*(student.gradeList[i]));
		this->gradeList.push_back(m);
	}

	return *this;
}

int Student::getStudNum()
{
	return this->studentNumber;
}

ostream& operator<<(ostream& output, Student& student)
{
	output << student.name << endl;
	output << student.age << endl;
	output << student.studentNumber << endl;
	if (student.gradeList.size() > 0)
	{
		output << student.gradeList.size() << endl;
		for (int i = 0; i < student.gradeList.size(); i++)
		{
			output << student.gradeList[i]->getName() << endl;
			output << student.gradeList[i]->getGrade() << endl;
		}
	}
	else
		output << "0" << endl;

	return output;
}

istream& operator>>(istream& input, Student& student)
{
	input >> student.name;
	input >> student.age;
	input >> student.studentNumber;
	
	int numberOfGrades = 0;
	input >> numberOfGrades;
	string moduleName = "";
	int moduleGrade = 0;
	for (int i = 0; i < numberOfGrades; i++)
	{
		input >> moduleName;
		input >> moduleGrade;
		student.gradeList.push_back(new Module(moduleName, moduleGrade));
	}

	return input;
}

#pragma once
#include "Person.h"
#include "Module.h"

#include <string>
#include <vector>
using namespace std;


class Student : public Person
{
private:
	int studentNumber;
	vector<Module*> gradeList;

public:

	Student(string name, int age, int stNum);

	Student(const Student& student);

	~Student();

	void addModule(string modName, int modGrade);

	void showGradeList();

	void clearGradeList();

	Student& operator = (const Student& student);

	int getStudNum();

	friend ostream& operator << (ostream& output, Student& student);
	friend istream& operator >> (istream& input, Student& student);


};


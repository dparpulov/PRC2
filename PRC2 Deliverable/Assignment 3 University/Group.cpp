#include "Group.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Group::Group()
{
}

Group::~Group()
{
	for (int i = 0; i < studentList.size(); i++)
	{
		delete studentList[i];
		studentList[i] = NULL;
	}
}

void Group::addStudent(string name, int age, int studentNumber)
{
	if (!studentExists(studentNumber))
	{
		Student* student = new Student(name, age, studentNumber);
		studentList.push_back(student);
	}
	
}

void Group::addStudent(Student* student)
{
	if (!studentExists(student->getStudNum()))
		studentList.push_back(student);
	else
		cout << "Student already exists.\n";
}

bool Group::studentExists(int studentNumber)
{
	for (int i = 0; i < studentList.size(); i++)
	{
		if (studentList[i]->getStudNum() == studentNumber)
		{
			return true;
		}
	}
	return false;
}

void Group::removeStudent(int studentNumber)
{
	for (int i = 0; i < studentList.size(); i++)
	{
		if (studentList[i]->getStudNum() == studentNumber)
		{
			studentList.erase(studentList.begin() + i);
		}
	}
}

void Group::showStudentList()
{
	cout << "This is the student list:\n";
	for (int i = 0; i < studentList.size(); i++)
	{
		cout << studentList[i]->getName() << " is " << studentList[i]->getAge() << " years old and his/her student number is " << studentList[i]->getStudNum() << endl;
	}
}

vector<Student*> Group::getStudentList()
{
	return studentList;
}

//ostream& operator<<(ostream& output, Group& group)
//{
//	
//
//	return output;
//}

//ostream& operator<<(ostream& output, const vector<Student>& studentList)
//{
//	for (int i = 0; i < studentList.size(); i++)
//	{
//		output << studentList[i];
//		if (i != studentList.size() - 1)
//		{
//			output << ", ";
//		}
//	}
//	output << "\n";
//	return output;
//}

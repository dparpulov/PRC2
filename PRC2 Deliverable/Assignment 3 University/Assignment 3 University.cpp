// Assignment 3 University.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Person.h"
#include "Module.h"
#include "Student.h"
#include "Group.h"

#include <string>
#include <vector>
using namespace std;


int main()
{
	int input = 1;
	Group group;
	Person person;
	Student* student = new Student("Mitko", 21, 1); //Manage the memory leaks
	Module* module = new Module("PRC", 9);

	while (input != 0)
	{
		cout << "Enter 0 to exit: \n";
		cout << "Enter 1 to print student data: \n";
		cout << "Enter 2 to create a student: \n";
		cout << "Enter 3 to create a module with its grade: \n";
		cout << "Enter 4 to add a new module and its grade to the students list: \n";
		cout << "Enter 5 to show the grade list: \n";
		cout << "Enter 6 to clear the grade list: \n";
		cout << "Enter 7 to write the data of the student on a file: \n";
		cout << "Enter 8 to read the data of a student from a file: \n";
		cout << "Enter 9 to add a student to a group: \n";
		cout << "Enter 10 to remove a student from a group: \n";
		cout << "Enter 11 to show the student list: \n";
		cout << "Enter 12 to write the data from the student list on a file: \n";
		cout << "Enter 13 to read the data of a student list from a file: \n";

		cin >> input;


		switch (input)
		{
			case 1:
				cout << student->getName() << " is " << student->getAge() << " years old and his/her student number is " << student->getStudNum() << endl;
				
			break;
			case 2:
			{
				string name;
				int age;
				int studentNumber;
				cout << "Student name: ";
				cin >> name;
				cout << "Student age: ";
				cin >> age;
				cout << "Student number: ";
				cin >> studentNumber;

				student = new Student(name, age, studentNumber);

				cout << student->getName() << " is " << student->getAge() << " years old and his/her student number is " << student->getStudNum() << endl;

			}
			break;
			case 3:
			{
				string name;
				int grade;
				cout << "Module name: ";
				cin >> name;
				cout << "Module grade: ";
				cin >> grade;

				module = new Module(name, grade);
				module->showModule();
			}
			break;
			case 4:
			{
				string name;
				int grade;
				cout << "Module name: ";
				cin >> name;
				cout << "Module grade: ";
				cin >> grade;

				student->addModule(name, grade);
			}
			break;
			case 5:
				student->showGradeList();
			break;
			case 6:
				student->clearGradeList();
			break;
			case 7:
			{
				ofstream writeFile;
				writeFile.open("student.txt");
				writeFile << *student;
				writeFile.close();
				cout << "The data of your current student is in a text file now.\n";
			}
			break;
			case 8:
			{
				cout << "This data is read from a text file\n";
				ifstream readFile;
				readFile.open("student.txt");

				Student* studentFromFile = new Student("", 0, 0);
				readFile >> *studentFromFile;
				student = studentFromFile;

				readFile.close();
				cout << studentFromFile->getName() << " is " << studentFromFile->getAge() << " years old and his/her student number is " << studentFromFile->getStudNum() << endl;
			}
			break;
			case 9:
			{
				group.addStudent(student);

				group.showStudentList();
			}
			break;
			case 10:
			{
				int studentNumber;
				cout << "Student number: ";
				cin >> studentNumber;

				group.removeStudent(studentNumber);
				group.showStudentList();
			}
			break;
			case 11:
			{
				group.showStudentList();
			}
			break;
			case 12:
			{
				ofstream writeFile;
				writeFile.open("group.txt");

				writeFile << group.getStudentList().size() << endl;
				for (int i = 0; i < group.getStudentList().size(); i++)
				{
					writeFile << *group.getStudentList()[i];
				}

				writeFile.close();
				cout << "The data of your current group is in a text file now.\n";
			}
			break;
			case 13:
			{
				cout << "This data is read from a text file.\n";
				ifstream readFile;
				readFile.open("group.txt");
				
				int amountOfStudents = 0;
				readFile >> amountOfStudents;

				if (amountOfStudents > 0)
				{
					for (int i = 0; i < amountOfStudents; i++)
					{
						Student* studentFromFile = new Student("", 0, 0);
						readFile >> *studentFromFile;

						group.addStudent(studentFromFile);
						student = studentFromFile;

					}
				}

				group.showStudentList();
				readFile.close();
			}
			break;
		}

		cout << endl;
	}
}
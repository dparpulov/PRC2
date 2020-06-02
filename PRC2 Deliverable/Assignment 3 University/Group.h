#pragma once
#include "Student.h"
#include <string>
#include <vector>

using namespace std;

class Group
{
private:
	vector<Student*> studentList;


public:
	Group();

	~Group();

	void addStudent(string name, int age, int studentNumber);
	void addStudent(Student* student);


	bool studentExists(int studentNumber);

	void removeStudent(int studentNumber);

	void showStudentList();

	vector<Student*> getStudentList();



	//friend ostream& operator << (ostream& output, Group& group);

	//friend ostream& operator << (ostream& output, const vector<Student>& studentList);



};


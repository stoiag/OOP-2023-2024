#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
using namespace std;

//class Student;

//class Profesor {
//private:
//	int varstaStudentPreluat;
//
//public:
//	void setVarstaStudentPreluat(Student s);
//	int getVarstaStudentPreluat();
//};

class Student {
private:
	char* name;
	int age;
public:
	Student();
	Student(const char* n, int a);
	Student(const Student& s);
	~Student();
	char* getName();
	int getAge();
	void setName(char* n);
	void setAge(int a);
	Student& operator=(const Student& s);
	bool operator==(const Student& s);
	Student& operator++(int);

	friend istream& operator>>(istream& is, Student& r);
	friend ostream& operator<<(ostream& os, Student& r);

	//friend Profesor;
};

#endif
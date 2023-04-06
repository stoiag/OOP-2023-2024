#include "Student.h"
#include <iostream>
#include <string.h>

// Constructor
// In: -
// Out: an empty object of type Student
Student::Student() {
	//cout << "Constructor fara parametri" << endl;
	this->name = NULL;
	this->age = 0;
}
// Constructor with parameters
// In: a name (string) and an age (integer)
// Out: an object of type Student that contains the given info
Student::Student(const char* n, int a) {
	//cout << "Constructor cu parametri" << endl;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
	this->age = a;
}
// Copy constructor
// In: an object s of type Student
// Out: another object of type Student that contains the same info as s
Student::Student(const Student& s) {
	//cout << "Constructor de copiere"<<endl;
	this->name = new char[strlen(s.name) + 1];
	strcpy_s(this->name, strlen(s.name) + 1, s.name);
	this->age = s.age;
}
// Destructor
// In: an object of type Student
// Out: -
Student::~Student() {
	//cout << "Destructor"<<endl;
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}
// getter
// In: an object of type Student
// Out: name of the student
char* Student::getName() {
	return this->name;
}
// getter
// In: an object of type Student
// Out: age of the student
int Student::getAge() {
	return this->age;
}
// setter
// In: an object of type Student and a name (string)
// Out: the same object with a new name
void Student::setName(char* n) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

// setter
// In: an object of type Student and an age (integer)
// Out: the same object with a new age
void Student::setAge(int a) {
	this->age = a;
}
// assignment operator
// In: two objects of type Student (the current one, this, and s)
// Out: the new state of the current object (this)
Student& Student::operator=(const Student& s) {
	//cout << "Operator="<<endl;
	this->setName(s.name);
	this->setAge(s.age);
	return *this;
}
// comparator
// In: two objects of type Student (this and s)
// Out: true or false
bool Student::operator==(const Student& s) {
	//cout << "Operator==" << endl;
	return ((strcmp(this->name, s.name) == 0) && (this->age == s.age));
}

Student& Student::operator++(int) {
	this->setAge(this->getAge() + 1);
	return *this;
}

//IO operators
istream& operator>>(istream& is, Student & s) {
	//cout << "Citim studentul";
	char* name = new char[10];
	is >> name;
	s.setName(name);
	is >> s.age;
	cout << "Student citit: " << s.name << " " << s.age << endl;
	return is;
}

//IO operators
ostream& operator<<(ostream& os, Student& s) {
	os << "Student: " << s.name << " " << s.age << endl;
	return os;
}

//void Profesor::setVarstaStudentPreluat(Student s) {
//	this->varstaStudentPreluat = s.age;
//}
//int Profesor::getVarstaStudentPreluat() {
//	return this->varstaStudentPreluat;
//}
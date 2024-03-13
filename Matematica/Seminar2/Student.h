#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
using namespace std;
class Student {
private:
	char* name;
	int age;
public:
	Student();
	Student(char* n, int a);
	Student(const Student& s);
	~Student();
	char* getName();
	int getAge();
	void setName(char* n);
	void setAge(int a);
	Student& operator=(const Student& s);
	bool operator==(const Student& s);
	Student operator+(const Student& s);
	Student& operator++(int);
	//Student& operator++();

	friend istream& operator>>(istream& is, Student& r);
	friend ostream& operator<<(ostream& os, Student& r);
};
#endif
#pragma once
#include "Student.h"
class StudentBursier : public Student {
private:
	char* IBAN;
public:
	StudentBursier();
	StudentBursier(char* name, int age, const char* IBAN);
	StudentBursier(const StudentBursier& sb);
	~StudentBursier();

	char* getIBAN();
	void setIBAN(char* i);

	StudentBursier& operator=(const StudentBursier& sb);
	bool operator==(const StudentBursier& sb);

	friend ostream& operator<<(ostream& os, StudentBursier& sb);
	friend istream& operator>>(istream& is, StudentBursier& sb);
};
#pragma once
#include "StudentBursier.h"
#include <cstring>

StudentBursier::StudentBursier() : Student() {
	this->IBAN = NULL;
}

StudentBursier::StudentBursier(char* name, int age, const char* i) : Student(name, age) {
	this->IBAN = new char[strlen(i) + 1];
	strcpy_s(this->IBAN, strlen(i) + 1, i);
}


StudentBursier::StudentBursier(const StudentBursier& sb) : Student(sb) {
	this->IBAN = NULL;

	if (sb.IBAN != NULL) {
		this->IBAN = new char[strlen(sb.IBAN) + 1];
		strcpy_s(this->IBAN, strlen(sb.IBAN) + 1, sb.IBAN);
	}
}

StudentBursier::~StudentBursier()
{
	if (this->IBAN != NULL) {
		delete[] this->IBAN;
		this->IBAN = NULL;
	}
}

char* StudentBursier::getIBAN(){
	return this->IBAN;
}

void StudentBursier::setIBAN(char* i) {
	if (this->IBAN) {
		delete[] this->IBAN;
	}
	this->IBAN = new char[strlen(i) + 1];
	strcpy_s(this->IBAN, strlen(i) + 1, i);
}

StudentBursier& StudentBursier::operator=(const StudentBursier& sb) {
	this->setIBAN(sb.IBAN);
	this->setAge(sb.age);
	this->setName(sb.name);
	return *this;
}

bool StudentBursier::operator==(const StudentBursier& sb) {
	Student s = (Student)sb;
	Student me = (Student)(*this);
	if (s == me && strcmp(sb.name, this->name) == 0)
	{
		return true;
	}
	return false;
}


ostream& operator<<(ostream& os, StudentBursier& sb) {
	Student s(sb);
	os << s << ";" << sb.IBAN;

	return os;
}

istream& operator>>(istream& is, StudentBursier& sb)
{
	Student s;
	char* temp = new char[10];
	is >> s;
	is >> temp;
	sb.setAge(s.getAge());
	sb.setIBAN(temp);
	sb.setName(s.getName());

	if (temp != NULL) delete[] temp;

	return is;
}

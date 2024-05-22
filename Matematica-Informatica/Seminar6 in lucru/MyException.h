#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <cstring>

class MyException {
private:
	char* message;

public:

	MyException(const char* message) {
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}

	MyException(const MyException& m) {
		this->message = new char[30];
		strcpy_s(this->message, 30, m.message);
	}

	char* getMessage() {
		return this->message;
	}
};

#endif
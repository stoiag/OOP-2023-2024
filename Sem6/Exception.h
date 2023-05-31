#include<string.h>
#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception {
private:
	const char* message;
public:
	Exception(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};

#endif
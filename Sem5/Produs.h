#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
#include <string.h>
using namespace std;

class Produs {
protected:
	char* name;
	int pret;
public:
	Produs() {
		name = NULL;
		pret = 0;
	}
	Produs(const char* n, int a) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		pret = a;
	}
	Produs(const Produs& s) {
		name = new char[strlen(s.name) + 1];
		strcpy_s(name, strlen(s.name) + 1, s.name);
		pret = s.pret;
	}
	~Produs() {
		delete[] name;
		name = NULL;
	}
	char* getName() {
		return name;
	}
	int getPret() {
		return pret;
	}
	void setName(char* n) {
		if (name != NULL) {
			delete[] name;
			name = NULL;
		}
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void setPret(int a) {
		pret = a;
	}
	//Produs& operator=(const Produs& s);
	//bool operator==(const Produs& s);
	virtual void printInfo() {
		cout << "produs: " << name << " " << pret << endl;
	}

	//friend istream& operator>>(istream& is, Produs& r);
	//friend ostream& operator<<(ostream& os, Produs& r);

};



#endif
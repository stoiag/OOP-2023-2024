#ifndef PRODUSSARAT_H
#define PRODUSSARAT_H
#include "Produs.h"
#include <iostream>
#include <string.h>
using namespace std;

class ProdusSarat : public Produs {
private:
	int cantitateSare;
public:
	ProdusSarat() : Produs() {
		cantitateSare = 0;
	}
	ProdusSarat(const char* n, int a, int c) : Produs(n, a) {
		cantitateSare = c;
	}
	ProdusSarat(const ProdusSarat& s) : Produs(s) {
		cantitateSare = s.cantitateSare;
	}
	~ProdusSarat() {
	}
	int getCantitateSare() {
		return cantitateSare;
	}

	void setCantitateSare(int c) {
		cantitateSare = c;
	}

	//Produs& operator=(const Produs& s);
	//bool operator==(const Produs& s);
	void printInfo() {
		cout << "produs sarat: " << name << " " << pret << " " << cantitateSare << '\n';
	}

	//friend istream& operator>>(istream& is, Produs& r);
	//friend ostream& operator<<(ostream& os, Produs& r);

};



#endif
#ifndef PRODUSDULCE_H
#define PRODUSDULCE_H
#include "Produs.h"
#include <iostream>
#include <string.h>
using namespace std;

class ProdusDulce : public Produs {
private:
	int cantitateZahar;
public:
	ProdusDulce() : Produs() {
		cantitateZahar = 0;
	}
	ProdusDulce(const char* n, int a, int c) : Produs(n, a) {
		cantitateZahar = c;
	}
	ProdusDulce(const ProdusDulce& s) : Produs(s) {
		cantitateZahar = s.cantitateZahar;
	}
	~ProdusDulce() {
	}
	int getCantitateZahar() {
		return cantitateZahar;
	}

	void setCantitateZahar(int c) {
		cantitateZahar = c;
	}

	//Produs& operator=(const Produs& s);
	//bool operator==(const Produs& s);
	void printInfo() {
		cout << "produs dulce: " << name << " " << pret << " " << cantitateZahar << '\n';
	}

	//friend istream& operator>>(istream& is, Produs& r);
	//friend ostream& operator<<(ostream& os, Produs& r);

};



#endif
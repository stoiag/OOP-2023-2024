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
	Produs* clone() {
		ProdusSarat* newProdus = new ProdusSarat();
		newProdus->setName(this->name);
		newProdus->pret = pret;
		newProdus->cantitateSare = cantitateSare;
		return newProdus;
	}
	int getCantitateSare() {
		return cantitateSare;
	}

	void setCantitateSare(int c) {
		cantitateSare = c;
	}

	ProdusSarat& operator=(Produs& s) {
		if (this->name != NULL) delete[] this->name;
		name = new char[strlen(s.getName()) + 1];
		strcpy_s(name, strlen(s.getName()) + 1, s.getName());
		this->pret = s.getPret();
		return *this;
	}
	//Produs& operator=(const Produs& s);
	//ProdusSarat& operator=(const ProdusSarat& s);
	//bool operator==(const Produs& s);
	void printInfo() {
		cout << "produs sarat: " << name << " " << pret << " " << cantitateSare << '\n';
	}
	char* toString() {
		int l = strlen("Produs sarat: ") + strlen(name) + 6 + 6 + 1;
		char* s = new char[l];
		strcpy_s(s, l, "Produs sarat: ");
		strcat_s(s, l, name);
		char* aux = new char[6];
		_itoa_s(pret, aux, 6, 10);
		strcat_s(s, l, aux);
		delete[] aux;
		aux = new char[6];
		_itoa_s(cantitateSare, aux, 6, 10);
		strcat_s(s, l, aux);
		delete[] aux;
		return s;
	}

	friend istream& operator>>(istream& is, ProdusSarat& p)
	{
		cout << "Introduceti nume:";
		char* name = new char[10];
		cin >> name;
		p.setName(name);
		delete[] name;

		cout << "Introduceti pret: ";
		int pret;
		cin >> pret;
		p.setPret(pret);

		cout << "Introduceti cantitate sare: ";
		int cantitate;
		cin >> cantitate;
		p.setCantitateSare(cantitate);

		return is;
	}

	friend ostream& operator<<(ostream& os, ProdusSarat& p)
	{
		cout << "produs: " << p.name << " " << p.pret << " " << p.cantitateSare << endl;
		return os;
	}

};



#endif
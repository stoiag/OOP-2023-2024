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
	~ProdusDulce() {}
	Produs* clone() {
		ProdusDulce* newProdus = new ProdusDulce();
		newProdus->setName(this->name);
		newProdus->pret = pret;
		newProdus->cantitateZahar = cantitateZahar;
		return newProdus;
	}
	char* toString() {
		int l = strlen("Produs dulce: ") + strlen(name) + 6 + 6 + 1;
		char* s = new char[l];
		strcpy_s(s, l, "Produs dulce: ");
		strcat_s(s, l, name);
		char* aux = new char[6];
		_itoa_s(pret, aux, 6, 10);
		strcat_s(s, l, aux);
		delete[] aux;
		aux = new char[6];
		_itoa_s(cantitateZahar, aux, 6, 10);
		strcat_s(s, l, aux);
		delete[] aux;
		return s;
	}
	int getCantitateZahar() {
		return cantitateZahar;
	}

	void setCantitateZahar(int c) {
		cantitateZahar = c;
	}

	ProdusDulce& operator=(ProdusDulce& s) {
		if (this->name != NULL) delete[] this->name;
		name = new char[strlen(s.getName()) + 1];
		strcpy_s(name, strlen(s.getName()) + 1, s.getName());
		this->pret = s.getPret();
		this->cantitateZahar = s.cantitateZahar;
		return *this;
	}

	//Produs& operator=(const Produs& s);
	//bool operator==(const Produs& s);
	void printInfo() {
		cout << "produs dulce: " << name << " " << pret << " " << cantitateZahar << '\n';
	}

	friend istream& operator>>(istream& is, ProdusDulce& p)
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

		cout << "Introduceti cantitate zahar: ";
		int cantitate;
		cin >> cantitate;
		p.setCantitateZahar(cantitate);

		return is;
	}

	friend ostream& operator<<(ostream& os, ProdusDulce& p)
	{
		cout << "produs: " << p.name << " " << p.pret << " " << p.cantitateZahar << endl;
		return os;
	}

};



#endif
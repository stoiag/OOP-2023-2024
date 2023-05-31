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
		if (name) {
			delete[] name;
			name = NULL;
		}
	}
	virtual Produs* clone() {
		Produs* newProdus = new Produs();
		newProdus->setName(this->name);
		newProdus->pret = pret;
		return newProdus;
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
	virtual Produs& operator=(const Produs& s) {
		if (this->name != NULL) delete[] this->name;
		name = new char[strlen(s.name) + 1];
		strcpy_s(name, strlen(s.name)+1, s.name);
		this->pret = s.pret;
		return *this;
	}
	//bool operator==(const Produs& s);
	virtual void printInfo() {
		cout << "produs: " << name << " " << pret << endl;
	}

	virtual char* toString() {
		int l = strlen("Produs: ") + strlen(name) + 6 + 1;
		char* s = new char[l];
		strcpy_s(s, l, "Produs: ");
		strcat_s(s, l, name);
		char* aux = new char[6];
		_itoa_s(pret, aux, 6, 10);
		strcat_s(s, l, aux);
		delete[] aux;
		return s;
	}

	friend istream& operator>>(istream& is, Produs& p)
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

		return is;
	}
	 
	friend ostream& operator<<(ostream& os, Produs& p)
	{
		cout << "produs: " << p.name << " " << p.pret << endl;
		return os;
	}

};

#endif
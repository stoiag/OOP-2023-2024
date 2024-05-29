#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Bacterie {
private:
	char* denumire;
	int varsta;
	char tip;
public:
	Bacterie() {
		varsta = 0;
		denumire = NULL;
		tip = 'A';
	}
	Bacterie(const char* denumire, int varsta, char tip) {
		this->varsta = varsta;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->tip = tip;
	}
	Bacterie(Bacterie& b) {
		this->varsta = b.varsta;
		this->denumire = new char[strlen(b.denumire) + 1];
		strcpy_s(this->denumire, strlen(b.denumire) + 1, b.denumire);
		this->tip = b.tip;
	}

	~Bacterie() {
		if (this->denumire != NULL)
			delete[] this->denumire;
		this->denumire = NULL;
	}

	char* getDenumire() { return this->denumire; }
	int getVarsta() { return this->varsta; }
	char getTip() { return this->tip; }

	void setDenumire(char* denumire) {
		if (this->denumire != NULL)
			delete[] this->denumire;

		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	void setVarsta(int varsta) { this->varsta = varsta; }
	void setTip(char tip) { this->tip = tip; }

	Bacterie& operator=(const Bacterie& b) {
		this->varsta = b.varsta;
		this->setDenumire(b.denumire);
		this->tip = b.tip;

		return *this;
	}

	friend ostream& operator<<(ostream& os, Bacterie b) {
		os << "Bacterie tip " << b.tip << ", denumire: " << b.denumire << ", varsta: " << b.varsta<<endl;
		return os;
	}

	friend istream& operator>>(istream& is, Bacterie b) {
		if (b.denumire != NULL) delete[] b.denumire;
		b.denumire = new char[10];
		cout << "Introduceti date bacterie:" << endl;
		cout << "Tip: ";
		is >> b.tip;
		cout << "Denumire: ";
		is >> b.denumire;
		cout << "Varsta : ";
		is >> b.varsta;

		return is;
	}

	void diviziune(Bacterie*& copii, int& size) {
		if (copii != NULL) delete[] copii;
		size = 0;

		if (this->tip == 'A') {
			copii = new Bacterie[2];
			size = 2;

			copii[0] = Bacterie(*this);
			char* nameChild1 = new char[100];
			strcpy_s(nameChild1, 100, "c1");
			strcat_s(nameChild1, 100, this->denumire);
			copii[0].setDenumire(nameChild1);

			copii[1] = Bacterie(*this);
			char* nameChild2 = new char[100];
			strcpy_s(nameChild2, 100, "c2");
			strcat_s(nameChild2, 100, this->denumire);
			copii[1].setDenumire(nameChild2);

			delete[] nameChild1;
			delete[] nameChild2;
		}
		else if (this->tip == 'B') {
			if (this->varsta % 3 == 2 && this->varsta > 0) {
				copii = new Bacterie[2];
				size = 2;

				copii[0] = Bacterie(*this);
				copii[0].setVarsta(copii[0].getVarsta() + 1);
				copii[1] = Bacterie("", 0, 'A');
				char* nameChild1 = new char[100];
				strcpy_s(nameChild1, 100, "c");
				strcat_s(nameChild1, 100, this->denumire);
				copii[1].setDenumire(nameChild1);
			}
			else {
				size = 1;
				copii = new Bacterie[size];
				copii[0] = Bacterie(*this);
				copii[0].setVarsta(copii[0].getVarsta() + 1);
			}
		}
	}
};
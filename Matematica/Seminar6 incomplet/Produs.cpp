#include "Produs.h"
#include <cstring>
#include <iostream>
using namespace std;

Produs::Produs()
{
	pret = 0;
	nume = new char[10];
	strcpy_s(nume, 10, "PRODUS");
	cod = 0;
}

Produs::Produs(int Pret, const char* Nume, int Cod) {
	pret = Pret;
	nume = new char[strlen(Nume) + 1];
	strcpy_s(nume, strlen(Nume) + 1, Nume);
	cod = Cod;
}

Produs::Produs(const Produs& pr) {
	pret = pr.pret;
	nume = new char[strlen(pr.nume) + 1];
	strcpy_s(nume, strlen(pr.nume) + 1, pr.nume);
	cod = pr.cod;
}

Produs::~Produs() {
	cout << "destructor Produs" << endl;
	if (nume != NULL)
		delete[] nume;
}

int Produs::getPret() {
	return pret;
}

char* Produs::getNume() {
	return nume;
}

int Produs::getCod() {
	return cod;
}

void Produs::setPret(int Pret) {
	pret = Pret;
}

void Produs::setNume(const char* Nume) {
	if (nume != NULL)
		delete[] nume;
	nume = new char[strlen(Nume) + 1];
	strcpy_s(nume, strlen(Nume) + 1, Nume);
}

void Produs::setCod(int Cod) {
	cod = Cod;
}

void Produs::getDescriere() {
	cout << "P" << " " << cod << " " << nume << " " << pret << endl;
}

std::istream& operator>>(std::istream& is, Produs p) {
	is >> p.cod;
	if (p.nume != NULL)
		delete[] p.nume;
	p.nume = new char[10];
	is >> p.nume;
	is >> p.pret;

	return is;
}
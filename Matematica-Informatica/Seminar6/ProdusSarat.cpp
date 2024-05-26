#include "ProdusSarat.h"
#include <iostream>
#include <cstring>
using namespace std;

ProdusSarat::ProdusSarat() : Produs()
{
	saruri = 0;
}

ProdusSarat::ProdusSarat(int pret, const char* nume, int cod, float saruri) : Produs(pret, nume, cod)
{
	this->saruri = saruri;
}

ProdusSarat::ProdusSarat(const ProdusSarat& ps) : Produs(ps)
{
	this->saruri = ps.saruri;
}

Produs* ProdusSarat::clone() {
	ProdusSarat* newProdus = new ProdusSarat();
	newProdus->setNume(nume);
	newProdus->setPret(pret);
	newProdus->setCod(cod);
	newProdus->setSaruri(saruri);
	return newProdus;
}

ProdusSarat::~ProdusSarat()
{
	cout << "destructor ProdusSarat" << endl;
}

float ProdusSarat::getSaruri()
{
	return saruri;
}

void ProdusSarat::setSaruri(float s)
{
	saruri = s;
}

void ProdusSarat::getDescriere() {
	cout << "PS" << " " << cod << " " << nume << " " << pret << " " << saruri << endl;
}

std::istream& operator>>(std::istream& is, ProdusSarat& ps) {
	cout << "cod: ";
	is >> ps.cod;
	if (ps.nume != NULL)
		delete[] ps.nume;
	ps.nume = new char[10];
	cout << "nume: ";
	is >> ps.nume;
	cout << "pret: ";
	is >> ps.pret;
	cout << "saruri: " << endl;
	is >> ps.saruri;

	return is;
}
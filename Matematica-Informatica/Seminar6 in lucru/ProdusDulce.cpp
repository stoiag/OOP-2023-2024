#include "ProdusDulce.h"
#include <iostream>
#include <cstring>
using namespace std;

ProdusDulce::ProdusDulce():Produs()
{
	zaharuri = 0;
}

ProdusDulce::ProdusDulce(int pret, const char* nume, int cod, float zaharuri) : Produs(pret, nume, cod)
{
	this->zaharuri = zaharuri;
}

ProdusDulce::ProdusDulce(const ProdusDulce& pd) :Produs(pd)
{
	this->zaharuri = pd.zaharuri;
}

ProdusDulce::~ProdusDulce()
{
	cout << "destructor ProdusDulce"<<endl;
}

float ProdusDulce::getZaharuri()
{
	return zaharuri;
}

void ProdusDulce::setZaharuri(float z)
{
	zaharuri = z;
}

void ProdusDulce::getDescriere() {
	cout << "PD" << " " << cod << " " << nume << " " << pret << " " << zaharuri << endl;
}

std::istream& operator>>(std::istream& is, ProdusDulce pd) {
	cout << "Cod:";
	is >> pd.cod;
	if (pd.nume != NULL)
		delete[] pd.nume;
	pd.nume = new char[10];
	cout << "Nume:";
	is >> pd.nume;
	cout << "Pret:";
	is >> pd.pret;
	cout << "Zaharuri:";
	is >> pd.zaharuri;

	return is;
}

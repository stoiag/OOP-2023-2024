#include<iostream>
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "Repo.h"
using namespace std;

void testDulce() {
	Repo<Produs*> repoDulce;
	Produs* pd1 = new ProdusDulce;
	Produs* pd2 = new ProdusDulce(2, "Ciocolata", 123, 0.5f);
	Produs* pd3 = new ProdusDulce(*((ProdusDulce*)pd2));
	pd3->setNume("Prajitura");
	pd3->setPret(10);
	((ProdusDulce*)pd3)->setZaharuri(0.8f);
	pd3->setCod(1234);

	repoDulce.addItem(pd1);
	repoDulce.addItem(pd2);
	repoDulce.addItem(pd3);

	repoDulce.showAll();

	delete pd1;
	delete pd2;
	delete pd3;
}

void testSarat() {
	Repo<Produs*> repoSarat;
	Produs* ps1 = new ProdusSarat;
	Produs* ps2 = new ProdusSarat(3, "Telemea", 142, 0.7f);
	Produs* ps3 = new ProdusSarat(*((ProdusSarat*)ps2));
	ps3->setNume("Saratele");
	ps3->setPret(5);
	((ProdusSarat*)ps3)->setSaruri(0.7f);
	ps3->setCod(1234);

	repoSarat.addItem(ps1);
	repoSarat.addItem(ps2);
	repoSarat.addItem(ps3);

	repoSarat.showAll();

	delete ps1;
	delete ps2;
	delete ps3;
}

void testDulceSarat() {
	Repo<Produs*> repo;
	Produs* p = new Produs;
	Produs* ps = new ProdusSarat(3, "Telemea", 142, 0.7f);
	Produs* pd = new ProdusDulce(10, "Prajitura", 1234, 0.8f);

	repo.addItem(p);
	repo.addItem(ps);
	repo.addItem(pd);

	repo.showAll();

	// se apeleaza intai destructor clasa derivata (pentru pointerii construiti astfel), apoi cel al clasei de baza
	delete p;
	delete ps;
	delete pd;
}

int main() {
	//testDulce();
	//testSarat();
	testDulceSarat();
}
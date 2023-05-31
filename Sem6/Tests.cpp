#include "tests.h"
#include "assert.h"
#include <iostream>
#include "Produs.h"
#include "ProdusSarat.h"
#include "ProdusDulce.h"
#include "Repo.h"
using namespace std;
void testFilterProduseWithRepo() {
	Repo<Produs*> repo;

	//Repo<Produs*> rep;
	//Produs p1 = Produs("paine", 7);
	//ProdusDulce p2 = ProdusDulce("inghetata", 5, 100);
	//ProdusSarat p3 = ProdusSarat("sare", 10, 111);
	ProdusSarat* pp1 = new ProdusSarat("Ppaine", 7, 7);
	ProdusDulce* pp2 = new ProdusDulce("Pinghetata", 5, 100);

	repo.addItem(pp1);
	repo.addItem(pp2);

	for (int i = 0; i < repo.getSize(); i++)
		repo.getItem(i)->printInfo();
	////pp1->printInfo();
	////pp1 = pp2;
	////p1.printInfo();
	////p1 = p2;
	//p3.printInfo();
	//p3 = p2;
	//p3.printInfo();
	//rep.addItem(&p1);
	//rep.addItem(&p2);
	//rep.addItem(&p3);
	//for (int i = 0; i < rep.getSize(); i++)
	//{
	//	rep.getEntities()[i]->printInfo();
	//}

	//delete pp1; delete pp2;
}
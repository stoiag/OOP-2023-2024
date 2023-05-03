#include "tests.h"
#include "assert.h"
#include <iostream>
#include "Produs.h"
#include "ProdusSarat.h"
#include "ProdusDulce.h"
#include "Repo.h"
using namespace std;
void testFilterProduseWithRepo() {
	Repo <Produs*> rep;
	Produs p1 = Produs("paine", 7);
	ProdusDulce p2 = ProdusDulce("inghetata", 5, 100);
	ProdusSarat p3 = ProdusSarat("sare", 10, 111);
	rep.addItem(&p1);
	rep.addItem(&p2);
	rep.addItem(&p3);
	for (int i = 0; i < rep.getSize(); i++)
	{
		rep.getEntities()[i]->printInfo();
	}
}
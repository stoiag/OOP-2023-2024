#include "Repo.h"
#include "Produs.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "Exception.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef bool (*filterfunct)(int, string);

class Controller
{
private:
	Repo<Produs*> repo;
public:
	Controller() { this->repo = Repo<Produs*>(); }
	void adaugare(ProdusDulce& p) {
		ProdusDulce* pp = new ProdusDulce(p);
		repo.addItem(pp);
		delete pp;
	}
	vector<Produs*> getAll() {
		return repo.getEntities();
		/*for (int i = 0; i < repo.getSize(); i++) {
			repo.getItem(i)->printInfo();
		}*/
	}
	void adaugare(ProdusSarat& r) {
		ProdusSarat* pp = new ProdusSarat(r);
		repo.addItem(pp);
		delete pp;
	}
	void stergere(int poz) {
		try {
			repo.delItem(poz);
		}
		catch (Exception& msg) {
			throw msg;
		}
	 
	}
	Repo<Produs*> getRepo() { return this->repo; }
	
	//vector<Produs*> filtrare(int pret, char nume[])
	//{
	//	vector<Produs*> produse = this->getAll();
	//	vector<Produs*> filter;
	//	for (int i = 0; i < produse.size(); i++)
	//	{
	//		if (strcmp(produse[i]->getName(), nume) == 0 && produse[i]->getPret() == pret)
	//			filter.push_back(produse[i]);
	//	}
	//	return filter;
	//}
};

#endif // !CONTROLLER_H
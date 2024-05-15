#pragma once
#ifndef UI_H
#define UI_H
#include "Produs.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "Service.h"
#include"MyException.h"
#include <vector>

template <class T>
class UI {
private:
	Service<T> service;

public:
   	UI() { }
	~UI() { }

	void uiAddItem() {
		cout << "ce tip de obiect doriti sa adaugati? (PD sau PS)" << endl;
		string raspuns;
		cin >> raspuns;

		if (raspuns == "PD") {
			ProdusDulce pd;
			cin >> pd;
			service.addItem(&pd);
		}
		else if (raspuns == "PS") {
			ProdusSarat ps;
			cin >> ps;
			service.addItem(&ps);
		}
		else {
			throw MyException("acest  tip de produs nu exista");
		}
	}
	void uiGetItems() const {
		vector<T> rez = service.getItems();
		for (int i = 0; i < rez.size(); i++) {
			rez[i]->getDescriere();
		}
	}

	void afisareMeniu() {
		while (true) {
			cout << "- - - MENIU - - -" << endl;
			cout << "1. adauga." << endl;
			cout << "2. afiseaza. " << endl;
			//cout << "3. sorteaza. " << endl;
			cout << "0. exit" << endl;

			cout << "alegeti optiunea: ";
			int optiune;
			cin >> optiune;
			try {
				switch (optiune) {
				case 1: {
					uiAddItem();
					break;
				}
				case 2: {
					uiGetItems();
					break;
				}
				case 0: {
					return;
				}
				}
			}
			catch(MyException& exc) {
				cout << exc.getMessage();
			}
		}
	}
};

#endif // !UI_H

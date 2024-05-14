#ifndef UI_H
#define UI_H
#include <iostream>
#include "Service.h"
using namespace std;

template <class T>
class UI {
private:
	Service<T> service;
public:
	//UI() {}

	void afisare_meniu() {
		cout << "\n1.Afisare lista" <<
			"\n2.Adaugare element" <<
			"\n3.Filtrare" <<
			"\n4.Inchidere meniu" << endl;
	}
	void run() {
		int option;
		while (true) {
			afisare_meniu();

			cout << "Alege optiune:";
			cin >> option;
			if (option == 1)
				showAll();
			else if (option == 2)
				adaugare();
			else if (option == 3)
				filtrare();
			else if (option == 4)
				break;
			else cout << "Comanda necunoscuta!";
		}
	}
	void adaugare() {
		T s;
		cin >> s;
		service.adaugare(s);
	}
	void filtrare() {
		T filtru;
		cin >> filtru;
		vector<T> rez = service.filtrare(filtru);
		showList(rez);
	}

	void showList(vector<T> list) {
		typename vector<T>::iterator it;
		for (it = list.begin(); it < list.end(); it++)
			cout << *it << endl;
	}

	void showAll()
	{
		vector<T> list = service.getItems();
		showList(list);
	}
};

#endif

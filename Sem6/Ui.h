#include <iostream>
#include "Controller.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "Exception.h"
#ifndef UI_H
#define UI_H

using namespace std;

class Ui
{
private:
	Controller controller;
public:
	Ui() { this->controller = Controller(); }
	Ui(Controller& controller) { this->controller = controller; }
	~Ui() {}
	void print_menu() {
		cout << "1. Adauga produs:\n";
		cout << "2. Elimina produs\n";
		cout << "3. Afiseaza toate produsele\n";
		cout << "4. Filtrare dupa pret si nume\n";
		cout << "5. Iesire\n";
	}

	void start()
	{
		print_menu();
		int input;
		bool ok = true;
		while (ok)
		{
			cout << "Introduceti optiune: ";
			cin >> input;
			if (input > 5) throw Exception("optiune invalida!");
			else
			{
				switch (input)
				{
				case 1: 
					adaugare();
					break;
				case 2:
					eliminare();
					break;
				case 3:
					afisare();
					break;
				case 4:
					filtrare();
					break;
				case 5:
					ok = false;
					break;
				}
			}
		}
	}

	void adaugare()
	{
		ProdusDulce p;
		ProdusSarat r;
		string tip;
		cout << "Introducere tip produs:";
		cin >> tip;
		if (tip == "dulce")
		{
			cin >> p;
			controller.adaugare(p);
		}
		else
		{
			cin >> r;
			controller.adaugare(r);
		}
	}

	void eliminare()
	{
		int poz;
		cout << "Input pozitie: ";
		cin >> poz;
		try {
			controller.stergere(poz);
		}
		catch (Exception& msg) {
			cout<<msg.getMessage();
		}
	}
	void afisare()
	{
		vector<Produs*> produse = this->controller.getAll();
		for (int i = 0; i < produse.size(); i++) {
			produse[i]->printInfo();
		}
	}
	void filtrare()
	{
		int pret;
		char nume[20];
		cout << "Dati pretul si numele produselor " << endl;
		cin >> pret >> nume;
		/*vector<Produs*> filter =this->controller.filtrare(pret, nume);
		for (int i = 0; i < filter.size(); i++)
			cout << *(filter[i]) << endl;*/
	}
};

#endif // !UI_H

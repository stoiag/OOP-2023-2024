#ifndef UI_H
#define UI_H
#include <iostream>
#include "Student.h"
#include "Service.h"
using namespace std;
class UI {
private:
	Service service;
public:
	UI()
	{
		service = Service();
	}

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
		Student s;
		cin >> s;
		service.adaugare(s);
	}
	void filtrare() {
		char* nume=new char[10];
		int age;
		cout << "Nume:";
		cin >> nume;
		cout << "Varsta:";
		cin >> age;
		Student s(nume, age);
		vector<Student> rez = service.filtrare(s);
		showList(rez);
	}

	void showList(vector<Student> list) {
		vector<Student>::iterator it;
		for (it = list.begin(); it < list.end(); it++)
			cout << *it << endl;
	}

	void showAll()
	{
		vector<Student> list = service.getItems();
		showList(list);
	}
};

#endif

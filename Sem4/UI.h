#ifndef UI_H
#define UI_H
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include "Student.h"
#include "Service.h"
using namespace std;

class UI {
private:
	Service service;
public:
	UI(const Service& service);
	~UI();

	void readFromFile();
	void addItem();
	void getItem();
	void printMenu();
	void filterStudentsWithRepo();
	void runMenu();
	void getEntities();
};

UI::UI(const Service& service) {
	this->service = service;
}

UI::~UI() {};

void UI::addItem() {
	StudentBursier student;
	cout << "Introduceti datele studentului (nume, varsta, IBAN): ";
	cin >> student;
	this->service.addItem(student);
}

void UI::getItem() {
	int pos;
	cout << "Introduceti pozitia: ";
	cin >> pos;
	StudentBursier student = this->service.getItem(pos);
	cout << student << endl;
}

void UI::filterStudentsWithRepo() {
	int age;
	char* name = new char[20];
	cout << "Introduceti numele: ";
	cin >> name;
	cout << "Introduceti varsta: ";
	cin >> age;
	char* IBAN = new char[256];
	cout << "Introduceti IBAN: ";
	cin >> IBAN;

	vector<StudentBursier> studFilter = this->service.filterStudentiBursieriWithRepo(name, age, IBAN);
	vector<StudentBursier>::iterator it = studFilter.begin(); // eroare: adaugat keyword template
	while (it != studFilter.end()) {
		cout << *it;
		it++;
	}

	delete[] name;
	delete[] IBAN;
};

void UI::printMenu() {
	cout << endl << "1. Adauga student" << endl;
	cout << "2. Preluare student" << endl;
	cout << "3. Citire din fisier" << endl;
	cout << "4. Filtrare studenti" << endl;
	cout << "5. Afisare studenti" << endl;
}

void UI::readFromFile() {
	char* filename = new char[100];
	cout << "Dati numele fisierului: ";
	cin >> filename;
	this->service.readFromFile(filename);

	delete[] filename;
}

void UI::getEntities() {
	vector<StudentBursier> entities = this->service.getEntities();
	vector<StudentBursier>::iterator it = entities.begin();
	while (it != entities.end()) {
		cout << *it;
		it++;
	}
}

void UI::runMenu() {
	int optiune;	
	
	while (true) {
		printMenu();
		cout << "Selectati optiunea: ";
		cin >> optiune;
		switch (optiune)
		{
			case 1:
				this->addItem();
				break;
			case 2:
				this->getItem();
				break;
			case 3:
				this->readFromFile();
				break;
			case 4:
				this->filterStudentsWithRepo();
				break;
			case 5:
				this->getEntities();
				break;
			default:
				return;
		}
	}
}

#endif

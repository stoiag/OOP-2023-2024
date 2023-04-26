#pragma once
#include "Repo.h"
#include "StudentBursier.h"
#include <fstream>

class Service {
private:
	Repo<StudentBursier> repo;
public:
	Service() {
		this->repo = Repo<StudentBursier>(); // eroare: adaugat constructor fara parametri, altfel eroare la constructor UI cu paramteri
	}

	Service(const Repo<StudentBursier>& repo) {
		this->repo = repo;
	};

	~Service() {};

	void readFromFile(char* fileName) {
		ifstream fin;
		char* aux, * nextToken;
		fin.open(fileName);
		aux = new char[30];
		while (fin.getline(aux, 30)) {
			char* name = strtok_s(aux, ";", &nextToken);
			char* ageString = strtok_s(NULL, ";", &nextToken);
			int age = atoi(ageString);
			StudentBursier s(name, age, "");
			this->repo.addItem(s);
		}

		fin.close();
		delete[] aux;
	};
	void addItem(const StudentBursier& s) {
		this->repo.addItem(s);
	};
	StudentBursier getItem(int pos) {
		return this->repo.getItem(pos);
	};
	vector<StudentBursier> filterStudentiBursieriWithRepo(const char* s, int a, const char* IBAN) {
		vector<StudentBursier> studFilter;
		studFilter.reserve(10);
		for (int i = 0; i < this->repo.getSize(); i++) {
			StudentBursier crtStudentBursier = this->repo.getItem(i);
			if (
				(strcmp(s, crtStudentBursier.getName()) == 0)
				&& (crtStudentBursier.getAge() >= a)
				&& (strcmp(IBAN, crtStudentBursier.getIBAN()) == 0)
			) {
				studFilter.push_back(crtStudentBursier);
			}
		}
		return studFilter;
	};
	vector<StudentBursier> getEntities() {
		return this->repo.getEntities();
	};
};
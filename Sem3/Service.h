#pragma once
#include "Repo.h"
#include <fstream>

class Service {
private:
	Repo<Student> repo;
public:
	Service() {
		this->repo = Repo<Student>(); // eroare: adaugat constructor fara parametri, altfel eroare la constructor UI cu paramteri
	}

	Service(const Repo<Student>& repo) {
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
			Student s(name, age);
			this->repo.addItem(s);
		}

		fin.close();
		delete[] aux;
	};
	void addItem(const Student& s) {
		this->repo.addItem(s);
	};
	Student getItem(int pos) {
		return this->repo.getItem(pos);
	};
	vector<Student> filterStudentsWithRepo(const char* s, int a) {
		vector<Student> studFilter;
		studFilter.reserve(10);
		for (int i = 0; i < this->repo.getSize(); i++) {
			Student crtStudent = this->repo.getItem(i);
			if ((strcmp(s, crtStudent.getName()) == 0) && (crtStudent.getAge() >= a)) {
				studFilter.push_back(crtStudent);
			}
		}
		return studFilter;
	};
	vector<Student> getEntities() {
		return this->repo.getEntities();
	};
};
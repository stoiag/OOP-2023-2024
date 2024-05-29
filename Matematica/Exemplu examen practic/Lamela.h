#pragma once
#pragma once
#include <cstring>
#include <iostream>
#include "Bacterie.h"
using namespace std;

class Lamela {
private:
	Bacterie* populatie;
	int size;
public:
	Lamela() {
		size = 0;
		populatie = NULL;
	}
	Lamela(Bacterie* populatie, int size) {
		this->populatie = new Bacterie[size];
		this->size = size;
		for (int i = 0; i < size; i++)
			this->populatie[i] = populatie[i];
	}
	~Lamela() {
		if (this->populatie != NULL)
			delete[] this->populatie;
	}

	Bacterie* getPopulatie() { return this->populatie; }
	int getSize() { return this->size; }



	void applyDivision() {
		Bacterie* newPopulation = new Bacterie[2 * size];
		int counter = 0;
		for (int i = 0; i < size; i++) {
			Bacterie* aux = NULL; int auxSize;
			populatie[i].diviziune(aux, auxSize);
			for (int j = 0; j < auxSize; j++) {
				newPopulation[counter++] = aux[j];
			}
		}

		this->setPopulatie(newPopulation, counter);
		delete[] newPopulation;
	}

	void setPopulatie(Bacterie* populatie, int size) {
		if (this->populatie != NULL)
			delete[] this->populatie;

		this->size = size;
		this->populatie = new Bacterie[size];

		for (int i = 0; i < size; i++) {
			this->populatie[i] = populatie[i];
		}
	}
	void setSize(int size) { this->size = size; }

	friend ostream& operator<<(ostream& os, Lamela& l) {
		os << "Populatie lamela: " << endl;
		for (int i = 0; i < l.size; i++) {
			os << l.populatie[i];
		}
		cout << endl;

		return os;
	}
};
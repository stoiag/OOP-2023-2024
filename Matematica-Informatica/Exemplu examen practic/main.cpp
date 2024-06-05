#include <iostream>
using namespace std;
#include "Lamela.h"

int main() {
	Lamela lamela;

	Bacterie* populatieInitiala = new Bacterie[5];
	populatieInitiala[0] = Bacterie("B1", 0, 'A');
	populatieInitiala[1] = Bacterie("B2", 0, 'A');
	populatieInitiala[2] = Bacterie("B3", 0, 'B');
	populatieInitiala[3] = Bacterie("B4", 0, 'A');
	populatieInitiala[4] = Bacterie("B5", 0, 'B');

	lamela.setPopulatie(populatieInitiala, 5);
	cout << "T=0" << endl << lamela;

	int nr_iter;
	cout << "Introduceti nr. de iteratii: ";
	cin >> nr_iter;

	for (int i = 1; i <= nr_iter; i++) {
		lamela.applyDivision();
		cout << "T=" << i << endl << lamela;
	}

	return 0;
}
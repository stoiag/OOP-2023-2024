#include "sem1.h"
#include <assert.h>
#include <iostream>
using namespace std;

void myTests1() {
	assert(maxim(12, 32) == 32);
	assert(maxim(22, 11) == 22);
	cout << "Testele au avut succes!" << endl;
}
void myTests2() {
	assert(maxim2(12, 32, 40) == 40);
	assert(maxim2(22, 11, 10) == 22);
	cout << "Testele au avut succes!" << endl;
}
void myTests3() {
	assert(calcul(12, 32, '+') == 44);
	assert(calcul(2, 1, '*') == 2);
	assert(calcul(4, 2, '/') == 2);
	assert(calcul(4, 2, '-') == 2);
	assert(calcul(4, 2, '@') == -1);
	cout << "Testele au avut succes!" << endl;
}

void myTests5() {
	assert(primulNumarPrimDupaX(0) == 2);
	assert(primulNumarPrimDupaX(5) == 7);
	assert(primulNumarPrimDupaX(20) == 23);

	assert(estePrim(0) == false);
	assert(estePrim(-25) == false);
	assert(estePrim(13) == true);

	cout << "Testele au avut succes!" << endl;
}

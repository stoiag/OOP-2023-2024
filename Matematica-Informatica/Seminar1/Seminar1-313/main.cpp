#include <iostream>
#include <string.h>
//#include "tests.h"
//#include "sem1.h"
using namespace std;

int* test(int v[], int* &rez) {
	for (int i = 0; i < 4; i++)
		cout << v[i];

	cout << endl;

	if (rez != NULL)
		delete[] rez;
	rez = new int[2];

	rez[0] = 2;
	rez[1] = 5;

	return rez;
}

int main() {
	//Problema 1
	/*myTests1();
	problema1();*/
	
	//Problema 2
	//myTests2();
	//problema2();

	//Problema3
	//myTests3();
	//problema3();

	//Problema5
	//myTests5();
	//problema5();

	// Problema 6
	//problema6();

	/*int v[] = {1, 2, 3, 4};
	int* sol = NULL;

	int* result = test(v, sol);

	for (int i = 0; i < 2; i++) {
		cout << sol[i] << ";;;" << result[i];
	}

	delete[] sol;*/

	char* test = new char[20];
	strcpy_s(test, 20, "test");
	cout << test;

	return 0;
}
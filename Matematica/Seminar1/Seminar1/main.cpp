#include <iostream>
#include "pb1.h"
using namespace std;

int main()
{
	/*
	//pb1
	pb1_test();
	int a, b;
	pb1_citire(a, b);
	cout << pb1(a, b);
	*/

	/*
	//pb2
	pb2_test();
	int a, b, c;
	pb2_citire(a, b, c);
	cout << pb2(a, b, c);
	*/

	/*
	//pb3
	pb3_test();
	int a, b;
	char op;
	pb3_citire(a, b, op);
	cout << pb3(a, b, op);
	*/

	/*
	//pb4
	pb4_test();
	int a;	
	pb4_citire(a);
	cout << pb4(a);
	*/

	/*
	//pb7 alocare statica
	int a[CAP];
	pb7_citire(a);
	pb7(a);

	//pb7 alocare dinamica
	//alloc
	int* a = new int[CAP];
	pb7_dinamic_citire(a);
	pb7_dinamic(a);

	//dealloc
	delete[] a;
	*/

	// alocare statica
	//int a[12][12];
	// alocare dinamica
	int** a = new int*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new int[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Introduceti a(" << i << ", " << j << ")" << endl;
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " " << *(*(a+i)+j)<<endl;
	
	//dealloc
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
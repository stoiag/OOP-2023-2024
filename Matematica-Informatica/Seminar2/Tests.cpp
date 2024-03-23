#include "Operations.h"
#include "assert.h"
#include <iostream>
using namespace std;
void testFilterStudents() {
	char* Ana = new char[20];
	//*Ana <=> Ana[0]
	//*(A+1) <=> A[1]
	strcpy_s(Ana, 20, "Ana");
	char* Maria = new char[20];
	strcpy_s(Maria, 20, "Maria");
	Student test;
	Student test1(test);
	cout << "Test" << endl;
	Student s1(Ana, 19);
	cout << s1 << s1++ << endl;
	Student s2(Maria, 19);
	Student s3(Ana, 20);
	Student s4(Ana, 18);
	Student studs[4] = { s1, s2, s3, s4 };
	cout << "aici";
	Student s = s1;
	s = s2;
	Student results[4];
	int m = 0;
	filterStudents(studs, 4, s1, results, m);
	assert((m == 1) && (results[0] == s1));
	Student s10 = (s1++) + s2;
	cout << s10;

	//cout << s1.getAge() << endl;
	//s1++;
	//cout << s1.getAge() << endl;

	Student s6;
	cin >> s6;
	cout << s6;

	delete[] Ana;
	delete[] Maria;
}
void testFilterStudentsWithRepo() {
	char* Ana = new char[20];
	strcpy_s(Ana, 20, "Ana");
	char* Maria = new char[20];
	strcpy_s(Maria, 20, "Maria");
	Student s1(Ana, 19);
	Student s2(Maria, 19);
	Student s3(Ana, 20);
	Student s4(Ana, 18);
	Student s5;

	Repo rep;
	rep.addItem(s1);
	rep.addItem(s2);
	rep.addItem(s3);
	rep.addItem(s4);
	cout << &rep[3];
	Student results[10];
	int m = 0;
	filterStudentsWithRepo(rep, Ana, 19, results, m);
	assert((m == 2) && (results[0] == s1) && (results[1] == s3));
	for (int i = 0; i < m; i++) {
		cout << results[i] << endl;
	}
}
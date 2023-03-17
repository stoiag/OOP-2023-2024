#include "tests.h"
#include "operations.h"
#include "assert.h"
#include <iostream>
using namespace std;
void testFilterStudents() {
	const char* Ana = "Ana";
	const char* Maria = "Maria";
	Student s1(Ana, 19);
	Student s2(Maria, 19);
	Student s3(Ana, 20);
	Student s4(Ana, 18);
	Student studs[4] = { s1, s2,s3, s4 };
	Student results[4];
	int m = 0;
	filterStudents(studs, 4, Ana, 19, results, m);
	assert((m == 2) && (results[0] == s1) && (results[1] == s3));

	//cout << s1.getAge() << endl;
	//s1++;
	//cout << s1.getAge() << endl;

	Student s6;
	cin >> s6;
	cout << s6;
}
void testFilterStudentsWithRepo() {
	const char* Ana = "Ana";
	const char* Maria = "Maria";
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
	Student results[10];
	int m = 0;
	filterStudentsWithRepo(rep, Ana, 19, results, m);
	assert((m == 2) && (results[0] == s1) && (results[1] == s3));
	for (int i = 0; i < m; i++) {
		cout << results[i] << endl;
	}
}
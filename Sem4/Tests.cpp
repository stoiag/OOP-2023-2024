#include "tests.h"
#include "assert.h"
#include <iostream>
#include "Student.h"
#include "StudentBursier.h"
#include "Repo.h"
using namespace std;
//void testFilterStudents() {
//	const char* Ana = "Ana";
//	const char* Maria = "Maria";
	/*Student s1(Ana, 19);
	Profesor prof;*/
	//prof.setVarstaStudentPreluat(s1);
	//cout << prof.getVarstaStudentPreluat();
	//Student s2(Maria, 19);
	//Student s3(Ana, 20);
	//Student s4(Ana, 18);
	//Student s5;
	//Student s6(s3);
	//s5 = s4;
	//cout << s5;

	//Student studs[4] = { s1, s2,s3, s4 };
	//Student results[4];
	//int m = 0;
	//filterStudents(studs, 4, Ana, 19, results, m);
	//assert((m == 2) && (results[0] == s1) && (results[1] == s3));

	//cout << s1.getAge() << endl;
	//cout << (s1++)++;
	//cout << s1;
	//cout << s1.getAge() << endl;

	/*Student s6, s5;
	cin >> s6 >> s5;
	cout << s6 << s5;*/
//}
void testFilterStudentsWithRepo() {
	const char* Ana = "Ana";
	const char* Maria = "Maria";
	const char* IBAN = "Test IBAN";
	const char* IBAN2 = "Test2 IBAN";
	/*Student s1(Ana, 19);
	Student s2(Maria, 19);*/
	//StudentBursier* sb1 = new StudentBursier();
	//StudentBursier sb3(Ana, 19, IBAN);
	StudentBursier sb4(Maria, 18, IBAN2);
	//Student* sb2 = sb1);
	//Student s3(Ana, 20);
	//Student s4(Ana, 18);
	//Student s5;

	//Repo<StudentBursier> rep;
	//rep.addItem(s1);
	//rep.addItem(s2);
	//rep.addItem(s3);
	//rep.addItem(s4);
	//rep.addItem(sb1);
	//rep.addItem(sb3);
	//rep.addItem(sb4);
	//Student results[10];
	//int m = 0;
	//filterStudentsWithRepo(rep, Ana, 19, results, m);
	//assert((m == 2) && (results[0] == s1) && (results[1] == s3));
	//for (int i = 0; i < m; i++) {
	//	cout << results[i] << endl;
	//}
}
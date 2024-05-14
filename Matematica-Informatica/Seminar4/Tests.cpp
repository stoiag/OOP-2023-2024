//#include "Operations.h"
#include "assert.h"
#include "Student.h"
#include "StudentBursier.h"
#include "Repo.h"
#include "Operations.h"
#include <iostream>
using namespace std;

void testFilterStudents() {
	char* Ana = new char[20];
	//*Ana <=> Ana[0]
	//*(A+1) <=> A[1]
	strcpy_s(Ana, 20, "Ana");
	char* Maria = new char[20];
	strcpy_s(Maria, 20, "Maria");
	Student test; // constructor fara parametri
	Student test1(test); // constructor de copiere
	cout << "Test" << endl;
	Student s1(Ana, 19); // constructor cu parametri

	cout << s1 << s1++ << endl; // comportament nedefinit (ambele expresii acceseaza aceeasi locatie de memorie)
	// operator<<, operator++, operator<< OR operator++, operator<<, operator<<

	Student s2(Maria, 19);// constructor cu parametri
	Student s3(Ana, 20);// constructor cu parametri
	Student s4(Ana, 18);// constructor cu parametri
	Student studs[4] = { s1, s2, s3, s4 }; // 4x constructor de copiere (optimizare)
	cout << "aici" << endl;
	Student s = s1; // optimizare a compilatorului - nu se apeleaza constructorul fara parametri, urmat de operator=, ci direct constructorul de copiere
	// a se vedea copy elision
	s = s2; // operator=
	Student results[4]; // 4x constructor fara parametri
	int m = 0;
	filterStudents(studs, 4, s1, results, m); // constructor de copiere pentru parametrul s1, operator==, operator=, 3xoperator==, destructor pentru s1
	assert((m == 1) && (results[0] == s1)); // operator==
	Student s10 = (s1++) + s2; // operator++, operator+; nu se apeleaza niciun constructor, operator+ returneaza un obiect de tip Student
	cout << s10; // operator<<

	cout << s1.getAge() << endl;
	s1++; // operator++
	cout << s1.getAge() << endl;

	Student s6; // constructor fara parametri
	cin >> s6;
	cout << s6;

	delete[] Ana;
	delete[] Maria;

	//destructori pentru toate obiectele Student create in interiorul functiei
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

	Repo<Student> rep;

	//rep.addItem(s1);
	//rep.addItem(s2);
	//rep.addItem(s3);
	//rep.addItem(s4);
	//cout << rep[3];

	rep.readfile("C:\\Users\\George\\source\\repos\\Sem2-313\\Sem2-313\\studenti.txt");
	cout << "Teste"<<endl;
	rep.showAll();
	rep.addItem(s1);
	rep.addItem(s2);
	rep.addItem(s3);
	rep.addItem(s4);
	rep.writeFile("C:\\Users\\George\\source\\repos\\Sem2-313\\Sem2-313\\studenti.txt");

	/*cout << &rep[3];
	Student results[10];
	int m = 0;
	filterStudentsWithRepo(rep, Ana, 19, results, m);
	assert((m == 2) && (results[0] == s1) && (results[1] == s3));
	for (int i = 0; i < m; i++) {
		cout << results[i] << endl;
	}*/
}

void testFilterStudentsWithRepoInheritance() {
	char* Ana = new char[20];
	strcpy_s(Ana, 20, "Ana");
	char* Maria = new char[20];
	strcpy_s(Maria, 20, "Maria");
	Student s1(Ana, 19);
	Student s2(Maria, 19);
	Student s3(Ana, 20);
	Student s4(Ana, 18);
	Student s5;

	Repo<Student> repoStud;
	repoStud.addItem(s1);
	repoStud.addItem(s1);
	repoStud.addItem(s1);


	StudentBursier sb;
	StudentBursier sb1(Ana, 18, "testIBAN");
	StudentBursier sb2(Maria, 20, "testIBAN2");
	StudentBursier sb3(sb2);
	StudentBursier sb4 = sb3;


	Repo<StudentBursier> repoStudBursieri;

	repoStudBursieri.addItem(sb);
	repoStudBursieri.addItem(sb1);
	repoStudBursieri.addItem(sb2);
	repoStudBursieri.addItem(sb3);
	repoStudBursieri.addItem(sb4);
	cout << repoStudBursieri[4];
}
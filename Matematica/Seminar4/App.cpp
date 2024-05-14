#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "Student.h"
#include "StudentBursier.h"
using namespace std;

int main() {

	cout << " start... " << endl;

	testFilterStudentsWithRepoInheritance();
	UI<StudentBursier> ui;
	ui.run();
	//testFilterStudents();
	//testFilterStudentsWithRepo();
	cout << " good job!! " << endl;
	return 0;
}
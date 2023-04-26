#include <iostream>
#include "tests.h"
#include "UI.h"
using namespace std;
int main() {
	//testFilterStudents();
	testFilterStudentsWithRepo();
	// testFilterStudentsWithRepoWithStl();
	Repo<StudentBursier> repo;
	Service service(repo);
	UI ui(service);
	ui.runMenu();
	return 0;
}
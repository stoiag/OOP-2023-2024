#include "Operations.h"
// filter all the students of a given name and older than a given limit
// In: an array of students and their number (integer), a name (String), an age (integer)
// Out: an array of filtered students and their number (integer)
void filterStudents(Student students[], int n, const char* s, int a, Student studFilter[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if ((strcmp(s, students[i].getName()) == 0) && (students[i].getAge() >= a)) {
			studFilter[m++] = students[i];
		}
	}
}

void filterStudents(Student students[], int n, Student comp, Student studFilter[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (comp == students[i]) {
			studFilter[m++] = students[i];
		}
	}
}
 //filter all the students of a given name and older than a given limit
 //In: an array of students and their number (integer), a name (String), an age (integer)
 //Out: an array of filtered students and their number (integer)
void filterStudentsWithRepo(Repo<Student>& rep, const char* s, int a, Student studFilter[], int& m) {
	for (int i = 0; i < rep.getSize(); i++) {
		Student crtStudent = rep.getItemFromPos(i);
		if ((strcmp(s, crtStudent.getName()) == 0) && (crtStudent.getAge() >= a)) {
			studFilter[m++] = crtStudent;
		}
	}
}
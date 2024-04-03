#include "Student.h"
#include "Repo.h"
void filterStudents(Student students[], int n,
	const char* s, int a, Student studFilter[], int& m);
void filterStudents(Student students[], int n,
	Student s, Student studFilter[], int& m);
void filterStudentsWithRepo(Repo<Student>& rep, const char* s,
	int a, Student studFilter[], int& m);
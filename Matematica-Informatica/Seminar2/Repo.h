#ifndef REPO_H
#define REPO_H
#include "Student.h"
using namespace std;
class Repo {
private:
	Student students[10];
	int noStudents;
public:
	Repo();
	//~Repo();
	void addItem(Student& s);
	Student getItemFromPos(int pos);
	Student& operator[](int pos);
	int getSize();
};
#endif
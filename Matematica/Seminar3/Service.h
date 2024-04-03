#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"
class Service
{
private:
	Repo<Student> repo;

public:
	Service();
	vector<Student> getItems();
	vector<Student> filtrare(Student student);
	void adaugare(Student student);
};



#endif


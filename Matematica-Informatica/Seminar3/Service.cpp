#include "Service.h"

Service::Service()
{
	repo = Repo<Student>();
}

vector<Student> Service::getItems()
{
	return this->repo.getItems();
}
vector<Student> Service::filtrare(Student student)
{
	vector<Student> stud;
	for (int i = 0; i < this->repo.getSize(); ++i)
	{
		if (repo[i] == student)
			stud.push_back(repo[i]);
	}

	return stud;
}
void Service::adaugare(Student student)
{
	repo.addItem(student);
}

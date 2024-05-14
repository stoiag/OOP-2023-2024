#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"

template <class T>
class Service
{
private:
	Repo<T> repo;

public:
	vector<T> getItems()
	{
		return this->repo.getItems();
	}

	vector<T> filtrare(T student)
	{
		vector<T> stud;
		for (int i = 0; i < this->repo.getSize(); ++i)
		{
			if (repo[i] == student)
				stud.push_back(repo[i]);
		}

		return stud;
	}

	void adaugare(T student)
	{
		repo.addItem(student);
	}
};



#endif


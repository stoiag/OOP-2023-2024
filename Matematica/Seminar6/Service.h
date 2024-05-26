#pragma once
#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"

template <class T>
class Service {
private:
	Repo<T> repo;

public:
	Service() { }
	Service(const Repo<T>& repo) {
		this->repo = repo;
	}
	~Service() { }

	void addItem(T elem) {
		repo.addItem(elem);
	}

	vector<T> getItems() const {
		return repo.getItems();
	}
	void eliminare(int i) {
		try{
			repo.delete_item(i);
		}
		catch (MyException& exc) {
			throw exc;
		}

	}
	void modificare(int i, T p) {
		try {
			repo.update_item(i, p);
		}
		catch (MyException& exc) {
			throw exc;
		}
	}
};



#endif // !SERVICE_H

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
};



#endif // !SERVICE_H

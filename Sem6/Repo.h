#ifndef REPO_H
#define REPO_H
#include "Exception.h"
#include <vector>
using namespace std;

template <class T> class Repo {
private:
	vector<T> entities;
public:
	Repo();
	~Repo();
	void addItem(T s);
	void delItem(int pos);
	T getItem(int pos);
	int getSize();
	vector<T> getEntities();
};

template <class T> Repo<T>::Repo() {
	this->entities.reserve(10);
}

template <class T> Repo<T>::~Repo() {
	for (int i = 0; i < this->entities.size(); i++)
		delete this->entities[i];
	this->entities.clear();
}

template <class T>
void Repo<T>::addItem(T s) {
	this->entities.push_back(s->clone());
}

template <class T>
void Repo<T>::delItem(int pos) {
	if (pos < 0 || pos  > this->getSize())
		throw Exception("Pozitie invalida\n");

	this->entities.erase(next(this->entities.begin(), pos - 1));
}

template <class T>
T Repo<T>::getItem(int pos) {
	if (pos < 0 || pos  > this->getSize())
		throw Exception("Pozitie invalida\n");
	return this->entities[pos];
}

template <class T>
int Repo<T>::getSize() {
	return (int)this->entities.size();
}

template <class T>
vector<T> Repo<T>::getEntities() {
	return this->entities;
}
#endif
#ifndef REPO_H
#define REPO_H
#include <vector>
using namespace std;

template <class T> class Repo {
private:
	vector<T> entities;
public:
	Repo();
	~Repo();
	void addItem(const T& s);
	T getItem(int pos);
	int getSize();
	vector<T> getEntities();
};

template <class T> Repo<T>::Repo() {
	this->entities.reserve(10);
}

template <class T> Repo<T>::~Repo() {
	this->entities.clear();
}

template <class T>
void Repo<T>::addItem(const T& s) {
	this->entities.push_back(s);
}

template <class T>
T Repo<T>::getItem(int pos) {
	cout << "getItem" << endl;
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
#ifndef REPO_H
#define REPO_H
#include <vector>
#include <fstream>
#include <cstring>
#include "MyException.h"
using namespace std;

template <class T>
class Repo {
private:
	//T sv[10];
	//int noEntities;
	vector<T> v;
public:
	Repo() {
		v.reserve(20);
	}
	~Repo()
	{
		v.clear();
	}
	void addItem(T item) {
		//this->sv[noEntities++] = item;
		this->v.push_back(item->clone());
	}
	T getItemFromPos(int pos) {
		//return this->sv[pos];
		return this->v[pos];
	}

	vector<T> getItems() const
	{
		return this->v;
	}
	T& operator[](int pos) {
		//return this->sv[pos];
		return this->v[pos];
	}
	int getSize();
	/*
	int getSize() {
		return this->v.size();
	}
	*/
	void showAll() {
		typename vector<T>::iterator it;
		for (it = v.begin(); it < v.end(); it++) // v = v[0] - v[1] - v[v.size()-1] - END
			(T(*it))->getDescriere();
	}
	void delete_item(int i) {
		if (v.size() <= i || i < 0)
			throw MyException("Index out of range");
		v.erase(v.begin() + i);

	}
	void update_item(int i, T p) {
		if (v.size() <= i || i < 0)
			throw MyException("Index out of range");
		v[i] = p->clone();
	}
};

template <class T> int Repo<T>::getSize() {
	//return this->noEntities;
	return this->v.size();
}


#endif
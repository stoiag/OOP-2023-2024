#ifndef REPO_H
#define REPO_H
#include "Student.h"
#include <vector>
#include <fstream>
#include <cstring>
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
	void addItem(T& item) {
		//this->sv[noEntities++] = item;
		this->v.push_back(item);
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
	void readfile(const char* filename)
	{
		ifstream fin;
		fin.open(filename);
		char* line = new char[40];
		char* p = NULL;
		while (fin.getline(line, 40))
		{
			char* nume = strtok_s(line, ";", &p);
			char* agestring = strtok_s(NULL, ";", &p);
			int age = atoi(agestring);
			Student student(nume, age);
			addItem(student);
		}
		fin.close();
	}
	void writeFile(const char* filename)
	{
		ofstream fout;
		fout.open(filename);
		vector<Student>::iterator it;
		for (it = v.begin(); it < v.end(); it++)
			fout << *it;
		fout.close();
	}
	void showAll() {
		vector<Student>::iterator it;
		for (it = v.begin(); it < v.end(); it++) // v = v[0] - v[1] - v[v.size()-1] - END
			cout << *it;
	}
};

template <class T> int Repo<T>::getSize() {
	//return this->noEntities;
	return this->v.size();
}

#endif
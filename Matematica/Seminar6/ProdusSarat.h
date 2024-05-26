#pragma once
#include <iostream>
#include "Produs.h"
class ProdusSarat : public Produs {
private:
	float saruri;
public:
	ProdusSarat();
	ProdusSarat(int, const char*, int, float);
	ProdusSarat(const ProdusSarat&);
	Produs* clone();
	~ProdusSarat();
	float getSaruri();
	void setSaruri(float);
	void getDescriere();
	friend std::istream& operator>>(std::istream& is, ProdusSarat& ps);
};

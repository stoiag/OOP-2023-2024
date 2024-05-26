#pragma once
#include <iostream>
#include "Produs.h"
class ProdusDulce : public Produs {
private:
	float zaharuri;
public:
	ProdusDulce();
	ProdusDulce(int, const char*, int, float);
	ProdusDulce(const ProdusDulce&);
	Produs* clone();
	~ProdusDulce();
	float getZaharuri();
	void setZaharuri(float);
	void getDescriere();

	friend std::istream& operator>>(std::istream& is, ProdusDulce& pd);
};

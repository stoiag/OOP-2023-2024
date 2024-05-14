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
	~ProdusSarat();
	float getSaruri();
	void setSaruri(float);
	void getDescriere();
};

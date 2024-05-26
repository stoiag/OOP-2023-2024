#pragma once
#include <iostream>
class Produs {
	protected:
		int pret;
		char* nume;
		int cod;
	public:
		Produs();
		Produs(int, const char*, int);
		Produs(const Produs&);
		virtual ~Produs();
		virtual Produs* clone();
		int getPret();
		char* getNume();
		int getCod();
		void setPret(int);
		void setNume(const char*);
		void setCod(int);
		virtual void getDescriere();
		friend std::istream& operator>>(std::istream& is, Produs& p);
};


#pragma once
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
		int getPret();
		char* getNume();
		int getCod();
		void setPret(int);
		void setNume(const char*);
		void setCod(int);
		virtual void getDescriere();
};


#ifndef SEM1_H
#define SEM1_H
//Prob 1
void read(int& n, int& m);
void print(int n, int m, int max);
int maxim(int n, int m);
void problema1();

//Prob 2
void read2(int& n, int& m, int &p);
void print2(int n, int m, int p, int max);
int maxim2(int n, int m, int p);
void problema2();

//Prob 3
void read3(int& n, int& m, char& op);
void print3(int n, int m, char op, int rez);
int calcul(int n, int m, char op);
void problema3();

//Prob 5
void read5(int& x);
void print5(int x, int res);
void problema5();
bool estePrim(int x);
int primulNumarPrimDupaX(int x);

// Prob 6
void read6(int* &v, int& n);
int countNumbers(int* v, int n, int& poz, int& neg);
void problema6();
#endif
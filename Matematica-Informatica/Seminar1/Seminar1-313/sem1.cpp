#include <iostream>
using namespace std;
//Problema 1
void read(int &n,int &m) {
	cin >> n >> m;
}

void print(int n, int m, int max) {
	cout << "Maximul este " << max;
}

int maxim(int n, int m) {
	int maxx;
	if (n > m)
		maxx = n;
	else maxx = m;
	return maxx;//a > b? a : b
}

void problema1() {
	int n, m, maxx;
	read(n, m);
	maxx = maxim(n, m);
	print(n , m, maxx);
}

//Problema 2
void read2(int& n, int& m, int &p) {
	cin >> n >> m >> p;
}
void print2(int n, int m, int p, int max) {
	cout << "Maximul este " << max;
}
int maxim2(int n, int m, int p) {
	int maxx;
	if (n > m && n > p)
		maxx = n;
	else if (m > p && m > n)
		maxx = m;
	else maxx = p;
	/*
	(n > m && n > p)
		? n
		: (m > p && m > n)
			? m
			: p
	*/
	return maxx;
}
void problema2() {
	int n, m,p, maxx;
	read2(n, m, p);
	maxx = maxim2(n, m, p);
	print2(n, m, p, maxx);
}

int calcul(int a, int b, char op)
{
	int rez;
	switch (op)
	{
	case '+':
		rez = a + b;
		break;
	case '-':
		rez = a - b;
		break;
	case '*':
		rez = a * b;
		break;
	case '/':
		int(b != 0);
		rez = a / b;
		break;
	default:
		rez = -1;
		break;
	}
	return rez;
}
void read3(int& a, int& b, char& op)
{
	cout << "Introduceti numerele: " << endl;
	cin >> a >> b;
	cout << "Introduceti caracterul: " << endl;
	cin >> op;
}
void print3(int a, int b, char op, int rez)
{
	cout << "Rezultatul operatiei " << a << " " << op << " " << b << " " << "este " << rez;
}

void problema3() {
	int a, b, rez;
	char op;
	read3(a, b, op);
	rez = calcul(a, b, op);
	print3(a, b, op, rez);
}

// problema 5
void read5(int& x)
{
	cout << "Introduceti numarul: ";
	cin >> x;
}

void print5(int x, int res)
{
	cout << "Primul numar prim dupa " << x << " este " << res;
}

bool estePrim(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

int primulNumarPrimDupaX(int x)
{
	int numar = x + 1;
	while (true) {
		if (estePrim(numar))
			break;
		++numar;
	}
	return numar;
}

void problema5()
{
	int x, res;
	read5(x);
	res = primulNumarPrimDupaX(x);
	print5(x, res);
}

void read6(int* &v, int &n) {
	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}

void countNumbers(int* v, int n, int &poz, int &neg) {
	poz = neg = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == 0)
			continue;

		if (v[i] > 0)
			poz++;
		else neg++;
	}
}

void problema6() {
	int* v;
	int n;
	int poz, neg;
	read6(v, n);
	countNumbers(v, n, poz, neg);
	cout << poz << " " << neg << " " << n - poz - neg << '\n';
	delete[] v;
}
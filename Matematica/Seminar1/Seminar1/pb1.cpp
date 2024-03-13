#include <iostream>
#include <assert.h>
#include "pb1.h"
using namespace std;

int pb1(int a, int b)
{
	//return (a>b ? a : b);
	if (a > b)
		return a;
	return b;
}

void pb1_citire(int& a, int& b)
{
	cin >> a >> b;
}

void pb1_test()
{
	assert(pb1(10, 2) == 10);
	assert(pb1(3, 15) == 15);
	cout << "testele au rulat cu succes" << endl;

}

int pb2(int a, int b, int c)
{
	/*return (
		a>b
			? a>c
				? a
				: (b>c ? b : c)
			: (b>c ? b : c)
	);*/
	
	if (a > b)
	{
		if (a > c)
			return a;
		else
		{
			if (b > c)
				return b;
			return c;
		}	
	}
		
	else
	{
		if (b > c)
			return b;
		return c;
	}
		
}

void pb2_citire(int& a, int& b, int &c)
{
	cin >> a >> b >> c;
}

void pb2_test()
{
	assert(pb2(10, 2, 7) == 10);
	assert(pb2(3, 15, 8) == 15);
	cout << "testele au rulat cu succes" << endl;
}

void pb3_citire(int& a, int& b, char& op)
{
	cin >> a >> b>>op;

}

int pb3(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/' :
		if (b != 0)
			return a / b;
		else
			return -1;
	default: 
			return 0;
	}
	
}
void pb3_test()
{
	assert(pb3(10, 2, '+' ) == 12);
	assert(pb3(3, 15, '*') == 45);
	assert(pb3(3, 0, '/') == -1);
	cout << "testele au rulat cu succes" << endl;

}

void pb4_citire(int& a)
{
	cin >> a;
}
int pb4(int a)
{
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return i;
	return -1;
}
void pb4_test()
{
	assert(pb4(5) == -1);
	assert(pb4(14) == 2);
	cout << "testele au rulat cu succes" << endl;
}

void pb7_citire(int a[])
{
	for (int i = 0; i < CAP; i++)
	{
		cin >> a[i];
	}
}
void pb7(int a[])
{
	int n = 0, p = 0;
	for (int i = 0; i < CAP; i++)
	{
		if (a[i] == 0) continue;
		if (a[i] > 0) p++;
		if (a[i] < 0) n++;
	}
	cout << p << " " << n << " " << CAP - n - p;
}

void pb7_dinamic_citire(int* a)
{
	for (int i = 0; i < CAP; i++)
	{
		cin >> a[i];
	}
}
void pb7_dinamic(int* a)
{
	int n = 0, p = 0;
	for (int i = 0; i < CAP; i++)
	{
		if (a[i] == 0) continue;
		if (a[i] > 0) p++;
		if (a[i] < 0) n++;
	}
	cout << p << " " << n << " " << CAP - n - p;
}


#define CAP 3
#include <iostream>
using namespace std;

void citire(int** p) {
	for (int i = 0; i < CAP; i++)
		for (int j = 0; j < CAP; j++)
			cin >> p[i][j];
}

int main() {
	cout << CAP << endl;

	//alloc
	int** p = new int*[CAP];
	for (int i = 0; i < CAP; i++) {
		p[i] = new int[CAP];
	}

	citire(p);
	for (int i = 0; i < CAP; i++)
		for (int j = 0; j < CAP; j++)
			cout << *(*(p + i) + j) << p[i][j];

	//dealloc
	for (int i = 0; i < CAP; i++) {
		delete[] p[i];
	}
	delete[] p;
	return 0;
}
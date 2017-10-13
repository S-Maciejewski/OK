#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<random>
#include<fstream>

using namespace std;

class Punkt {
private:
	int x, y;
public:
	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }
	int getX() { return x; }
	int getY() { return y; }
};

Punkt* generateTable(long int size, long int range) {
	Punkt* table = new Punkt[size];
	Punkt point;

	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> distribution(-range, range);
	for (int i = 0; i < size; i++) {
		point.setX(distribution(gen));
		point.setY(distribution(gen));

		table[i] = point;
	}
	return table;
}

void printTable(Punkt tab[], long int size) {
	for (int i = 0; i < size; i++) {
		cout << tab[i].getX() << " " << tab[i].getY() << endl;
	}
}

void writeTableToFile(Punkt tab[], long int size) {
	ofstream out("instancja.txt");
	for (int i = 0; i < size; i++) {
		out << tab[i].getX() << ", " << tab[i].getY() << endl;
	}
}

Punkt* readTable(long int size) {
	Punkt* table = new Punkt[size];
	Punkt point;
	int x, y;
	ifstream in("instancja.txt");
	for (int i = 0; i < size; i++) {
		in >> x >> y;
		point.setX(x);
		point.setY(y);

		table[i] = point;
	}

	return table;
}

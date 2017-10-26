#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<random>
#include<fstream>

using namespace std;

class Punkt {
private:
	long int x, y;
public:
	void setX(long int X) { x = X; }
	void setY(long int Y) { y = Y; }
	long int getX() { return x; }
	long int getY() { return y; }
};

double distance(Punkt point1, Punkt point2) {
	return sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
}

Punkt* generateTable(long int size, long int range) {
	Punkt* table = new Punkt[size];
	Punkt point;

	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> distribution(0, range);
	for (int i = 0; i < size; i++) {
		point.setX(distribution(gen));
		point.setY(distribution(gen));

		table[i] = point;
	}
	return table;
}

void printTable(Punkt tab[], long int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " " << tab[i].getX() << " " << tab[i].getY() << endl;
	}
}

void writeTableToFile(Punkt tab[], string fileName, long int size) {
	ofstream out(fileName);
	out << size << endl;
	for (int i = 0; i < size; i++) {
		out << i + 1 << " " << tab[i].getX() << " " << tab[i].getY() << endl;
	}
}

long int getInstanceSize(string fileName) {
	long int size;

	ifstream in(fileName);
	in >> size;

	return size;
}

Punkt* readTable(string fileName, long int size) {
	int x, y, numer;
	ifstream in(fileName);

	Punkt* table = new Punkt[size];
	Punkt point;

	for (int i = 0; i < size; i++) {
		in >> numer >> x >> y;
		//in >> x >> y;		//dla odczytu b³êdnej instancji ze strony
		point.setX(x);
		point.setY(y);

		table[i] = point;
	}

	return table;
}

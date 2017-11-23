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
	long int randX, randY;
	int generated = 0;
	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> distribution(0, range);
	for (int i = 0; i < size; i++) {
		randX = distribution(gen);
		randY = distribution(gen);
		
		for (int j = 0; j < generated; j++) {
			if (randX == table[j].getX() && randY == table[j].getY()) {
				i--;
				continue;
			}
		}

		point.setX(distribution(gen));
		point.setY(distribution(gen));

		table[i] = point;
		generated++;
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

	long int size;
	in >> size;
	Punkt* table = new Punkt[size];
	Punkt point;

	for (int i = 0; i < size; i++) {
		in >> numer >> x >> y;
		point.setX(x);
		point.setY(y);

		table[i] = point;
	}

	return table;
}

#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<random>
#include "generator.h"

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
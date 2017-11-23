#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "instance.h"
#include <fstream>

using namespace std;

double greed(Punkt tab[], long int size) {
	double dist = 0, minDist;
	long int position = 0, closestPos;
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) visited[i] = false;

	visited[0] = true;
	
	cout << "Droga: ";

	for (int i = 0; i < size; i++) {
		minDist = DBL_MAX;
		cout << position <<", ";

		for (int j = 0; j < size; j++) {
			if (!visited[j]) {
				if (minDist > distance(tab[position], tab[j])) {
					closestPos = j;
					minDist = distance(tab[position], tab[j]);
				}
			}
		}

		if (i != size - 1) {
			dist += minDist;
		}
		visited[closestPos] = true;
		position = closestPos;
	}
	dist += distance(tab[position], tab[0]);
	
	return dist;
}

int main()
{
	long int size = 52, range = 1000;
	string fileName = "berlin52.txt";

	Punkt* table = readTable(fileName, size);
	printTable(table, size);
	
	cout << "Greed distance: " << greed(table, size) << endl;

    return 0;
}


#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "instance.h"

using namespace std;

double greed(Punkt tab[], long int size) {
	double dist = 0, minDist = 0;
	long int position = 0, closestPos;
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) visited[i] = false;

	visited[0] = true;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			if (!visited[j]) {
				minDist = distance(tab[position], tab[j]);
				closestPos = j;
			}

		for (int j = 0; j < size - i; j++) {
			if (j != position)
				if (distance(tab[position], tab[j]) < minDist) {
					minDist = distance(tab[position], tab[j]);
					closestPos = j;
				}
		}
		dist += minDist;
		visited[closestPos] = true;
		position = closestPos;

		if (i == size - 1)
			dist += distance(tab[position], tab[0]);
	}
	
	return dist;
}

int main()
{
	long int size = 100, range = 1000;
	Punkt* table = generateTable(size, range);
	printTable(table, size);
	
	cout << "Greed distance: " << greed(table, size) << endl;



    return 0;
}


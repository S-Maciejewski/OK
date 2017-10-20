//#pragma once

//#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<random>


using namespace std;

class Punkt {
private:
	long int x, y;
public:
	void setX(long int X);
	void setY(long int Y);
	long int getX();
	long int getY();
};

double distance(Punkt point1, Punkt point2);

Punkt* generateTable(long int size, long int range);

void printTable(Punkt tab[], long int size);

void writeTableToFile(Punkt tab[], long int size);

Punkt* readTable(long int size);
#pragma once

#include<cstdlib>
#include<iostream>
#include<random>
#include<fstream>


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

void writeTableToFile(Punkt tab[], string fileName, long int size);

long int getInstanceSize(string fileName);

Punkt* readTable(string fileName, long int size);
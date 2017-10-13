#pragma once

#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<random>

using namespace std;

class Punkt {
private:
	int x, y;
public:
	void setX(int X);
	void setY(int Y);
	int getX();
	int getY();
};

Punkt* generateTable(long int size, long int range);

void printTable(Punkt tab[], long int size);

void writeTableToFile(Punkt tab[], long int size);

Punkt* readTable(long int size);
#pragma once

#include<cstdlib>
#include<iostream>
#include<random>
#include<fstream>

using namespace std;

class Punkt {
private:
	long int x, y;
    bool visited;
public:
	void setX(long int X);
	void setY(long int Y);
    void setNumber(int Number);
    void setVisited(bool Z);
    bool isVisited();
	long int getX();
	long int getY();
    int getNumber();
};

class Edge {
private:
    Punkt begin, end;
    double length;
public:
    void setBegin(Punkt X);
    void setEnd(Punkt Y);
    void setLength(double Length);
    Punkt getBegin();
    Punkt getEnd();
    double getLength();
};

double distance(Punkt point1, Punkt point2);

Punkt* generateTable(long int size, long int range);

void printTable(Punkt tab[], long int size);

void printRoute(long int route[], long int size);

void printEdges(Edge edge[], long int size);

void writeTableToFile(Punkt tab[], string fileName, long int size);

long int getInstanceSize(string fileName);

<<<<<<< HEAD
Punkt* readTable(string fileName, long int size);
=======
void readTable(string fileName, Punkt* table);

void makeEdges(Edge* edges, long int route[], Punkt table[], long int size);

void swapEdges(Edge* edge, double bb, double ee, int begin, int end, Edge& temp);

double generateRoute(Punkt tab[], long int* route, long int size, bool printPath);
>>>>>>> ede0e9ce3ee051e66ae6e319d125bf189a4e992b

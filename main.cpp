#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include "instance.h"
#include <fstream>
#include <cfloat>

using namespace std;

double greed(Punkt tab[], long int* route, long int size, long int const startPosition, bool printPath) {

	double dist = 0, minDist;
	long int position = startPosition, closestPos;

	for (int i = 0; i < size; i++) tab[i].setVisited(false);

	tab[startPosition].setVisited(true);

    if(printPath) {
        cout << "Droga: ";
        cout << startPosition << " --> ";
    }

    route[0] = startPosition;

	for (int i = 0; i < size - 1; i++) {
		minDist = DBL_MAX;

		for (int j = 0; j < size; j++) {
			if (!tab[j].isVisited()) {
				if (minDist > distance(tab[position], tab[j])) {
					closestPos = j;
					minDist = distance(tab[position], tab[j]);
				}
			}
		}
        dist += minDist;
		tab[closestPos].setVisited(true);

		position = closestPos;
        if(printPath) cout << position <<" --> ";
        route[i+1] = position;
	}
	dist += distance(tab[position], tab[startPosition]);
    if(printPath) cout << startPosition <<endl;
    route[size] = startPosition;
	
	return dist;
}

void opt2(Edge edge[], long int size, long int route[], double& currentDistance) {

    double bbEdge, eeEdge, difference; //begin-begin edge & end-end edge
    Edge temp;
    bool change;

    while(true) {
        change = false;
        for (int j = 0; j <= size - 3; j++) {
            for (int k = j + 2; k < size && k!=j+size-1; k++) {

                bbEdge = distance(edge[j].getBegin(), edge[k].getBegin());
                eeEdge = distance(edge[j].getEnd(), edge[k].getEnd());
                difference = edge[j].getLength() + edge[k].getLength() - bbEdge - eeEdge;

                if (difference > 0) {
                    change = true;
                    //cout<<"Swapping : " << j<<" "<<k<<endl;
                    swapEdges(edge, bbEdge, eeEdge, j, k, temp);
                }
            }
        }
        if(!change) break;
    }
    currentDistance=0;
    for(int i=0; i<size; i++) {
        currentDistance += edge[i].getLength();
    }
}

int main()
{
    bool printEveryPath = false;
    string fileName = "/home/jan/CLionProjects/OK/inst.txt";

	long int size = getInstanceSize(fileName), range = 1000;
    Punkt* table = new Punkt[size];
    Edge* edge = new Edge[size];

    long int* route = new long int[size+1];
    double bestGreedEver = DBL_MAX, greedDist, randomDist;

	readTable(fileName, table);
	//printTable(table, size);

    //GREED + 2-OPT
    
    for(int i=0; i<size; i++) {
        cout<<endl<<"###############################################" <<endl;

        greedDist = greed(table, route, size, i, printEveryPath);
        cout<<endl<<"Current greed distance: " << greedDist << endl;
        //printRoute(route, size);

        makeEdges(edge, route, table, size);
        //printEdges(edge, size);

        opt2(edge, size, route, greedDist);
        //printEdges(edge, size);
        cout << "2-Opt result : " << greedDist << endl;
        if(greedDist < bestGreedEver) bestGreedEver = greedDist;
    }

    cout<<endl<<"###############################################" <<endl;

    cout<<endl<<"BEST RESULT BY GREED: " << bestGreedEver <<endl;

    //RANDOM + 2-OPT
    
    while(true) {

        //cout << endl << "###############################################" << endl;

        randomDist = generateRoute(table, route, size, printEveryPath);
        //cout << endl << "Current random distance: " << randomDist << endl << endl;
        //printRoute(route, size);

        makeEdges(edge, route, table, size);
        //printEdges(edge, size);

        opt2(edge, size, route, randomDist);
        //printEdges(edge, size);
        //cout << "2-Opt result : " << randomDist << endl;
        if (randomDist < bestGreedEver) {
            bestGreedEver = randomDist;
            cout<<endl<<"###############################################" <<endl;
            cout<<endl<<"BEST RESULT BY RANDOM: " << bestGreedEver <<endl;
            printEdges(edge, size);
        }
    }

    return 0;
}


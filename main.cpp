#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "instance.h"


using namespace std;

int main()
{
	Punkt* table = generateTable(100, 1000);
	writeTableToFile(table, 100);
	readTable(100);
	printTable(table, 100);
	

    return 0;
}


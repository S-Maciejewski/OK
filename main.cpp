#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "generator.h"

using namespace std;

int main()
{
	Punkt* table = generateTable(100, 1000);
	printTable(table, 100);
	writeTableToFile(table, 100);

    return 0;
}


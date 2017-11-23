#include<cstdlib>
#include<iostream>
#include<random>
#include<fstream>

using namespace std;

class Punkt {
private:
	long int x, y;
	bool visited;
	int number;
public:
	void setX(long int X) { x = X; }
	void setY(long int Y) { y = Y; }
	void setNumber(int Number) { number = Number; }
	void setVisited(bool V) { visited = V; }
	bool isVisited() { return visited; }
	long int getX() { return x; }
	long int getY() { return y; }
	int getNumber() { return number; }
};

class Edge {
private:
	Punkt begin, end;
	double length;
public:
	void setBegin(Punkt Begin) { begin = Begin; }
	void setEnd(Punkt End) { end = End; }
	void setLength(double Length) { length = Length; }
	Punkt getBegin() { return begin; }
	Punkt getEnd() { return end; }
	double getLength() { return length; }
};

double distance(Punkt point1, Punkt point2) {
	return sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
}

void generateTable(Punkt* table, long int size, long int range) {

	Punkt point;
	long int randX, randY;
	int generated = 0;
	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> distribution(0, range);

	for (int i = 0; i < size; i++) {
		randX = distribution(gen);
		randY = distribution(gen);

		for (int j = 0; j < generated; j++) {
			if (randX == table[j].getX() && randY == table[j].getY()) {
				i--;
				continue;
			}
		}

		point.setX(distribution(gen));
		point.setY(distribution(gen));
		point.setNumber(i);
		point.setVisited(false);

		table[i] = point;
		generated++;
	}
}

void printTable(Punkt tab[], long int size) {
	for (int i = 0; i < size; i++) {
		cout << tab[i].getNumber() << " " << tab[i].getX() << " " << tab[i].getY() << " " << tab[i].isVisited() << endl;
	}
}

void printRoute(long int route[], long int size) {
	cout << "Route : ";
	for (int i = 0; i <= size; i++) {
		cout << route[i] << " ";
	}
	cout<<endl<<endl;
}

void printEdges(Edge edge[], long int size) {
	cout << endl<< "Final edges : " << endl;
	for (int i = 0; i < size; i++) {
		cout << i<<" :   " << edge[i].getBegin().getNumber() <<"(" << edge[i].getBegin().getX() << "," << edge[i].getBegin().getY() << ")" << " --> " << edge[i].getEnd().getNumber() <<"(" << edge[i].getEnd().getX() << "," << edge[i].getEnd().getY() << ")" << "    " << edge[i].getLength()<<endl;
	}
	cout<<endl;
}

void writeTableToFile(Punkt tab[], string fileName, long int size) {
	ofstream out(fileName);
	out << size << endl;
	for (int i = 0; i < size; i++) {
		out << i + 1 << " " << tab[i].getX() << " " << tab[i].getY() << endl;
	}
}

long int getInstanceSize(string fileName) {
	long int size;

	ifstream in(fileName);
	in >> size;

	return size;
}

void readTable(string fileName, Punkt* table) {
	ifstream in(fileName);
	long int size;
	in >> size;
	int x, y, numer;
	Punkt point;

	for (int i = 0; i < size; i++) {
		in >> numer >> x >> y;
		point.setX(x);
		point.setY(y);
		point.setVisited(false);
		point.setNumber(i);

		table[i] = point;
	}
}

void makeEdges(Edge* edge, long int route[], Punkt table[], long int size) {
	double dist;
	for(int i=0; i<size; i++) {
		edge[i].setBegin(table[route[i]]);
		edge[i].setEnd(table[route[i+1]]);
		edge[i].getLength(); // wuuuuut... nie wiem dlaczego, ale bez tego nie dziala
		edge[i].setLength(distance(edge[i].getBegin(), edge[i].getEnd()));
	}
}

void swapEdges(Edge* edge, double bb, double ee, int begin, int end, Edge& temp) {

	// przełączenie krawędzi
	temp.setEnd(edge[begin].getEnd());

	edge[begin].setEnd(edge[end].getBegin());
	edge[end].setBegin(temp.getEnd());

	edge[begin].setLength(bb);
	edge[end].setLength(ee);

	//odwracanie pozostałych krawędzi
	for (int i = begin + 1; i < end; i++) {
		temp.setBegin(edge[i].getBegin());

		edge[i].setBegin( edge[i].getEnd() );
		edge[i].setEnd(temp.getBegin());
	}

	//odwracanie kolejności pozostałych krawędzi
	for (int i = end - 2;  i>begin; i--) {
		for( int l = begin + 1; l <= i; l++) {

			temp.setBegin(edge[l].getBegin());
			temp.setEnd(edge[l].getEnd());
			temp.setLength(edge[l].getLength());

			edge[l].setBegin(edge[l+1].getBegin());
			edge[l].setEnd(edge[l+1].getEnd());
			edge[l].setLength(edge[l+1].getLength());

			edge[l+1].setBegin(temp.getBegin());
			edge[l+1].setEnd(temp.getEnd());
			edge[l+1].setLength(temp.getLength());
		}
	}




}

double generateRoute(Punkt tab[], long int* route, long int size, bool printPath) {

	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> distribution(0, size-1);

	long int startPosition, currentPosition;
	double dist = 0;
	int randPoint;

	for (int i = 0; i < size; i++) tab[i].setVisited(false);

	startPosition = distribution(gen);
	tab[startPosition].setVisited(true);

	if(printPath) cout << endl<< "Droga: " << startPosition << " --> ";
	route[0] = startPosition;

	for (int i = 0; i < size - 2; i++) {

		do {
			randPoint = distribution(gen);
		} while(tab[randPoint].isVisited() != false);

		dist += distance(tab[currentPosition], tab[randPoint]);
		tab[randPoint].setVisited(true);
		currentPosition = randPoint;
		if(printPath) cout << currentPosition <<" --> ";
		route[i+1] = currentPosition;
	}

	int lastPoint;
	for(int i=0; i<size; i++) {
		if(tab[i].isVisited() == false) lastPoint = i;
	}
	dist += distance(tab[currentPosition], tab[lastPoint]);
	tab[lastPoint].setVisited(true);
	route[size-1] = lastPoint;
	if(printPath) cout << lastPoint <<" --> ";

	dist += distance(tab[lastPoint], tab[startPosition]);
	if(printPath) cout << startPosition <<endl;
	route[size] = startPosition;

	return dist;
}



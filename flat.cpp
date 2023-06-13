#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Overcoat {
	char* cloth;
	int cost;
public:
	Overcoat(const char* ucloth, int ucost) {
		cloth = new char[strlen(ucloth) + 1];
		cost = ucost;
	}

	friend bool operator>(const Overcoat& o1, const Overcoat& o2);

	friend bool operator==(const Overcoat& o1, const Overcoat& o2);

	~Overcoat() {
		if (cloth) {
			delete[] cloth;
		}
	}
};

bool operator==(const Overcoat& o1, const Overcoat& o2) {
	return (strcmp(o1.cloth, o2.cloth) == 0);
}

bool operator>(const Overcoat& o1, const Overcoat& o2) {
	return (o1.cost > o2.cost);
}

class Flat {
	int S;
	int cost;
public:
	Flat(int us, int ucost) {
		S = us;
		cost = ucost;
	}

	friend bool operator==(const Flat& f1, const Flat& f2);
	friend bool operator>(const Flat& f1, const Flat& f2);
};

bool operator==(const Flat& f1, const Flat& f2) {
	return (f1.S == f2.S);
}
bool operator!=(const Flat& f1, const Flat& f2) {
	return !(f1 == f2);
}
bool operator>(const Flat& f1, const Flat& f2) {
	return (f1.cost > f2.cost);
}
bool operator<(const Flat& f1, const Flat& f2) {
	return !(f1 > f2);
}

int main() {
	Overcoat a{"Брюки", 2000};
	Overcoat b{ "Брюки", 3000 };

	cout << "A == B: " << (a == b) << endl;
	cout << "A > B: " << (a > b) << endl;

	cout << endl;

	Flat f1{ 20000,5000000 };
	Flat f2{ 20000,10000000 };

	cout << "F1 == F2: " << (f1 == f2) << endl;
	cout << "F1 > F2: " << (f1 > f2) << endl;
}

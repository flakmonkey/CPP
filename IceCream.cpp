//============================================================================
// Name        : IceCream.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printMenu();
int numbOfCones();
int numbOfScoops();
double conePrice(int scoopCount);
char* chooseFlavors(int scoopCount);
void printCone(char flavors[], int scoopCount);

const int MAXCONES = 10;
const int MAXSCOOPS = 5;
int coneCount;
int scoopCount;
char* flavors;
double purchasePrice = 0;

int main() {
	printMenu();
	coneCount = numbOfCones();
	for(int i=0; i<coneCount; i++) {
		scoopCount = numbOfScoops();
		purchasePrice += conePrice(scoopCount);
		flavors = chooseFlavors(scoopCount);
		printCone(flavors, scoopCount);
	}
	cout << "Total price: $" << purchasePrice << endl;
	return 0;
}

void printMenu() {
	cout << "*********************" << endl;
	cout << "Brett's Frozen Treats" << endl;
	cout << "*********************" << endl;
	cout << "1 scoop ->\t$2.00" << endl;
	cout << "2 scoops ->\t$3.00" << endl;
	cout << "Extra scoops ->\t$0.75" << endl;
	cout << "Ice Cream Flavors: Only one input character for each flavor." << endl;
}

int numbOfCones() {
	int coneCount = 0;
	while(coneCount <= 0 or coneCount > 10) {
		cout << "How many cones would you like to purchase? (10 max)" << endl;
		cout << ">> ";
		cin >> coneCount;
	}
	return coneCount;
}

int numbOfScoops() {
	int scoopCount = 0;
	while(scoopCount <= 0 or scoopCount > 5) {
		cout << "How many scoops for cone? (5 max)" << endl;
		cout << ">> ";
		cin >> scoopCount;
	}
	return scoopCount;
}

double conePrice(int scoopCount) {
	double price;
	switch(scoopCount) {
	case 1:
		price = 2;
		break;
	case 2:
		price = 3;
		break;
	default:
		price = 3 + (scoopCount-2)*0.75;
		break;
	}
	return price;
}

char* chooseFlavors(int scoopCount) {
	char flavors[5];
	for(int i=0; i<scoopCount; i++) {
		cout << "Specify the flavor for scoop " << i+1 << endl;
		cout << ">> ";
		cin  >> flavors[i];
	}
	return flavors;
}

void printCone(char flavors[], int scoopCount) {
	for(int i=0; i<scoopCount; i++) {
		cout << "(" << flavors[i] << ")" << endl;
	}
	cout << "\\ /" << endl;
	cout << " |" << endl;
}


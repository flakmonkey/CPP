//============================================================================
// Name        : METS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



int activity;
double weight, minutes;
const int SLEEPING = 1;
const int WALKING = 2;
const int BASKETBALL = 8;

int main() {
	cout << "1. Sleeping\n2. Walking\n3. Basketball" << endl;
	cout << ">> ";
	cin >> activity;
	cout << "User weight in pounds: ";
	cin >> weight;
	weight /= 2.2; // convert from lbs to kg
	cout << "User activity duration: ";
	cin >> minutes;

	cout << "You have burned ";
	switch(activity) {
	case 1:
		 cout << (0.0175 * SLEEPING * weight) * minutes;
		break;
	case 2:
		cout << (0.0175 * WALKING * weight) * minutes;
		break;
	case 3:
		cout << (0.0175 * BASKETBALL * weight) * minutes;
		break;
	default:
		break;
	}
	cout << " calories!";
	return 0;
}

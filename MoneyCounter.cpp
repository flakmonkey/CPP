//============================================================================
// Name        : MoneyCounter.cpp
// Author      : Brett Bailey
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Counter {
public:
	Counter() {
		value = 0;
		maxVal = 9999;
		overCapacity = false;
	}
	Counter(int newMax) {
		value = 0;
		maxVal = newMax;
		overCapacity = false;
	}
	void printVal() {
		cout << "Current value of the counter is " << value << endl;
	}
	void getInput() {
		string input;
		cin >> input;

		if(getValueFromInput(input)) {
			cout << "Input not understood";
		}
	}
	bool isOverCapacity() {
		return overCapacity;
	}
	int getMaxVal(){
		return maxVal;
	}

private:
	int value;
	int maxVal;
	int overCapacity;

	void reset() {
			value = 0;
	}
	void inc1(int qty) {
		value += qty;
	}
	void inc10(int qty) {
		value += 10 * qty;
	}
	void inc100(int qty) {
		value += 100 * qty;
	}
	void inc1000(int qty) {
		value += 1000 * qty;
	}
	bool overflow() {
		if(value > maxVal) {
			cout << "You have gone over the amount." << endl;
			overCapacity = true;
			return true;
		}
		else
			cout << "There is no overflow." << endl;
			return false;
	}
	int getValueFromInput(string input) {
		int multi = 0;

		if(input.length() > 1)
			multi = atoi(&input[1]);

		switch(input[0]) {
		case 'a':
			inc1(multi);
			break;
		case 's':
			inc10(multi);
			break;
		case 'd':
			inc100(multi);
			break;
		case 'f':
			inc1000(multi);
			break;
		case 'o':
			if(overflow())
				reset();
			break;
		default:
			return 1;
		}
		return 0;
	}
};

void printMenu(Counter);

int main() {
	Counter count;
	printMenu(count);
	cout << "Enter a key, either a, s, d, f, followed by 1-9." << endl;
	cout << "a -> cents, s -> dimes, d -> dollars, f -> tens of dollars." << endl;

	bool done = false;
	while(!done) {
		while(!count.isOverCapacity()) {
			count.getInput();
		}
		int newMax;
		cout << "Please enter an integer amount less than 9999 to initialize the counter." << endl;
		cin >> newMax;
		count = Counter(newMax);
		printMenu(count);
	}

	count.printVal();
	return 0;
}

void printMenu(Counter count) {
	cout << "Maximum value for the counter is " << count.getMaxVal() << endl;
	count.printVal();
}

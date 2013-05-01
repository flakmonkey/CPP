//============================================================================
// Name        : NewRedGreenYellow.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

class RandomSeq {
private:
	enum {
		RED, GREEN, YELLOW
	};
	vector<int> seq;
	vector<int> guess;
	int result[3];

	void setRandomSeq(int length) {
		int baseRand = getRandomNumber(length);
		intToVec(seq, baseRand);
	}

	int getRandomNumber(int length) {
		srand((unsigned int) time(0));
		int max = (int) pow(10, length) - 100;
		int min = (int) pow(10, length - 1);
		int num = (rand() % max) + min;
		return num;
	}

	int findGreens(vector<int>& seq) {
		int greenCount = 0;
		for (int i = 0; i < (int) guess.size(); i++) {
			if (seq[i] == guess[i]) {
				greenCount++;
				guess.erase(guess.begin() + i);
				seq.erase(seq.begin() + i);
				i--; //move index back because we have erased an entry
			}
		}
		return greenCount;
	}

	int findYellows(vector<int>& seq) {
		int yellowCount = 0;
		for (int i = 0; i < (int) guess.size(); i++) {
			for (int j = 0; j < (int) seq.size(); j++) {
				if (guess[i] == seq[j]) {
					yellowCount++;
					guess.erase(guess.begin() + i);
					seq.erase(seq.begin() + j);
					i--; j--; //move index back because we have erased an entry
					break;
				}
			}
		}
		return yellowCount;
	}

	void intToVec(vector<int>& vec, int num) {
		vec.erase(vec.begin(), vec.end());
		int length = floor(log10(abs(num))) + 1;
		int curDigit;
		for (int i = 0; i < length; i++) {
			curDigit = (int) (num / pow(10, i)) % 10;
			vec.push_back(curDigit);
		}
	}

	void clearInstanceVars() {
		for (int i = 0; i < 3; i++) {
			result[i] = 0;
		}
		guess.erase(guess.begin(), guess.end());
	}

public:
	RandomSeq(int length) {
		setRandomSeq(length);
	}

	bool evaluateGuess(int num) {
		// makes sure result array and guess vector are empty.
		clearInstanceVars();
		//copies the guess number into the instance var guess
		intToVec(guess, num);
		//maximum number of green entries possible
		int greenMax = guess.size();

		/* in this version of the red-green-yellow game, entries cannot be
		 * counted twice. i.e.
		 * 	if
		 *  	a guessed digit n is green
		 *  	AND n is unique in the random sequence
		 *  then
		 *  	another guessed digit with the same value n must be red
		 *  Other versions of this game would have the second digit assigned
		 *  the color yellow, since it exists within the random sequence
		 *
		 *  So, matched entries are removed from their respective arrays
		 *  this prevents double counting, but requires a copy of the
		 *  random sequence array, since that array persists between guesses
		 */
		vector<int> temp = seq;
		//find matching colors
		//digits that have been assigned a color are removed
		result[GREEN] = findGreens(temp);
		result[YELLOW] = findYellows(temp);
		//# digits not matched is calculated. These are red values.
		result[RED] = greenMax - (result[GREEN] + result[YELLOW]);

		if (result[GREEN] == greenMax) {
			cout << "CONGRATULATIONS, YOU ARE CORRECT!!!!!!!!!!!!!!!";
			return true;
		} else {
			printResult();
			return false;
		}
	}

	void printResult() {
		cout << "You have: ";
		string indexToColor[] = { "red", "green", "yellow" };
		for (int i = 0; i < 3; i++) {
			cout << result[i] << " " << indexToColor[i] << endl;
		}
		cout << endl;
	}

	void printSeq() {
		for (int i = ((int) seq.size() - 1); i >= 0; i--)
			cout << seq[i];
		cout << endl;
	}

	void printGuess() {
		for (int i = ((int) guess.size() - 1); i >= 0; i--)
			cout << guess[i];
		cout << endl;
	}
};

int main() {
	RandomSeq rand(3);
	bool done = false;
	do {
		int guess;
		cin >> guess;
		done = rand.evaluateGuess(guess);
	} while (!done);

	return 0;
}

//============================================================================
// Name        : MagicSquare.cpp
// Author      : Brett Bailey
// Description : Creates an NxN matrix of unique integers
//				 from 1 to n**2 where the sum of the integers
//				 in every row, column, and on both diagonals
//				 is the same.
//============================================================================

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class MagicSquare {
private:
	vector< vector<int> > square;

public:
	MagicSquare() {}

	void display() {
		for(int i=0; i<(int)square.size(); i++) {
			for(int j=0; j<(int)square.at(i).size(); j++)
				cout << square.at(i).at(j) << "\t";
			cout << endl;
		}
		cout << endl;
	}

	void magic(int n) {
		if(n%2 != 0){
			square = buildEmptyMatrix(n);
			fillMatrix(n);
		}
	}

	vector< vector<int> > buildEmptyMatrix(int n) {
		vector< vector<int> > square;
		for (int i = 0; i < n; i++) {
		    vector<int> row(n,0); // Create an empty row
		    square.push_back(row); // Add the row to the main vector
		}
		return square;
	}


	void fillMatrix(int n) {
		//start off in the middle of the first column
		int count = 1;
		int i = 0;
		int j = n/2;

		while(count<=pow(n,2)) {
			if ((i < 0) && (j >= n)) {
				i = 1;
				j = n-1;
			}
			else if(i < 0)
				i = n-1;
			else if(j == n)
				j = 0;
			else if(square.at(i).at(j) != 0) {
				i += 2;
				j -= 1;
			}
			square.at(i).at(j) = count++;
			//move
			i -= 1;
			j += 1;
		}
	}
};

int main() {
	MagicSquare square;
	square.magic(5);
	square.display();
	square.magic(15);
	square.display();
	return 0;
}

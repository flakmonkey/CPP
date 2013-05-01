// Hand.h

#ifndef HAND_H_
#define HAND_H_

#include <set>
#include <vector>
#include <algorithm>
#include "Card.h"

struct CompareCardPtr: public std::binary_function<Card*, Card*, bool> {
	bool operator()(Card* c1, Card* c2) const {
		return (*c1) > (*c2);
	}
};

class Hand {
private:
	set<Card*, CompareCardPtr> hand;
	int maxOccurences(vector<int>*);
	vector<int>* histogram();
	void setHandType();
public:
	friend ostream& operator<<(ostream& output, const Hand& h);
	friend bool operator==(Hand h1, Hand h2);

	enum HandType {
		HIGHCARD,
		TWOOFAKIND,
		TWOPAIR,
		THREEOFAKIND,
		STRAIGHT,
		FLUSH,
		FULLHOUSE,
		FOUROFAKIND,
		STRAIGHTFLUSH,
		ROYALFLUSH
	};

	HandType type;

	Hand();

	int compare(Hand);
	int compareByValue(Hand);
	Card* insert(Card*);
	bool isRoyalFlush();
	bool isStraightFlush();
	bool isFullHouse();
	bool isFlush();
	bool isStraight();
	bool isTwoPair();
	set<Card*, CompareCardPtr> ofAKind();
	set<Card*, CompareCardPtr> ofAKind(int);
	set<Card*, CompareCardPtr> getHand();
	int size();
	void print();
};

#endif /* HAND_H_ */

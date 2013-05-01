// Card.h

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

#define SUITSIZE 4
#define VALUESIZE 13

class Card {
	friend ostream& operator<<(ostream& output, const Card& c);
	friend bool operator>(Card c1, Card c2);
	friend bool operator<(Card c1, Card c2);
	friend bool operator>=(Card c1, Card c2);
	friend bool operator<=(Card c1, Card c2);
	friend bool operator==(Card c1, Card c2);
public:
	static string const SuitString[SUITSIZE];
	static string const ValueString[VALUESIZE];

	enum Suit {
		DIAMOND, CLUB, HEART, SPADE
	};
	enum Value {
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
	};
	Suit suit;
	Value value;

	Card(int, int);
};

#endif /* CARD_H_ */

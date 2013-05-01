// Card.cpp

#include "Card.h"


const string Card::SuitString[SUITSIZE] = { "Diamonds", "Hearts", "Clubs", "Spades" };
const string Card::ValueString[VALUESIZE] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

ostream& operator<<(ostream& output, const Card& c) {
	output << Card::SuitString[c.suit] << " : " << Card::ValueString[c.value];
	return output;
}

bool operator>(Card c1, Card c2) {
	if (c1.value > c2.value)
		return true;
	else if (c1.value == c2.value) {
		if (c1.suit > c2.suit)
			return true;
	}
	return false;
}

bool operator<(Card c1, Card c2) {
	if (c1.value < c2.value)
		return true;
	else if (c1.value == c2.value) {
		if (c1.suit < c2.suit)
			return true;
	}
	return false;
}

bool operator>=(Card c1, Card c2) {
	bool cond = c1.value >= c2.value ? true : false;
	return cond;
}

bool operator<=(Card c1, Card c2) {
	bool cond = c1.value <= c2.value ? true : false;
	return cond;
}

bool operator==(Card c1, Card c2) {
	return (c1.value == c2.value);
}

Card::Card(int suit, int value) {
	if (suit >= 0 && suit <= SUITSIZE && value >= 0 && value <= VALUESIZE) {
		this->suit = (Suit)suit;
		this->value = (Value)value;
	} else
		throw;
}


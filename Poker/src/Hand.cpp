// Hand.cpp

#include "Hand.h"
/*
bool operator<(Hand h1, Hand h2) {
	int cmpVal;
	int h1Val;
	int h2Val;
	if (h1.type < h2.type) {
		return true;
	} else if (h1.type == h2.type) {
		switch (h1.type) {

		case 6: // full house
			//see which three of a kind is higher
			// if equal
			//  see which two of a kind is higher
			break;
		case 3: // three of a kind
		case 2: // two pair
			h1Val = (*h1.ofAKind().begin())->value;
			h2Val = (*h2.ofAKind().begin())->value;
			if (h1Val > h2Val)
				return true;
			break;
		case 1: // two of a kind

		case 9: // royal flush
		case 8: // straight flush
		case 7: // four of a kind
		case 5: // flush
		case 4: // straight
		case 0: // high card
			cmpVal = h1.compareByValue(h2);
			if (cmpVal > 0)
				return true;
			break;
		default:
			break;
		}
	} else
		return false;

}
*/

bool operator==(Hand h1, Hand h2) {
	set<Card*, CompareCardPtr> set1 = h1.getHand();
	set<Card*, CompareCardPtr> set2 = h2.getHand();
	set<Card*>::iterator cur1 = set1.begin();
	set<Card*>::iterator cur2 = set2.begin();
	while ((**cur1) == (**cur2)) {
		cur1++;
		cur2++;
		if (cur1 == set1.end() || cur2 == set2.end())
			break;
	}
	if (cur1 == set1.end() || cur2 == set2.end())
		return true;
	else
		return false;
}

Hand::Hand() {
	type = HIGHCARD;
}

int Hand::compare(Hand cmp) {
	setHandType();
	cmp.setHandType();
	if(type > cmp.type)
		return 1;
	else if(type == cmp.type) {
		//call fancy switch to decide what to do
		//return result of switch
		return 0;
	}
	else
		return -1;
}

int Hand::compareByValue(Hand cmp) {
	set<Card*, CompareCardPtr> hand2 = cmp.getHand();
	set<Card*>::iterator cur = hand.begin();
	set<Card*>::iterator cur2 = hand2.begin();
	while ((**cur) == (**cur2)) {
		cur++;
		cur2++;
		if (cur == hand.end() || cur2 == hand2.end())
			break;
	}
	if (cur == hand.end() || cur2 == hand2.end())
		return 0;
	else if ((*cur) > (*cur2))
		return 1;
	else
		return -1;
}

Card* Hand::insert(Card* card) {
	if (hand.size() < 5) {
		if (hand.insert(card).second)
			return card;
	} else if (hand.size() == 5) {
		setHandType();
		if (hand.insert(card).second)
			return card;
	}
	return NULL;
}

vector<int>* Hand::histogram() {
	//histogram of value occurrences
	vector<int>* hist = new vector<int>;
	for (int i = 0; i < VALUESIZE; i++)
		hist->push_back(0);
	for (set<Card*>::iterator itr = hand.begin(); itr != hand.end();) {
		int val = (*itr)->value;
		hist->at(val) += 1;
		itr++;
	}
	return hist;
}

int Hand::maxOccurences(vector<int>* hist) {
	//find item with most occurrences
	int max = 0;
	for (int i = 0; i < VALUESIZE; i++) {
		if (hist->at(i) > max) {
			max = hist->at(i);
		}
	}
	return max;
}

void Hand::setHandType() {
	if (hand.size() == 5) {
		int pairs = ofAKind().size();
		if (isRoyalFlush())
			type = ROYALFLUSH;
		else if (isStraightFlush())
			type = STRAIGHTFLUSH;
		else if (pairs == 4)
			type = FOUROFAKIND;
		else if (isFullHouse())
			type = FULLHOUSE;
		else if (isFlush())
			type = FLUSH;
		else if (isStraight())
			type = STRAIGHT;
		else if (pairs == 3)
			type = THREEOFAKIND;
		else if (isTwoPair())
			type = TWOPAIR;
		else if (pairs == 2)
			type = TWOOFAKIND;
		else
			type = HIGHCARD;
	}
}

bool Hand::isRoyalFlush() {
	int topVal = (*hand.begin())->value;
	if (isStraightFlush() && topVal == VALUESIZE)
		return true;
	else
		return false;
}

bool Hand::isStraightFlush() {
	if (isStraight() && isFlush()) {
		return true;
	} else
		return false;
}

bool Hand::isFullHouse() {
	vector<int>* hist = histogram();
	bool three = false;
	bool two = false;
	for (int i = 0; i < 14; i++) {
		three = hist->at(i) == 3 ? true : three;
		two = hist->at(i) == 2 ? true : two;
		if (three && two)
			break;
	}
	if (three && two)
		return true;
	else
		return false;
}

bool Hand::isFlush() {
	set<Card*, CompareCardPtr>::iterator cur = hand.begin(); // first
	set<Card*, CompareCardPtr>::iterator next = ++hand.begin(); // second
	int count = 1;
	while (next != hand.end()) {
		if ((*cur)->suit == (*next)->suit) {
			count++;
			cur++;
			next++;
		} else
			break;
	}
	if (count == 5)
		return true;
	else
		return false;
}

bool Hand::isStraight() {
	set<Card*, CompareCardPtr>::iterator cur = hand.begin(); // first object
	set<Card*, CompareCardPtr>::iterator next = ++hand.begin(); // second
	int count = 1;
	while (next != hand.end()) {
		if ((*cur)->value - (*next)->value == 1) {
			count++;
			cur++;
			next++;
		} else
			break;
	}

	if (count == 5)
		return true;
	else
		return false;
}

bool Hand::isTwoPair() {
	vector<int>* hist = histogram();
	int count = 0;
	for (int i = 0; i < VALUESIZE; i++) {
		if (hist->at(i) == 2)
			count++;
		if (count == 2)
			break;
	}
	if (count == 2)
		return true;
	else
		return false;
}

set<Card*, CompareCardPtr> Hand::ofAKind() {
	// returns a set containing the two, three or four cards representing the
	// highest two of a kind, three of a kind or four of a kind, respectively

	set<Card*, CompareCardPtr> matches;
	// histogram of card values
	vector<int>* hist = histogram();
	// max gives type of hand, either two/three/four of a kind
	int max = maxOccurences(hist);
	// since index values (i) for hist correspond to (card values-1) we search
	// through the histogram in reverse, looking for the first item in the hist
	// array that is equal in value to max. This tells us the card value at
	// which max same value cards occurs.
	int matchCardVal = -1;
	for (int i = (VALUESIZE - 1); i >= 0; i--) {
		if (max == hist->at(i)) {
			matchCardVal = i;
			break;
		}
	}
	delete[] hist;
	// since we know the card value of the two, three or four of a kind
	// representing the best possible hand of that type, we search the hand for
	// cards that have that value and add then to the matches set
	if (matchCardVal >= 0) {
		for (set<Card*>::iterator itr = hand.begin(); itr != hand.end();) {
			if ((*itr)->value == matchCardVal)
				matches.insert(*itr);
			itr++;
		}
	}
	return matches;
}

set<Card*, CompareCardPtr> Hand::ofAKind(int value) {
	// returns a set containing the two, three or four cards representing the
	// highest two of a kind, three of a kind or four of a kind, respectively

	set<Card*, CompareCardPtr> matches;
	for (set<Card*>::iterator itr = hand.begin(); itr != hand.end();) {
		if ((*itr)->value == value)
			matches.insert(*itr);
	}

	return matches;
}

set<Card*, CompareCardPtr> Hand::getHand() {
	return hand;
}

int Hand::size() {
	return hand.size();
}

void Hand::print() {
	for (set<Card*>::iterator itr = hand.begin(); itr != hand.end();) {
		cout << (**itr) << endl;
		itr++;
	}
}


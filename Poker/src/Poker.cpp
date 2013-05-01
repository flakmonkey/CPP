// Poker.cpp

#include "Poker.h"

int main() {
	Player p1("Brett");
	Player p2("Danny");

	p1.hand.insert(new Card(0, 2));
	p1.hand.insert(new Card(0, 2));
	p1.hand.insert(new Card(1, 2));
	p1.hand.insert(new Card(0, 3));
	p1.hand.insert(new Card(0, 3));

	p2.hand.insert(new Card(0, 11));
	p2.hand.insert(new Card(0, 11));
	p2.hand.insert(new Card(0, 11));
	p2.hand.insert(new Card(0, 3));
	p2.hand.insert(new Card(0, 1));

	p1.print();
	p2.print();

	int res = p1.hand.compare(p2.hand);
	cout << "BRETT TYPE : " << p1.hand.type << endl;
	cout << "DANNY TYPE : " << p2.hand.type << endl;
	if (res == 0)
		cout << "EQUAL" << endl;
	else if(res < 0)
		cout << "DANNY WINS" << endl;
	else
		cout << "BRETT WINS" << endl;
	return 0;
}

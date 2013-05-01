// Player.cpp

#include "Player.h"

Player::Player(string name) {
	this->name = name;
}

void Player::print() {
	cout << "Name: " << name << endl;
	if(hand.size() > 0) {
		cout << "Cards in hand" << endl;
		hand.print();
	}
	else {
		cout << "No cards in hand" << endl;
	}
}

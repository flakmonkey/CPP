// Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include "Hand.h"
#include <iostream>
#include <vector>
using namespace std;

class Player {
public:
	string name;
	Hand hand;
	Player(string name);

	void print();
};


#endif /* PLAYER_H_ */

#pragma once

#include <vector>
#include "Domino.h"

using namespace std;

class Hand {
private:
	vector<Domino> hand;

public:
	Hand();
	Hand(vector<Domino> dominos);
	
	void printHand();
	
	int findDominoWithSide(int a);
	int findDominoDouble();

	void removeDomino(int index);

	inline void addDomino(Domino domino) {
		hand.push_back(domino);
	}

	inline int getSize() {
		return hand.size();
	}

	inline vector<Domino> getHand() {
		return hand;
	}





};


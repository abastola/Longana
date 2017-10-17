#pragma once

#include <vector>
#include "Domino.h"

using namespace std;

class Hand {
private:
	

public:
	Hand();
	Hand(vector<Domino> dominos);
	vector<Domino> hand;
	
	void printHand();
	
	int findDominoWithSide(int a);
	bool findEngine(int a);
	int findDominoDouble();
	int findDominoWithTwoSides(int a, int b);

	Domino getDomino(int index);
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


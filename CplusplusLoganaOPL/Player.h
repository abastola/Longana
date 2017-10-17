#pragma once
#include "Hand.h"

class Player {
	private:

	public:
		int  score;
		bool passed;
		bool drawn;
		Hand hand;
		Player();
		void updateScore(int a);
		virtual int  getInput(int requiredSide);
		int  validiateInput(int a, int b);
		int  calculateScore();
		bool isHandEmpty();
		void setHand(Hand h);
		void printHand();
		void deleteDominoFromHand(int index);
		int findIfMovePossible(int requiredSide);
		int getSumOfHands();
};
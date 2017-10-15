#pragma once
#include "Hand.h"

class Player {
	private:
		int  score;
		bool passed;
		Hand hand;

	public:
		Player();
		void updateScore(int a);
		int  getInput();
		int  validiateInput(int a, int b);
		int  calculateScore();
		bool isHandEmpty();
		void setHand(Hand h);
		void printHand();
		void deleteDominoFromHand(int index);
};
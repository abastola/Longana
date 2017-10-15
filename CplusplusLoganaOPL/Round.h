#pragma once
#include "Player.h"
#include "Stock.h"
#include "Domino.h"

class Round {
private:
	int  engine;
	int  countPassed;
	bool passed;
	bool turn;
	Player player1;
	Player player2;
	Stock stock;

public:
	Round(int a);
	
	void setHands();
	
	void printDetails();
	void playDomino();

	



};

#pragma once
#include "Player.h"
#include "Stock.h"
#include "Domino.h"
#include "Layout.h"

class Round {
private:
	
	int  engine;
	bool enginePresent;
	int  countPassed;
	bool passed;
	int turn;
	bool gameEnded;
	Player player1;
	Player player2;
	Stock stock;
	Layout layout;

public:
	Round(int a);
	
	void setHands();
	void printDetails();
	void placeFirstDomino();
	int findTurn();
	void playTurn(Player *player);
	int getCountPassed();
	bool isStockEmpty();
	int getPlayer1Sum();
	int getPlayer2Sum();


};

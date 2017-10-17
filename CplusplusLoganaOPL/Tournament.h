#pragma once
#include "stdafx.h"
#include "Round.h"

class Tournament {
private:
	int tournaMentScore;
	int player1Score;
	int player2Score;
	int roundNumber;
	int roundRemaining;
	bool loadFile();
	vector <Domino> computerHand;
	vector <Domino> playerHand;
	deque <Domino> layout;
	vector <Domino> boneyard;
	bool p = false;
	int t = 0;
	bool loadedFromFile = false;
	bool loadedRoundFirstTime = false;

public:
	Tournament();
	void playGame(); 



};

/*

int playingRound = 1;

if (loadFile()) {
Round round((7-roundNumber));
round.player1.hand.hand = playerHand;
round.player2.hand.hand = computerHand;
round.layout.boardDominos = layout;
round.stock.deck = boneyard;
round.passed = p;
round.turn = t;
round.printDetails();
}




*/
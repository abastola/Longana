#pragma once
#include "stdafx.h"
#include "Round.h"

class Tournament {
private:
	int tournaMentScore;
	int player1Score;
	int player2Score;
	int roundNumber;
	bool loadFile();

public:
	Tournament();
	void playGame();



};
/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  1/Tournament
     Date:  October 18, 2017
     ************************************************************
*/

//Detail explanation in cpp files for each header file

#pragma once
#include "stdafx.h"
#include "Round.h"

class Tournament {

public:
	//constructor
	Tournament();
	
	//start playing the game
	void playGame();
	
	//load the file
	bool loadFile();
	
	//print tournament details
	void printTournamentDetails();
	
private:
	//store tournament score
	int tournaMentScore;
	
	//store player 1 score
	int player1Score;
	
	//store player 2 score
	int player2Score;
	
	//store round number
	int roundNumber;
	
	//store round number reamaining
	int roundRemaining;
	
	//store domino of computer hand
	vector <Domino> computerHand;
	
	//store domino of player hand
	vector <Domino> playerHand;
	
	//store domino of layout
	deque <Domino> layout;
	
	//store domino of boneyard
	vector <Domino> boneyard;
	
	//temp store if passed
	bool p = false;
	
	// temp store tournament score
	int t = 0;
	
	//store if load from file
	bool loadedFromFile = false;
	
	//store if first round
	bool loadedRoundFirstTime = false;


};

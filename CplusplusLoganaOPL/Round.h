/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  2/Round
     Date:  October 18, 2017
     ************************************************************
*/

#pragma once
#include "Player.h"
#include "Stock.h"
#include "Domino.h"
#include "Layout.h"
#include "Human.h"
#include "Computer.h"


//All methods explaine in detail in cpp file

class Round {
public:
	//constructor
	Round(int a);
	
	//set hand for players
	void setHands();
	
	//print the round details
	void printDetails();
	
	//place the first domino or engine
	void placeFirstDomino();
	
	//find the next turn and play
	int findTurn();
	
	//play the turn
	void playTurn(Player *player);
	
	//get the number of non-stop pass
	int getCountPassed();
	
	//check if stock is empty
	bool isStockEmpty();
	
	//get player 1 sum of pip
	int getPlayer1Sum();
	
	//get player 2 sum of pip
	int getPlayer2Sum();
	
private:
	//set the egine pip
	int  engine;
	
	//store if engine is present
	bool enginePresent;
	
	//store number of passes
	int  countPassed;
	
	//store if passed
	bool passed;
	
	//store the turn
	int turn;
	
	//store if game ended
	bool gameEnded;
	
	//human object for player 1
	Human player1;
	
	//computer object for player 1
	Computer player2;
	
	//stock for the round
	Stock stock;
	
	//layout for the round
	Layout layout;


};

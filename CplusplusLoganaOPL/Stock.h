/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  7/Stock
     Date:  October 18, 2017
     ************************************************************
*/

#include <vector>
#include "Domino.h"


class Stock {


public:
	//Detail explanation in cpp files for each header file
	
	//Constructor 
	Stock();
	
	//Shuffle the deck
	void shuffleTheDeck();
	
	//Distribute the hands
	std::vector<Domino> DistributeAHand();
	
	//Draw a domino
	Domino getTopDominoFromDeck();
	
	//print the deck
	void printDeck();
	
	//Get the deck
	std::vector<Domino> getStock();
private:
	//Get deck
	std::vector<Domino> deck;


};

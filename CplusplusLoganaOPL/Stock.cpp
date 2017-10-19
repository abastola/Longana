/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  7/Stock
     Date:  October 18, 2017
     ************************************************************
*/

#include "stdafx.h"
#include "Stock.h"
#include <stdlib.h> 
#include <time.h>
#include <random>

/* ********************************************************************* 
Function Name: 
	Stock(Constructor)
Purpose: 
	To intialize stock class
	Set new stock
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Set all 28 Dominos
Assistance Received: 
	None 
********************************************************************* */

Stock::Stock() {
	for (int i = 0; i <= 6; i++) {
		for (int j = i; j <= 6; j++) {
			deck.push_back(Domino(i, j));
		}
	}
}

/* ********************************************************************* 
Function Name: 
	shuffleTheDeck
Purpose: 
	shuffle the deck
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	get random number
	shuffle the deck
Assistance Received: 
	None 
********************************************************************* */

void Stock::shuffleTheDeck() {
	
	//get the random number
	auto rng = std::default_random_engine{};
	
	//shuffle
	shuffle(deck.begin(), deck.end(), rng);
}

/* ********************************************************************* 
Function Name: 
	DistributeAHand
Purpose: 
	Get top 8 dominos to set hand for player
Parameters: 
	N/A
Return Value: 
	vector<Domino> temp: vector of first 8 dominos.
Local Variables: 
	vector<Domino> temp: vector to store dominos.
Algorithm: 
	get first 8 dominos.
	delete the dominos from deck
	return the vector of 8 dominos.
Assistance Received: 
	None 
********************************************************************* */

vector<Domino> Stock::DistributeAHand() {
	
	//get first 8 dominos
	vector<Domino> temp(deck.begin(), deck.begin()+8);
	
	//delete all 8 dominos
	for (int i = 0; i < 8; i++) {
		deck.erase(deck.begin());
	}
	
	//return
	return temp;
}

/* ********************************************************************* 
Function Name: 
	getTopDominoFromDeck
Purpose: 
	Get top domino 
Parameters: 
	N/A
Return Value: 
	<Domino> temp: top domino
Local Variables: 
	<Domino> temp: top domino
Algorithm: 
	get top domino
	delete the domino from deck
	return the domino
Assistance Received: 
	None 
********************************************************************* */

Domino Stock::getTopDominoFromDeck() {
	Domino temp = deck.front();
	deck.erase(deck.begin());
	return temp; 

}

/* ********************************************************************* 
Function Name: 
	printDeck()
Purpose: 
	print the deck
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm:
	Loop through deck
	Print each domino
Assistance Received: 
	None 
********************************************************************* */

void Stock::printDeck() {
	for (Domino temp : deck) {
		temp.printDomino();
	}
}

//getter for deck
vector<Domino> Stock::getStock() {
	return deck;
}

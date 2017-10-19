/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  2/Round
     Date:  October 18, 2017
     ************************************************************
*/

#include "stdafx.h"
#include "Round.h"

/* ********************************************************************* 
Function Name: 
	ROund(Constructor)
Purpose: 
	To intialize the round class. 
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Initialize paranmeters of round class.
Assistance Received: 
	None 
********************************************************************* */

Round::Round(int a) {
	countPassed = 0;
	passed = false;
	turn = 1;
	engine = a;
	enginePresent = false;
	gameEnded = false;
}

/* ********************************************************************* 
Function Name: 
	setHands
Purpose: 
	Gets 8 hands for each player
	Finds the player with engine and sets engine to true.
	Sets turn according to whoever has the engine.
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Get hand.
	FInd Player with the engine.
	Set Turn
Assistance Received: 
	None 
********************************************************************* */

void Round::setHands() {
	
	//shuffle the deck
	stock.shuffleTheDeck();
	
	//draw dominos for each player
	player2.setHand(Hand(stock.DistributeAHand()));
	player1.setHand(Hand(stock.DistributeAHand()));
	
	//check if player 1 has engine and set the tunr
	if (player1.hand.findEngine(engine)) {
		enginePresent = true;
		turn = 1;
	}
	
	//check if player 2 has engine set the tunr
	if (player2.hand.findEngine(engine)) {
		enginePresent = true;
		turn = 2;
	}
}

/* ********************************************************************* 
Function Name: 
	printDetails
Purpose:
	Print round details like player's hand, deck, board.
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Print the details	
Assistance Received: 
	None 
********************************************************************* */

void Round::printDetails() {
	
	//print player hands
	cout << "\nPlayer 1 Hand: ";
	player1.printHand();
	cout << "\nPlayer 2 Hand: ";
	player2.printHand();
	
	//print the round
	cout << "\nRound " << (7 - engine) << " Stock: ";
	
	//print the stock
	stock.printDeck();
	
	//print the boneyard
	layout.printBoard();
}

/* ********************************************************************* 
Function Name: 
	findTurn
Purpose:
	finds the turn and play the turn
	return the winner
Parameters: 
	N/A
Return Value: 
	return the winner
Local Variables: 
	N/A
Algorithm: 
	Play the turns
	Return the winner
Assistance Received: 
	None 
********************************************************************* */

int Round::findTurn() {
	
	//check if hands are empty and return the player number in case of empty
	if (player1.isHandEmpty()) {
		return 1;
	}
	if (player2.isHandEmpty()) {
		return 2;
	}
	
	//check for turn and play them
	if (turn == 1) {
		
		//display whose turn
		cout << "\nPlayer 1 turn." << endl;
		
		//play the turn
		playTurn(&player1);
		
		//change the turn
		turn = 2;
	}
	else {
		
		//display whose turn
		cout << "\nPlayer 2 turn." << endl;
		
		//play the turn
		playTurn(&player2);
		
		//chaneg the turn
		turn = 1;
	}
	
	//return -1 if roudn not complete
	return -1;
}

void Round::playTurn(Player *player) {

	//Try to put on original side
	Domino temp;
	int requiredSide;
	if (turn == 1) {
		temp = layout.getLeft();
		if (temp.Flipped()) {
			requiredSide = temp.getSideTwo();
		}
		else {
			requiredSide = temp.getSideOne();
		}
	}
	else {
		temp = layout.getRight();
		if (temp.Flipped()) {
			requiredSide = temp.getSideOne();
		}
		else {
			requiredSide = temp.getSideTwo();
		}
	}

	int playingDominoIndex = -1;
	bool requiredSideOne = true;

	while (true) {
		playingDominoIndex = player->getInput(requiredSide);
		if (playingDominoIndex < 0) {
			if (playingDominoIndex == -1) {
				if ((stock.getStock()).size() == 0) {
					countPassed++;
					cout << "\nPlayer" << turn << " passed because of empty boneyard." << endl;
					return;
				}
				else {
					player->hand.addDomino(stock.getTopDominoFromDeck());
				}
				printDetails();
				continue;
			}
			if (playingDominoIndex == -2) {
				passed = true;
				countPassed++;
				cout << "\nPlayer " << turn << " Passed." << endl;
				return;
			}
		}
		temp = player->hand.getDomino(playingDominoIndex);

		//check if returned domino is double

		if (temp.getSideOne() == temp.getSideTwo()) {
			if (turn == 1) {
				cout << "\nWhich side do you want to put the double? 1 for Left and 2 for right: ";
				int inputSide = 0;
				cin >> inputSide;
				if (inputSide == 1) {
					layout.insertLeft(temp);
				}
				else {
					layout.insertRight(temp);
				}
			}
			else {
				layout.insertRight(temp);
			}
			countPassed = 0;

			cout << "\nPlayer" << turn << " placed ";
			temp.printDomino();
			cout << endl;
			player->hand.removeDomino(playingDominoIndex);
			return;
		}

		if (temp.getSideOne() == requiredSide) {
			requiredSideOne = true;
			break;
		}
		if (temp.getSideTwo() == requiredSide) {
			requiredSideOne = false;
			break;
		}

		cout << "Invalid Domino Selection. Select one with matching PIP." << endl;
	}

	if (requiredSideOne) {
		if (turn == 1) {
			temp.setFlipped();
		}
	}
	else {
		if (turn == 2) {
			temp.setFlipped();
		}
	}

	if (turn == 1) {
		layout.insertLeft(temp);
	}
	else {
		layout.insertRight(temp);
	}
	countPassed = 0;
	cout << "\nPlayer" << turn << " placed ";
	temp.printDomino();
	cout << endl;
	player->hand.removeDomino(playingDominoIndex);

}

void Round::placeFirstDomino() {
	while (true) {
		if (!enginePresent) {
			cout << "\n\nEngine Not Found. Drawing one domino from stock." << endl;
			player1.hand.addDomino(stock.getTopDominoFromDeck());
			player2.hand.addDomino(stock.getTopDominoFromDeck());
			printDetails();

			if (player1.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 1;
			}
			if (player2.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 2;
			}
		}
		else {
			cout << "\n\nEngine Found. Starting the game." << endl;
			break;
		}
	}

	cout << "\nPlayer " << turn << " starts first." << endl;
	cout << "\nPlayer " << turn << " placed Engine: " << engine << "-" << engine << endl;

	if (turn == 1) {
		int temp = player1.hand.findDominoWithTwoSides(engine, engine);
		layout.insertLeft(player1.hand.getDomino(temp));
		player1.deleteDominoFromHand(temp);
		turn = 2;
	}
	else {
		int temp = player2.hand.findDominoWithTwoSides(engine, engine);
		layout.insertLeft(player2.hand.getDomino(temp));
		player2.deleteDominoFromHand(temp);
		turn = 1;
	}

	printDetails();

}

//getter for player1 score
int Round::getPlayer1Sum() {
	return player1.getSumOfHands();
}

//getter for player2 score
int Round::getPlayer2Sum() {
	return player2.getSumOfHands();
}

//getter for number of times passed
int Round::getCountPassed() {
	return countPassed;
}

//getter for if a stock is empty
bool Round::isStockEmpty() {
	return (stock.getStock()).empty();
}




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
	returns the winner or -1 if no winner yet
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

/* ********************************************************************* 
Function Name: 
	playTurn
Purpose:
	Play the players turn
Parameters: 
	Player *player : Pointer to the player object
Return Value: 
	N/A
Local Variables: 
	Domino temp: Temporary domino for testing purpose
	int requiredSide: PIP of player's side
	bool requiredSide: To store if right domino
	int playingDominoIndex: Index of domino choose
Algorithm: 
	Play the turns
	Get the input
	Validiate the input
	Check if can be placed
	If yes place the input
Assistance Received: 
	None 
********************************************************************* */
void Round::playTurn(Player *player) {

	//temp domino
	Domino temp;
	
	//get required side depending on the player
	int requiredSide;
	
	//if player 1
	if (turn == 1) {
		
		//get left
		temp = layout.getLeft();
		
		//if fliiped get side2 or else side1
		if (temp.Flipped()) {
			requiredSide = temp.getSideTwo();
		}
		else {
			requiredSide = temp.getSideOne();
		}
	}
	//if player 2
	else {
		//get right
		temp = layout.getRight();
		
		//if fliiped get side2 or else side1
		if (temp.Flipped()) {
			requiredSide = temp.getSideOne();
		}
		else {
			requiredSide = temp.getSideTwo();
		}
	}

	//index of playing domino
	int playingDominoIndex = -1;
	
	//bool to store if correct choice
	bool requiredSideOne = true;

	//loop until correct input
	while (true) {
		
		//get index of playing domino
		playingDominoIndex = player->getInput(requiredSide);
		
		//if less than 0, it is draw of pass
		if (playingDominoIndex < 0) {
			
			//if -1 pass
			if (playingDominoIndex == -1) {
				
				//check if empty stock and let user draw
				if ((stock.getStock()).size() == 0) {
					countPassed++;
					cout << "\nPlayer" << turn << " passed because of empty boneyard." << endl;
					return;
				}
				
				//let draw if not empty
				else {
					
					//add a domino instead
					player->hand.addDomino(stock.getTopDominoFromDeck());
				}
				
				//print the details
				printDetails();
				
				
				continue;
			}
			
			//if -2, means pass
			if (playingDominoIndex == -2) {
				
				//set pass to true
				passed = true;
				countPassed++;
				cout << "\nPlayer " << turn << " Passed." << endl;
				return;
			}
		}
		
		//get the playing domino
		temp = player->hand.getDomino(playingDominoIndex);

		//check if returned domino is double
		if (temp.getSideOne() == temp.getSideTwo()) {
			
			//if human ask where the domino should be places
			if (turn == 1) {
				
				//get the side
				cout << "\nWhich side do you want to put the double? 1 for Left and 2 for right: ";
				int inputSide = 0;
				cin >> inputSide;
				
				//insert on left or right
				if (inputSide == 1) {
					layout.insertLeft(temp);
				}
				else {
					layout.insertRight(temp);
				}
			}
			
			//if computer insert on right
			else {
				layout.insertRight(temp);
			}
			
			// set passed to zero since insert
			countPassed = 0;

			cout << "\nPlayer" << turn << " placed ";
			temp.printDomino();
			cout << endl;
			player->hand.removeDomino(playingDominoIndex);
			return;
		}
		
		//validiate the inputs
		if (temp.getSideOne() == requiredSide) {
			requiredSideOne = true;
			break;
		}
		if (temp.getSideTwo() == requiredSide) {
			requiredSideOne = false;
			break;
		}
		
		//if user selects invalid, let them know
		cout << "Invalid Domino Selection. Select one with matching PIP." << endl;
	}

	//flip the sides if required
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
	
	//insert to the layout
	if (turn == 1) {
		layout.insertLeft(temp);
	}
	else {
		layout.insertRight(temp);
	}
	
	//reset the passed
	countPassed = 0;
	
	//print the play
	cout << "\nPlayer" << turn << " placed ";
	temp.printDomino();
	cout << endl;
	
	//remove domino from the hand
	player->hand.removeDomino(playingDominoIndex);

}

/* ********************************************************************* 
Function Name: 
	placeFirstDomino
Purpose:
	Finds the engines and places it for the user
	If no engine found, deal one each domino
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	int temp: store index of the engine domino
	
Algorithm: 
	Find engine in hand
	If not found, draw tiles until found
	Play the engine in appropriate side
Assistance Received: 
	None 
********************************************************************* */

void Round::placeFirstDomino() {
	
	//loop this until engine found
	while (true) {
		
		//if engine is not print
		if (!enginePresent) {
			
			//print not present
			cout << "\n\nEngine Not Found. Drawing one domino from stock." << endl;
			
			//draw dominos
			player1.hand.addDomino(stock.getTopDominoFromDeck());
			player2.hand.addDomino(stock.getTopDominoFromDeck());
			
			//print after draw
			printDetails();

			//find if engine present now for each players and set engnePresent to true if found
			//also set the turn to player who has engine
			if (player1.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 1;
			}
			if (player2.hand.findEngine(engine)) {
				enginePresent = true;
				turn = 2;
			}
		}
		
		//if engine found, output so
		else {
			cout << "\n\nEngine Found. Starting the game." << endl;
			break;
		}
	}

	//display which player has engine and starts first
	cout << "\nPlayer " << turn << " starts first." << endl;
	
	//print the engine to be placed
	cout << "\nPlayer " << turn << " placed Engine: " << engine << "-" << engine << endl;

	//if player 1
	if (turn == 1) {
		//find the index of engine
		int temp = player1.hand.findDominoWithTwoSides(engine, engine);
		
		//insert the engine
		layout.insertLeft(player1.hand.getDomino(temp));
		
		//delete from hand
		player1.deleteDominoFromHand(temp);
		
		//change the turn
		turn = 2;
	}
	
	//if player 2
	else {
		//find the index of engine
		int temp = player2.hand.findDominoWithTwoSides(engine, engine);
		
		//insert the engine
		layout.insertLeft(player2.hand.getDomino(temp));
		
		//delete from hand
		player2.deleteDominoFromHand(temp);
		
		//change the turn
		turn = 1;
	}

	//print the detail
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




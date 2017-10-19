/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  3/Player
     Date:  October 18, 2017
     ************************************************************
*/

#include "Player.h"
#include "Hand.h"
#include "stdafx.h"

/* ********************************************************************* 
Function Name: 
	Player(Constructor)
Purpose: 
	To intialize player class
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Set passed to false and drawn to false;
Assistance Received: 
	None 
********************************************************************* */

Player::Player() {
	score = 0;
	passed = false;
	drawn = false;
}


/* ********************************************************************* 
Function Name: 
	getInput
Purpose: 
	To get index of domino to be played
Parameters: 
	int requiredSide: side of PIP which should match the playing domino
Return Value: 
	//Return -1 to draw
	//Return -2 to pass
	//Return else for domino input
Local Variables: 
	int moveCode: Store the type of move
	string userInput: store the domino
Algorithm: 
	Get the input
	Validate the input
	get the index or draw or pass
	
Assistance Received: 
	None 
********************************************************************* */
//Return -1 to draw
//Return -2 to pass
//Return else for domino input

int Player::getInput(int requiredSide) {
	//temp to store draw, pass or move
	int temp = -1;
	while (true) {
		
		//get userInput
		string userInput;
		cout << "Enter a Domino or Pass or Draw or Help or Exit: ";
		cin >> userInput;

		//if user enters exit, exit the game
		if (userInput.compare("Exit") == 0) {
			exit(1);
		}

		//if user enters pass or draw, check if valid 
		if ((userInput.compare("Pass") == 0) || (userInput.compare("Draw") == 0)) {

			//find if move possible
			int moveCOde = findIfMovePossible(requiredSide);

			//if no move possible
			if (moveCOde == -1) {

				//if not drawn yet
				if (!drawn) {
					cout << "\nDraw Possible. A card will be drawn for you." << endl;
					drawn = true;
					return -1;
				}

				//if drawn then pass
				else {
					passed = true;
					return -2;
				}
			}
			
			//if move possible
			else {
				cout << "\nInvalid Pass/Draw. Move Possible. " << endl;
				cout << "Hint: Play " << (moveCOde % 100) / 10 << "-" << (moveCOde % 100) % 10 << endl;
			}
			continue;
		}

		//if user asks for help
		if (userInput.compare("Help") == 0) {

			//get the move
			int moveCOde = findIfMovePossible(requiredSide);

			//if move possible
			if (moveCOde >= 100) {
				
				//print the move
				cout << "Hint: On Left Play " << (moveCOde % 100) / 10 << "-" << (moveCOde % 100) % 10 << endl;
			}
			else {
				//print no move possible
				cout << "\nNo moves possible. Hint: Pass or Draw " << endl;
			}
			continue;
		}

		//validate the input length
		if (userInput.length() != 3) {
			continue;
		}

		//get the domino that player wants to play
		temp = validiateInput(stoi(userInput.substr(0, 1)),stoi(userInput.substr(2, 1)));
		
		//check if draw 
		if (temp != -1) {
			drawn = false;
			break;
		}
		
		//if no valid input, display not valid
		cout << "Invalid Input/Selection." << endl;
	}

	//return the return value
	return temp;

}

/* ********************************************************************* 
Function Name: 
	validiateInput
Purpose: 
	to check if move is valid 
Parameters: 
	a: side one of domino
	b: side two of domino
Return Value: 
	if valid, return index of domino
	if no, return -1
Local Variables: 
	int count: to keep track of index
Algorithm: 
	Loop through the hand and get the index
	If no match, return -1
Assistance Received: 
	None 
********************************************************************* */

int Player::validiateInput(int a, int b) {
	
	//set the counter
	int count = 0;
	
	//loop through
	for (Domino i : hand.getHand()) {
		
		//check for match
		if ((i.getSideOne() == a) && (i.getSideTwo() == b)) {
			
			//return index
			return count;
		}
		
		//increase counter
		count++;
	}
	
	//return -1
	return -1;
}
/* ********************************************************************* 
Function Name: 
	findIfMovePossible
Purpose: 
	To see of a move is possible from player's hand
Parameters: 
	int requiredSide: the PIP that should match
Return Value: 
	// Return > 100 if non-double possible
	// Return > 200 if double possible
	// Return -1 if no move possible
Local Variables: 
	int count: to keep track of counter
	int returnCode: to keep track of return code
Algorithm: 
	Loop through the hand and find matching tile
Assistance Received: 
	None 
********************************************************************* */

int Player::findIfMovePossible(int requiredSide) {
	
	//set teh counter
	int count = 0;
	
	//set the return code
	int returnCode = -1;
	
	//loop through hand
	for (Domino i : hand.getHand()) {
		
		//check for non-double
		if (i.getSideOne() != i.getSideTwo()) {
			
			//if pip matches return 100 + 10 * side1 + 10 * side2
			if ((i.getSideOne() == requiredSide) || (i.getSideTwo() == requiredSide)) {

				return (100 + i.getSideOne() * 10 + i.getSideTwo());
			}
		}
		
		//if double
		else {
			//if pip matches set return code 200 + 10 * side1 + 10 * side2
			//don't return yet, it is always better to find a matching non-double
			returnCode = (200 + i.getSideOne() * 10 + i.getSideTwo());
		}
		
		//increase the counter
		count++;
	}
	
	//return the code
	return returnCode;
}

/* ********************************************************************* 
Function Name: 
	getSumeOfHands
Purpose: 
	To get sum of hands
Parameters: 
	N/A
Return Value: 
	Return sum
Local Variables: 
	int sum: temp variable to store sum
Algorithm: 
	Loop through the hand and get the sum
Assistance Received: 
	None 
********************************************************************* */
int Player::getSumOfHands() {
	
	//set sum to 0
	int sum=0;
	
	//loop through  hand and get the sum
	for (Domino i : hand.getHand()) {
		sum = sum+ i.getSum();
	}
	
	//return the sum
	return sum;

}

/* ********************************************************************* 
Function Name: 
	calculateScore
Purpose: 
	To get sum of hands
Parameters: 
	N/A
Return Value: 
	Return sum
Local Variables: 
	N/A
Algorithm: 
	N/A
Assistance Received: 
	None 
********************************************************************* */

int Player::calculateScore() {
	return getSumofHands();
}


//Utility function to update the score
// add new score a to previous score 
void Player::updateScore(int a) {
	score += a;
}

//Utility function to set the hand h
void Player::setHand(Hand h) {
	hand = h;
}

//Utility function to print the hand
void Player::printHand() {
	
	//loop through hand and print
	for (Domino i : hand.getHand()) {
		i.printDomino();
	}
}


//Utility function to delete a domino
//h: index of hand that needs to be deleted

void Player::deleteDominoFromHand(int index) {
	
	//remove the hand
	hand.removeDomino(index);
}

//Utility function check if empty hand
bool Player::isHandEmpty() {
	
	//return true if empty, false if not.
	return hand.getHand().empty();
}


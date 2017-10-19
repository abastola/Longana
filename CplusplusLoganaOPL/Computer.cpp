
/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  6/Computer
     Date:  October 18, 2017
     ************************************************************
*/

#include "Computer.h"
#include "stdafx.h"

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

int Computer::getInput(int requiredSide) {
	//temp to store draw, pass or move
	int temp = -1;
	
	//fidn the possible move
	int moveCOde = findIfMovePossible(requiredSide);

	//If No Move Possible
	if (moveCOde == -1) {

		//if not drawn yet
		if (!drawn) {
			cout << "\nPlayer 2 will draw a card from boneyard." << endl;
			system("pause");
			drawn = true;
			return -1;
		}

		//if drawn then passW
		else {
			passed = true;
			cout << "\nPlayer 2 will pass." << endl;
			system("pause");
			return -2;
		}
	}
	else {
		//set the userinput
		string userInput = to_string((moveCOde % 100) / 10) + "-" + to_string((moveCOde % 100) % 10);
		
		//get the domino that player wants to play and validate
		temp = validiateInput(stoi(userInput.substr(0, 1)),stoi(userInput.substr(2, 1)));
		
		//set draw to false
		drawn = false;
		
		//return temp
		return temp;
	}

}

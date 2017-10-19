#include "Hand.h"

/* ********************************************************************* 
Function Name: 
	Hand(Constructor)
Purpose: 
	To intialize hand
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Does nothing
Assistance Received: 
	None 
********************************************************************* */

Hand::Hand() {}

/* ********************************************************************* 
Function Name: 
	Hand(Constructor)
Purpose: 
	To intialize hand
Parameters: 
	vector<Dominos> dominos: Vector of dominos that become hand
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Set the hand to dominos.
Assistance Received: 
	None 
********************************************************************* */

Hand::Hand(vector<Domino> dominos) {
	hand = dominos;
}

/* ********************************************************************* 
Function Name: 
	printHand()
Purpose: 
	print the hand
Parameters: 
	N/A
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm:
	Loop through hand
	Print each domino
Assistance Received: 
	None 
********************************************************************* */
void Hand::printHand() {
	for (Domino i : hand) {
		i.printDomino();
	}
}


/* ********************************************************************* 
Function Name: 
	findDominoWithSide
Purpose: 
	find index of a domino containg PIP with value a
Parameters: 
	a - PIP to match
Return Value: 
	//Found                 -> Return Index
	//Found Only Double     -> Return -2;
	//Not found Double/Side -> Return -1;
Local Variables: 
	int count: to keep track of counter
	int returnCode: to keep track of return code
Algorithm:
	Loop through the hand and find matching tile
Assistance Received: 
	None 
********************************************************************* */

int Hand::findDominoWithSide(int a) {
	//set teh counter
	int count = 0;
	
	//set the return code
	int returnCode = -1;
	
	//loop through hand
	for (Domino i : hand) {
		
		//get the sides
		int temp = i.getSides();
		
		//check if double
		if (((temp / 10) == a) && ((temp % 10) == a)) {
			returnCode = -2;
		}
		
		//check if non double
		else if (((temp / 10) == a) || ((temp % 10) == a)) {
			returnCode = count;
			break;
		}
		
		//increase counter
		count++;
	}
	
	//return the returncode
	return returnCode;
}

/* ********************************************************************* 
Function Name: 
	findDominoWithTwoSides
Purpose: 
	find index of a domino containg PIP with value a and b
Parameters: 
	a - PIP to match
	b - PIP to match
Return Value: 
	//Found                 -> Return Index
	//Not found             -> Return -1;
Local Variables: 
	int count: to keep track of counter
Algorithm:
	Loop through the hand and find matching tile
Assistance Received: 
	None 
********************************************************************* */

int Hand::findDominoWithTwoSides(int a, int b) {
	//set the counter
	int count = 0;
	
	//loop through hand
	for (Domino i : hand) {
		
		//get the sides
		int temp = i.getSides();
		
		//check if matches
		if (((temp / 10) == a) && ((temp % 10) == b)) {
			return count;
		}
		
		//increase counter
		count++;
	}
	
	//return value
	return -1;
}

/* ********************************************************************* 
Function Name: 
	findEngine
Purpose: 
	find Engine  and return true/false
Parameters: 
	a - PIP of engine
Return Value: 
	//Found                 -> Return true
	//Not found             -> Return false
Local Variables: 
	N/A
Algorithm:
	Loop through the hand and find matching tile
Assistance Received: 
	None 
********************************************************************* */

bool Hand::findEngine(int a) {
	
	//loop through hand
	for (Domino i : hand) {
		
		//get teh sides
		int temp = i.getSides();
		
		//check if matches
		if (((temp / 10) == a) && ((temp % 10) == a)) {
			return true;
		}
	}
	return false;
}

/* ********************************************************************* 
Function Name: 
	findDominoDouble
Purpose: 
	find a double and retuen index
Parameters: 
	n/a
Return Value: 
	//Found                 -> Return index
	//Not found             -> Return -1
Local Variables: 
	int count: to keep track of counter
	int returnCode: to keep track of return code
Algorithm:
	Loop through the hand and find double
Assistance Received: 
	None 
********************************************************************* */

int Hand::findDominoDouble() {
	//set the counter
	int count = 0;
	
	//set the return code
	int returnCode = -1;
	
	//loop through hand
	for (Domino i : hand) {
		
		//get the sides
		int temp = i.getSides();
		
		//check if match
		if ((temp / 10)  == (temp % 10)) {
			return count;
		}
		count++;
	}
	return returnCode;
}

//utility function remove a domino
void Hand::removeDomino(int index) {
	hand.erase(hand.begin() + index);
}

//utility function to get a domino
Domino Hand::getDomino(int index) {
	return (hand[index]);
}


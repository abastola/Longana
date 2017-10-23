/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  3/Domino
     Date:  October 18, 2017
     ************************************************************
*/

#include "Domino.h"
#include "stdafx.h"

/* ********************************************************************* 
Function Name: 
	Domino(Constructor)
Purpose: 
	To intialize domino
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

Domino::Domino() {

}

/* ********************************************************************* 
Function Name: 
	Domino(Constructor)
Purpose: 
	To intialize domino
Parameters: 
	sideOne- PIP 1
	sideTwo- PIP 2
Return Value: 
	N/A
Local Variables: 
	N/A
Algorithm: 
	Does nothing
Assistance Received: 
	None 
********************************************************************* */


//Default Constructor
Domino::Domino(int sideone, int sidetwo) {

	//set sides
	sideOne = sideone;
	sideTwo = sidetwo;

	//set double
	if (sideOne == sideTwo) {
		isDouble = true;
	}
	else {
		isDouble = false;
	}

	//set flipped
	isFlipped = false;
}

//Utility to get ths sum of both side
//get sum of both sides
int Domino::getSum() {
	return (sideOne + sideTwo);
}

//seter for isflipped
void Domino::setFlipped() {
	isFlipped = true;
}

//getter for double
bool Domino::findIfDouble() {
	return isDouble;
}

//getter for sides
int Domino::getSides() {
	return (sideOne*10+sideTwo);
}

//getter for sideone
int Domino::getSideOne() {
	return (sideOne);
}

//getter for sidetwo
int Domino::getSideTwo() {
	return ( sideTwo);
}

//getter for isflipped
bool Domino:: Flipped() {
	return isFlipped;
}

//utility function to print the domino
void Domino::printDomino() {
	if (isFlipped) {
		cout << "|" << sideTwo << "-" << sideOne << "|";
	}
	else {
		cout << "|" << sideOne << "-" << sideTwo << "|";
	}
}





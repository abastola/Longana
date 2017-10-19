/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  7/Layout
     Date:  October 18, 2017
     ************************************************************
*/

#include "Layout.h"

/* ********************************************************************* 
Function Name: 
	Layout(Constructor)
Purpose: 
	To intialize layout
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

Layout::Layout() {

}


//getter for left side of the layout
Domino Layout::getLeft() {
	return boardDominos[0];
}

//getter for right side of the layout
Domino Layout::getRight() {
	return boardDominos[boardDominos.size()-1];
}

//insert to left
void Layout::insertLeft(Domino a) {
	boardDominos.push_front(a);
}

//insert to right
void Layout::insertRight(Domino a) {
	boardDominos.push_back(a);
}

//print the board
void Layout::printBoard() {
	cout << "\nBoard  Layout: ";
	cout << "L - ";
	for (Domino i : boardDominos) {
		i.printDomino();
	}
	cout << " - R" << endl;

	cout << "\n----------------------------------------------------------------\n" << endl;
}

#include "Domino.h"
#include "stdafx.h"

Domino::Domino() {

}

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

//get sum of both sides
int Domino::getSum() {
	return (sideOne + sideTwo);
}

//set flipped
void Domino::setFlipped() {
	isFlipped = true;
}

//check if double
bool Domino::findIfDouble() {
	return isDouble;
}

int Domino::getSides() {
	return (sideOne*10+sideTwo);
}

int Domino::getSideOne() {
	return (sideOne);
}

int Domino::getSideTwo() {
	return ( sideTwo);
}

bool Domino:: Flipped() {
	return isFlipped;
}

//print the domino
void Domino::printDomino() {
	if (isFlipped) {
		cout << "|" << sideTwo << "-" << sideOne << "|";
	}
	else {
		cout << "|" << sideOne << "-" << sideTwo << "|";
	}
}





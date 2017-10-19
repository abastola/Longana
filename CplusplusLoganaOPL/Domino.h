/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  3/Domino
     Date:  October 18, 2017
     ************************************************************
*/

#pragma once

class Domino
{

public:
	//Detail explanation in cpp files for each header file
	//constructor 1
	Domino(int sideone, int sidetwo);
	//constructor 1
	Domino();
	
	
	//get sum
	int  getSum();
	
	//print the domino
	void printDomino();

	//setters and getters
	void setFlipped();
	bool Flipped();
	bool findIfDouble();
	int getSides();
	int getSideOne();
	int getSideTwo();
private:
	//stores PIP 1 of domino
	int  sideOne;
	
	//stores PIP 2 of domino
	int  sideTwo;
	
	//stores if domino is flipped
	bool isFlipped;
	
	//stores if domino is double
	bool isDouble;

	
};

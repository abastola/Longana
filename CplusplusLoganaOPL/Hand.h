/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  4/Hand
     Date:  October 18, 2017
     ************************************************************
*/

#pragma once

#include <vector>
#include "Domino.h"


class Hand {
public:
	
	//Detail explanation in cpp files for each header file
	//Constrcutor 1
	Hand();
	
	//Constructor 2
	Hand(vector<Domino> dominos);
	
	//Print the hand
	void printHand();
	
	//Find the domino with pip a
	int findDominoWithSide(int a);
	
	//Find the engine with pip a
	bool findEngine(int a);
	
	//find a double domino
	int findDominoDouble();
	
	//Find the domino with pip a and pip b
	int findDominoWithTwoSides(int a, int b);
	
	//get a domino by index
	Domino getDomino(int index);
	
	//remove a domino
	void removeDomino(int index);

	//inline function to addDOmino
	inline void addDomino(Domino domino) {
		hand.push_back(domino);
	}

	//inline function to get Size of hand
	inline int getSize() {
		return hand.size();
	}

	//inline function to get hand;
	inline vector<Domino> getHand() {
		return hand;
	}
private:
	
	//store the hand
	vector<Domino> hand;

};


/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  4/Hand
     Date:  October 18, 2017
     ************************************************************
*/

#pragma once
#include "Hand.h"

//All details of methods are in cpp file

class Player {
	public:
		//Constructor for player
		Player();
		
		//update score
		void updateScore(int a);
		
		//get move for the player; Hidden in computer
		virtual int  getInput(int requiredSide);
	
		//validate the move
		int  validiateInput(int a, int b);
	
		//calculate the score
		int  calculateScore();
	
		//check if hand is empty
		bool isHandEmpty();
	
		//setter for hand
		void setHand(Hand h);
	
		//print the hand
		void printHand();
	
		//dete a domino at index
		void deleteDominoFromHand(int index);
	
		//find if possible move
		int findIfMovePossible(int requiredSide);
	
		//get sum of all hands
		int getSumOfHands();
	
	private:
		//hand object to store player's hand
		Hand hand;
	
		//player's score
		int  score;
	
		//check if player passed
		bool passed;
		
		//check if drawn
		bool drawn;
};

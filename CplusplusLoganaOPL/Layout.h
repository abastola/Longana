/*
     ************************************************************
     Name:  Arjun Bastola
     Project:  Longana C++
     Class:  7/Layout
     Date:  October 18, 2017
     ************************************************************
*/

#pragma once
#include "stdafx.h"
#include "Domino.h"
#include <deque>

class Layout {
	
	public:
		//Detail explanation in cpp files for each header file
	
		//Constructor 1
		Layout();
	
		//Get left domino
		Domino getLeft();
	
		//get right domino
		Domino getRight();
	
		//insert to left
		void insertLeft(Domino a);
	
		//insert to right
		void insertRight(Domino a);
		
		//print the board
		void printBoard();
	
	private:
		//store the layout dominos
		deque<Domino> boardDominos;
			
};

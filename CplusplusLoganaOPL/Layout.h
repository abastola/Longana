#pragma once
#include "stdafx.h"
#include "Domino.h"
#include <deque>

class Layout {
	private:
		

	public:
		Layout();
		deque<Domino> boardDominos;
		Domino getLeft();
		Domino getRight();
		void insertLeft(Domino a);
		void insertRight(Domino a);
		void printBoard();
			
};

#pragma once

class Domino
{
private:
	int  sideOne;
	int  sideTwo;
	bool isFlipped;
	bool isDouble;

public:
	Domino(int sideone, int sidetwo);
	Domino();

	int  getSum();
	void printDomino();

	void setFlipped();
	bool Flipped();
	bool findIfDouble();

	int getSides();
	int getSideOne();
	int getSideTwo();

	
};
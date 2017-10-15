#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(vector<Domino> dominos) {
	hand = dominos;
}

void Hand::printHand() {
	for (Domino i : hand) {
		i.printDomino();
	}
}

//Return Codes Explained

//Found                 -> Return Index
//Found Only Double     -> Return -2;
//Not found Double/Side -> Return -1;

int Hand::findDominoWithSide(int a) {
	int count = 0;
	int returnCode = -1;
	for (Domino i : hand) {
		int temp = i.getSides();
		if (((temp / 10) == a) && ((temp % 10) == a)) {
			returnCode = -2;
		}
		else if (((temp / 10) == a) || ((temp % 10) == a)) {
			returnCode = count;
			break;
		}
		count++;
	}
	return returnCode;
}

//Return Codes Explained

//Found      Double     -> Return Index;
//Not found Double/Side -> Return -1;

int Hand::findDominoDouble() {
	int count = 0;
	int returnCode = -1;
	for (Domino i : hand) {
		int temp = i.getSides();
		if ((temp / 10)  == (temp % 10)) {
			return count;
		}
		count++;
	}
	return returnCode;
}

void Hand::removeDomino(int index) {
	hand.erase(hand.begin() + index);
}


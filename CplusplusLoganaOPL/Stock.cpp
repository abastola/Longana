#include "stdafx.h"
#include "Stock.h"

Stock::Stock() {
	for (int i = 0; i <= 6; i++) {
		for (int j = i; j <= 6; j++) {
			deck.push_back(Domino(i, j));
		}
	}
}

void Stock::shuffleTheDeck() {
	random_shuffle(deck.begin(), deck.end());
}

vector<Domino> Stock::DistributeAHand() {
	vector<Domino> temp(deck.begin(), deck.begin()+8);
	for (int i = 0; i < 8; i++) {
		deck.erase(deck.begin());
	}
	return temp;
}

Domino Stock::getTopDominoFromDeck() {
	Domino temp = deck.front();
	deck.erase(deck.begin());
	return temp; 

}

void Stock::printDeck() {
	for (Domino temp : deck) {
		temp.printDomino();
	}
}

vector<Domino> Stock::getStock() {
	return deck;
}
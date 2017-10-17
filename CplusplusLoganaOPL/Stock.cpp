#include "stdafx.h"
#include "Stock.h"
#include <stdlib.h> 
#include <time.h>
#include <random>

Stock::Stock() {
	for (int i = 0; i <= 2; i++) {
		for (int j = i; j <= 2; j++) {
			deck.push_back(Domino(i, j));
		}
	}
}

void Stock::shuffleTheDeck() {
	auto rng = std::default_random_engine{};
	shuffle(deck.begin(), deck.end(), rng);
}

vector<Domino> Stock::DistributeAHand() {
	vector<Domino> temp(deck.begin(), deck.begin()+2);
	for (int i = 0; i < 2; i++) {
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
#include "stdafx.h"
#include "Round.h"

Round::Round(int a) {
	countPassed = 0;
	passed = false;
	turn = 1;
	engine = a;
}

void Round::setHands() {
	stock.shuffleTheDeck();
	player1.setHand(Hand(stock.DistributeAHand()));
	player2.setHand(Hand(stock.DistributeAHand()));
}

void Round::printDetails(){
	cout << "Player 1 Hand: \n";
	player1.printHand();
	cout << "\n\nPlayer 2 Hand: \n";
	player2.printHand();
	cout << "\n\nRound Stock: \n";
	stock.printDeck();
}

void Round::playDomino() {
	

}